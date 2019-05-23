#include "ldoors.h"



ldoors::ldoors(QObject *parent):
    state(CLOSE)
{
    openingTimer.setSingleShot(true);
    closingTimer.setSingleShot(true);
    stayopenTimer.setSingleShot(true);

    QObject::connect(&openingTimer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&closingTimer, SIGNAL(timeout()), this, SLOT(close()));
    QObject::connect(&stayopenTimer, SIGNAL(timeout()), this, SLOT(start_closing()));
}

void ldoors::set_text_edit(QTextEdit *t)
{
    text = t;
    text->append("Двери подключены.");
}
void ldoors::start_closing()
{
    if (state == OPEN)
    {
        state = IN_CLOSE;
        text->append("Двери закрываются.");
        closingTimer.start(DOORS_TIME);
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
        text->append("Двери открываются.");
        openingTimer.start(DOORS_TIME);
    }
    else if (state == IN_CLOSE)
    {
        state = IN_OPEN;
        text->append("Двери открываются.");
        int t = closingTimer.remainingTime();
        closingTimer.stop();
        openingTimer.start(DOORS_TIME - t);
    }
}
void ldoors::open()
{
    if (state == IN_OPEN)
    {
        state = OPEN;
        text->append("Двери открыты.");
        stayopenTimer.start(DOORS_IN_OPEN_TIME);
    }
}
void ldoors::close()
{
    if (state == IN_CLOSE)
    {
        state = CLOSE;
        text->append("Двери зыкрыты.");
        emit closed_doors();
    }
}
