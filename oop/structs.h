#ifndef STRUCTS_H
#define STRUCTS_H

struct data
{
    const char *filename;
    struct
    {
        double alpha[3];
    } pov;
    struct
    {
        double k;
    } mast ;
    struct
    {
        double delta[3];
    } per;
};

struct point
{
    double x;
    double y;
    double z;
    int n;
};

struct figure
{
    struct point *mas;
    size_t n;

    int **matrix;
};

#endif // STRUCTS_H
