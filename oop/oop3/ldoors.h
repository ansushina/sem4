#ifndef LDOORS_H
#define LDOORS_H

#include <QObject>
#include <QTimer>
#include <QTextEdit>

class ldoors
{
    Q_OBJECT
public:
    explicit ldoors(QObject *parent = 0);
    virtual ~ldoors();
    enum DoorsState
    {
      CLOSE,
      OPEN,
      IN_CLOSE,
      IN_OPEN
    };
public slots:
    void start_closing();
    void start_opening();
private slots:
    void open();
    void close();
signals:
    void opened_doors();
    void closed_doors();

private:
    DoorsState state;
    QTimer openingTimer;
    QTimer closingTimer;
    QTimer stayopenTimer;
    QTimer waitTimer;

    QTextEdit *text;
};

#endif // LDOORS_H
