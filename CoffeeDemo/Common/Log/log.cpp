#include "log.h"
#include <cstdio>
#include <cstdarg>
#include <QDateTime>
#include <QDebug>

CLog* CLog::m_log = NULL;

CLog::CLog(const QString &name, bool bAppend)
{
    QString fileName = name;
    if (name.isEmpty())
    {
        fileName = QDateTime::currentDateTime().toString("yyyy_MM_dd") + ".log";
    }
    m_levelOn[log_debug] = false;
    m_levelOn[log_info] = false;
    m_levelOn[log_warn] = false;
    m_levelOn[log_err] = false;
    openLogName(fileName, bAppend);
}

CLog::~CLog()
{
    closeLogFile();
}

//打开日志文件名
bool CLog::openLogName(const QString &name, bool bAppend)
{
    bool bOpenOK = false;
    closeLogFile();
    mFile.setFileName(name);
    //如果打开文件名
    if (m_levelOn[log_debug] || m_levelOn[log_info] || m_levelOn[log_warn] || m_levelOn[log_err])
    {
        if (mFile.open(bAppend ? QFile::Append:(QFile::WriteOnly|QFile::Truncate)))
        {
            bOpenOK = true;
        }

    }
    return bOpenOK;
}

void CLog::closeLogFile()
{
    if (mFile.isOpen())
    {
        mFile.close();
    }
}
//以文本的方式打印日志
void CLog::logMsg(LOG_LEVEL_E level, const QString &str)
{
    if (false == m_levelOn[level])
    {
        return;
    }
    //文件未打开
    if (!mFile.isOpen())
    {
        //打开文件
        mFile.open(QFile::WriteOnly|QFile::Truncate);
    }
    //文件打开
    if (mFile.isOpen())
    {
        QTextStream out(&mFile);
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << "==>" << str <<endl;
    }
    qDebug(str.toStdString().data());

}
//以十六进制格式输出指定长度的内容
void CLog::logData(LOG_LEVEL_E level, const char *data, size_t len)
{
    if (data)
    {
        QString strData;
        for (size_t i = 0; i < len; i++)
        {
            char tmpChar[4] ={0};
            _snprintf_s(tmpChar, sizeof(tmpChar), "%02x", (unsigned char)data[i]);
            strData += tmpChar;
        }
        logMsg(level, strData);
    }
}

bool CLog::isLogOn(LOG_LEVEL_E level)
{
    return m_levelOn[level];
}

void CLog::setLogOn(LOG_LEVEL_E level, bool on)
{
    m_levelOn[level] = on;
}

CLog *CLog::instance()
{
    if (!m_log)
    {
        m_log = new CLog();
    }
    return m_log;
}
