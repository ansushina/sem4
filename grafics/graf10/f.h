#ifndef F_H
#define F_H
#include "math.h"
typedef double (*myfunc) (double, double);

class Function
{
public:
    Function()
    {
        arr[0] = &f1;
        arr[1] = &f2;
        arr[2] = &f3;
        arr[3] = &f4;
    }

    myfunc get_f(int i)
    {
        return arr[i];
    }
private:
    myfunc arr[5];
    static double f1(double x, double y)
    {
        return cos(x)*cos(x) - sin(y)*sin(y);
    }
    static double f2(double x, double y)
    {
        return cos(x)*sin(y);
    }
    static double f3(double x, double y)
    {
        return exp(cos(x));
    }
    static double f4(double x, double y)
    {
        return cos(x)*cos(x)*y*y;
    }

};
#endif // F_H
