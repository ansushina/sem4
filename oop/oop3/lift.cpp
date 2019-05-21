#include "lift.h"

Lift::lift()
{
    QObject::connect(&cabin, SIGNAL(cabin_stopped(int)), &control, SLOT());

}
