#ifndef IO_H
#define IO_H

#include <stdlib.h>
#include <stdio.h>

#include "points.h"
#include "rc.h"

typedef FILE * stream_t;

rc_type open_file_read(stream_t &stream, const char *filename);
void close_file(stream_t stream);

void free_fig(struct figure &fig);
int read_from_file(struct figure &fig, stream_t f);

#endif // IO_H
