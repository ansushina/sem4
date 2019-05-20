#ifndef LCONTROLLER_H
#define LCONTROLLER_H

#include <QObject>

class lcontroller
{
    Q_OBJECT
public:
    explicit lcontroller(QObject *parent = 0);
    virtual ~lcontroller();
    enum DoorsState
    {
        IN_PROCESS,
        FREE
    };

private slots:

signals:

private:
};

#endif // LCONTROLLER_H
