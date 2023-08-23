#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QObject>
#include <QTimer>

class ScreenManager : public QObject
{
    Q_OBJECT
public:
    explicit ScreenManager(QObject *parent = nullptr);
    ~ScreenManager();
    static ScreenManager* instance();

    QWidget* forwardTo(QString newScrnName, QWidget* parent = NULL);

    QWidget* goDefault(QString defaultScrnName, QWidget* parent = NULL);

    QWidget* back();

    QWidget* curScrn();

signals:


private slots:
    void switchShowTimeout();
    void switchHideTimeout();
private:
    static ScreenManager* m_scrnManager;
    QList<QWidget*>m_scrns;
    bool m_inSwitch;
    QWidget* m_oldScreen;
    QTimer m_switchShowTimer;
    QTimer m_switchHideTimer;
};

#endif // SCREENMANAGER_H
