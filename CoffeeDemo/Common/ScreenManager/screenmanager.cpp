#include "screenmanager.h"
#include "registerscreen.h"
#include <Windows.h>
#include "log.h"

ScreenManager* ScreenManager::m_scrnManager = NULL;

ScreenManager::ScreenManager(QObject *parent) :
QObject(parent), m_inSwitch(false), m_oldScreen(NULL)
{
    m_scrns.clear();
    connect(&m_switchShowTimer, SIGNAL(timeout()), this, SLOT(switchShowTimeout()));
    m_switchShowTimer.setSingleShot(true);
    m_switchShowTimer.setInterval(50);

    connect(&m_switchHideTimer, SIGNAL(timeout()), this, SLOT(switchHideTimeout()));
    m_switchHideTimer.setSingleShot(true);
    m_switchHideTimer.setInterval(50);
}

ScreenManager::~ScreenManager()
{
    qDeleteAll(m_scrns);
    m_scrns.clear();
}

ScreenManager *ScreenManager::instance()
{
    if (!m_scrnManager)
    {
        m_scrnManager = new ScreenManager();
    }
    return m_scrnManager;
}

QWidget *ScreenManager::forwardTo(QString newScrnName, QWidget *parent)
{
    if (m_inSwitch)
    {
        CLog::instance()->logMsg(log_err, tr("in switching screen"));
        if (m_switchShowTimer.isActive())
        {
            m_switchShowTimer.stop();
            switchShowTimeout();
        }
        if (m_switchHideTimer.isActive())
        {
            m_switchHideTimer.stop();
            switchHideTimeout();
        }
    }
    CLog::instance()->logMsg(log_debug, tr("forward to %1").arg(newScrnName));
    //!注册画面
    QWidget* screen = ScreenCreatorFactory::createScreen(newScrnName, parent);
    if (!screen)
    {
        CLog::instance()->logMsg(log_err, tr("fail to create %1").arg(newScrnName));
        return NULL;
    }
    if (!m_scrns.isEmpty())
    {
        m_oldScreen = m_scrns.last();
        m_switchShowTimer.start();
        m_inSwitch = true;
    }else
    {
        screen->show();
        screen->setFocus();
    }
    m_scrns.append(screen);
    return screen;
}

QWidget *ScreenManager::goDefault(QString defaultScrnName, QWidget *parent)
{
    if (m_inSwitch)
    {
        CLog::instance()->logMsg(log_err, tr("in switching screen"));
        if (m_switchShowTimer.isActive())
        {
            m_switchShowTimer.stop();
            switchShowTimeout();
        }
        if (m_switchHideTimer.isActive())
        {
            m_switchHideTimer.stop();
            switchHideTimeout();
        }
    }
    CLog::instance()->logMsg(log_debug, tr("godefault %1").arg(defaultScrnName));
    QWidget* screen = ScreenCreatorFactory::createScreen(defaultScrnName, parent);
    if (!screen)
    {
        CLog::instance()->logMsg(log_err, tr("fail to create %1").arg(defaultScrnName));
        return NULL;
    }
    if (!m_scrns.isEmpty())
    {
        m_oldScreen = m_scrns.takeLast();
        qDeleteAll(m_scrns);
        m_scrns.clear();
    }
    m_switchShowTimer.start();
    m_inSwitch = true;
    m_scrns.append(screen);
    return screen;
}

QWidget *ScreenManager::back()
{
    if (m_inSwitch)
    {
        CLog::instance()->logMsg(log_err, tr("in switching screen"));
        if (m_switchShowTimer.isActive())
        {
            m_switchShowTimer.stop();
            switchShowTimeout();
        }
        if (m_switchHideTimer.isActive())
        {
            m_switchHideTimer.stop();
            switchHideTimeout();
        }
    }
    if (m_scrns.isEmpty())
    {
        CLog::instance()->logMsg(log_err, tr("fail to back to screen"));
        return NULL;
    }
    m_oldScreen = m_scrns.takeLast();
    if (!m_scrns.isEmpty())
    {
        m_switchShowTimer.start();
        m_inSwitch = true;
    }else
    {
        m_scrns.append(m_oldScreen);
    }
    return m_scrns.last();
}

QWidget *ScreenManager::curScrn()
{
    if (m_scrns.isEmpty())
    {
        return NULL;
    }
    return m_scrns.last();
}

void ScreenManager::switchShowTimeout()
{
    m_scrns.last()->show();
    m_scrns.last()->setFocus();
    m_switchHideTimer.start();
}

void ScreenManager::switchHideTimeout()
{
    if (m_oldScreen)
    {
        if (-1 == m_scrns.indexOf(m_oldScreen))
        {
            delete m_oldScreen;
        }
        else
        {
            m_oldScreen->hide();
        }
    }
}
