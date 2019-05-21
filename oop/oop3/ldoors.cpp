#include "ldoors.h"



ldoors::ldoors(QObject *parent = 0):
    state(CLOSE)
{
    openingTimer.setSingleShot(true);
    closingTimer.setSingleShot(true);
    stayopenTimer.setSingleShot(true);
    waitTimer.setSingleShot(true);

    QObject::connect(this, SIGNAL(opened_doors()), this, SLOT(open()));
    QObject::connect(&openingTimer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&closingTimer, SIGNAL(timeout()), this, SLOT(close()));
    QObject::connect(&stayopenTimer, SIGNAL(timeout()), this, SLOT(start_closing()));
    //QObject::connect(&waitTimer, SIGNAL(timeout()), this, SLOT(open()));
}

void ldoors::start_closing()
{
    if (state == OPEN)
    {
        state = IN_CLOSE;
        text->append("Doors are closing");
        closingTimer.start(DOORS_TIME);
    }
    else if (state == IN_OPEN)
    {
        state = IN_CLOSE;
        text->append("Doors are closing");
        int t = openingTimer.remainingTime();
        openingTimer.stop();
        openingTimer.start(DOORS_TIME - t);
    }
    else if (state == CLOSE)
    {
       emit closed_doors();
    }
}
void ldoors::start_opening()
{
    if (state == CLOSE)
    {
        state = IN_OPEN;
        text->append("Doors are opening");
        openingTimer.start(DOORS_TIME);
    }
    else if (state == IN_CLOSE)
    {
        state = IN_OPEN;
        text->append("Doors are opening");
        int t = closingTimer.remainingTime();
        closingTimer.stop();
        openingTimer.start(DOORS_TIME - t);
    }
    else if (state == OPEN)
    {
        emit opened_doors();
    }
}
void ldoors::open()
{
    if (state == IN_OPEN)
    {
        state = OPEN;
        text->append("Doors are opened");
        emit opened_doors();
    }
}
void ldoors::close()
{
    if (state == IN_CLOSE)
    {
        state = CLOSE;
        text->append("Doors are closed");
        emit closed_doors();
    }
}
