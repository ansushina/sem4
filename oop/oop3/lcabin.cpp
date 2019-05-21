#include "lcabin.h"

lcabin::lcabin():
    state(STAY),
    current_floor(0),
    d(NONE)
{
    one_floor_Timer.setSingleShot(true);

    QObject::connect(&one_floor_Timer,SIGNAL(timeout()),this, SLOT(cabin_moving()));
    QObject::connect(&doors, SIGNAL(closed_doors()),this, SLOT(cabin_moving()));

    QObject::connect(this, SIGNAL(go()), &doors, SLOT(start_closing()));
    QObject::connect(this, SIGNAL(pass_target_floor(int)), this, SLOT(cabin_stopping()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors, SLOT(start_opening()));
}

void lcabin::set_target(int floor)
{
    state = BUZY;
    target_floor = floor;
    if (current_floor = target_floor)
    {
        emit pass_target_floor(current_floor);
    }
    else if (current_floor < target_floor)
    {
        d = UP;
        emit go();
    }
    else
    {
        d = DOWN;
        emit go();
    }
}
void lcabin::cabin_stopping()
{
    if (state == MOVING)
    {
        state = STAY;
        one_floor_Timer.stop();
        text->append("stopped at"+QString(current_floor));
        emit cabin_stopped(current_floor);
    }
}
void lcabin::cabin_moving()
{
    if (state == STAY)
        return;
    if (current_floor = target_floor)
    {
        emit pass_target_floor(current_floor);
    }
    if (state == BUZY)
    {
        state = MOVING;

    }
    else if (state == MOVING)
    {
        current_floor += d;
        emit passing_floor(current_floor,d);
        one_floor_Timer.start(ONE_FLOOR_TIME);
    }
}
