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

#endif // STRUCTS_H
