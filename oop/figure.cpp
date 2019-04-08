#include "figure.h"

size_t &get_fig_n(struct figure &fig)
{
    return fig.n;
}
int is_empty(struct figure &fig)
{
    return !(fig.mas && fig.matrix && get_fig_n(fig));
}

void free_fig(struct figure &fig)
{
    if (fig.mas)
       // free(fig.mas);
        delete [] fig.mas;
    if (fig.matrix)
        free_matrix(fig.matrix, fig.n);

    fig.n = 0;
    fig.matrix = NULL;
    fig.mas = NULL;
}
figure_t init_fig()
{
    figure_t fig;
    fig.n = 0;
    fig.matrix = NULL;
    fig.mas = NULL;
    return fig;
}
int get_matrix_el(figure_t fig, size_t i, size_t j)
{
    return fig.matrix[i][j];
}

void set_fig_matrix(figure_t &fig, matrix_t mt)
{
    fig.matrix = mt;
}
void set_fig_mas(figure_t &fig, point_t *mas)
{
    fig.mas = mas;
}
void set_fig_n(figure_t &fig, size_t n)
{
    fig.n = n;
}
