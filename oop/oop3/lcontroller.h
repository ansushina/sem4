#ifndef LCONTROLLER_H
#define LCONTROLLER_H

#include <QObject>

class lcontroller
{
    Q_OBJECT
public:
    explicit lcontroller(QObject *parent = 0);
    virtual ~lcontroller();
    enum ControllerState
    {
        IN_PROCESS,
        FREE
    };

    void set_new_target(int floor);
public slots:
private slots:

signals:

private:
};

#endif // LCONTROLLER_H
