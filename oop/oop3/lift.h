#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include"lcabin.h"
#include"ldoors.h"
#include"lcontroller.h"

class lift
{
    Q_OBJECT
public:
    lift();
private:
    ldoors doors;
    lcabin cabin;
    lcontroller control;
};

#endif // LIFT_H
