#ifndef LOG_H
#define LOG_H
#include <QString>
#include <QFile>
#include <QTextStream>
//默认的日志文件
typedef enum _eLogLevel
{
    log_debug = 0,
    log_info,
    log_warn,
    log_err
}LOG_LEVEL_E;
class CLog
{
public:
    //默认已清空文件的方式打开或者创建日志文件
    CLog(const QString &name = "", bool bAppend = true);
    virtual ~CLog();

public:
    bool openLogName(const QString &name, bool bAppend = true);

    void closeLogFile(void);

    void setLogLevel(LOG_LEVEL_E level) { mLevel = level;}

    void logMsg(LOG_LEVEL_E level, const QString &str);

    void logData(LOG_LEVEL_E level,const char *data, size_t len);

    bool isLogOn(LOG_LEVEL_E level);

    void setLogOn(LOG_LEVEL_E level, bool on);

    static CLog* instance();
private:
    static CLog* m_log;
    bool m_levelOn[4];
    QFile mFile;
    LOG_LEVEL_E mLevel;
};

#endif // LOG_H
