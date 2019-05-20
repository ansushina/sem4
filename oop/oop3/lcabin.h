#ifndef LCABIN_H
#define LCABIN_H


class lcabin
{
    Q_OBJECT
public:
    explicit lcabin(QObject *parent = 0);
    virtual ~lcabin();
    enum CabinState
    {
      FULL,
      MOVING,
      FREE
    };
private slots:

signals:

private:
};

#endif // LCABIN_H
