#include "alg.h"


bool CheckSigns( QVector<int> signs, int &obhod)
{
    int count_plus = 0;
    int count_minus = 0;
    for (int i = 0; i < signs.size(); i++)
    {
        if (signs[i] > 0)
        {
            count_plus++;
        }
        if (signs[i] < 0)
        {
            count_minus++;
        }
    }
    if ((count_minus == 0 && count_plus == 0) || (count_minus&&count_plus))
        return false;
    if (count_minus == 0)
        obhod = 1;
    else
        obhod = -1;
    return true;

}

int sign(int n)
{
    if (n > 0)
        return 1;
    else if (n == 0)
        return 0;
    return -1;
}

int VectorMult(line_t l1, line_t l2)
{
    int Vx1 = l1.x2-l1.x1;
    int Vy1 = l1.y2-l1.y1;
    int Vx2 = l2.x2-l2.x1;
    int Vy2 = l2.y2-l2.y1;
    return Vx1*Vy2-Vx2*Vy1;
}

double scalMult(point p1, point p2)
{
    return p1.x()*p2.x() + p2.y()*p1.y();
}
bool is_convex(std::vector<line_t> egles, int &obhod)
{
    if (egles.size() < 2)
        return false;
    QVector<int> signs;
    for (size_t i =0; i < egles.size() - 1; i++)
    {
        int Mult = VectorMult(egles[i],egles[i+1]);
        int msign = sign(Mult);
        signs.append(msign);
    }
    int Mult = VectorMult(egles[egles.size() - 1],egles[0]);
    int msign = sign(Mult);
    signs.append(msign);
    return CheckSigns(signs, obhod);
}
