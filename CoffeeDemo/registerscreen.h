#ifndef REGISTERSCREEN_H
#define REGISTERSCREEN_H
#include <QString>
#include <QMap>
#include <QWidget>

//定义画面生成函数
typedef QWidget* (*CREATESCREEN)(QWidget* parent);
//画面创建工厂
class ScreenCreatorFactory
{
public:
    static QWidget* createScreen(const QString &name, QWidget* parent = NULL)
    {
        //创建画面
        QMap<QString, CREATESCREEN>screen = screens();
        //需要创建的画面是否注册过，未注册过返回空
        if (screen.find(name) != screen.end())
        {
            return screen[name](parent);
        }else
        {
            return NULL;
        }
    }
    //注册画面
    static void registerScreen(const QString &name, CREATESCREEN screenCreator)
    {
        screens()[name] = screenCreator;
    }
private:
    static QMap<QString, CREATESCREEN>&screens(QWidget *parent = NULL)
    {
        //保存注册的画面
        static QMap<QString, CREATESCREEN>screen = QMap<QString, CREATESCREEN>();
        return screen;
    }
};

class Register
{
public:
    Register(const QString &name, CREATESCREEN creator)
    {
        //通过画面创建工厂注册画面
        ScreenCreatorFactory::registerScreen(name, creator);
    }
};
//定义宏，注册画面，注册时包含画面类名
#define REGISTER_SCREEN_CLASS(className)\
    class className##Register\
    {\
    public:\
        static QWidget* NewInstance(QWidget* parent = NULL)\
        {\
        return new className(parent);\
        }\
    };\
    static Register className##reg(#className, className##Register::NewInstance)

#endif // REGISTERSCREEN_H
