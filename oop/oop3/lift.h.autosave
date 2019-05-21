#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include"lcabin.h"
#include"ldoors.h"
#include"lcontroller.h"

class Lift: public QObject
{
    Q_OBJECT
public:
    Lift();
    void set_floor(int i);
private:
    ldoors doors;
    lcabin cabin;
    lcontroller control;
};

#endif // LIFT_H
