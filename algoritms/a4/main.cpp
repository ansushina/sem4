#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;

#define FROM -1
#define TO 1
#define STEP 0.1
double func(double x)
{
    return x*x*x;
}
void tabl()
{
    FILE *file = fopen("C:/c_prog/un1/my-rep/algoritms/a4/1.txt", "w");
    if (file)
    {
     //   printf("Входная таблица:\n\n");
        for(double i = FROM; i <= TO; i += STEP)
        {
            fprintf(file, "%10f %10f %d\n", i, func(i),1);
           // if ((-FROM + TO)/STEP < 40)
               // printf("%10f %10f %d\n", i, func(i),1);
        }
        fclose(file);
        printf("\n");
    }
    else
    {
        printf("Can't open file!\n");
    }
}

int main(int argc, char *argv[])
{
    //cout <<"dasdsa"<<endl;

    //tabl();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
