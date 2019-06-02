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

};
#endif // F_H
