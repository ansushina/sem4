#include "io.h"
#include<iostream>
#include<stdio.h>

using namespace std;
int input_all(double &t0, double &tw, int &m, double &pn, double &tn)
{
    cout << "Input t0: " << endl;
    if (scanf("%lf", &t0) != 1)
        return 1;
    cout << "Input tw: " << endl;
    if (scanf("%lf", &tw) != 1)
        return 1;
    cout << "Input m: " << endl;
    if (scanf("%d", &m) != 1)
        return 1;
    cout << "Input Pn: " << endl;
    if (scanf("%lf", &pn) != 1)
        return 1;
    cout << "Input Tn: " << endl;
    if (scanf("%lf", &tn) != 1)
        return 1;
    return 0;
}
