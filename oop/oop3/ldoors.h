#ifndef LDOORS_H
#define LDOORS_H

#include <QObject>

class ldoors
{
    Q_OBJECT
public:
    explicit ldoors(QObject *parent = 0);
    virtual ~ldoors():
    enum DoorsState
    {
      CLOSE,
      OPEN,
      MOVING
    };
private slots:

signals:

private:
};

#endif // LDOORS_H
