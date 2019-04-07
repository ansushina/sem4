#include"matrix.h"
#include"figure.h"
void free_matrix(matrix_t mat, size_t n)
{
    if (!mat)
        return;
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

matrix_t allocate_matrix(size_t n)
{
    if (!n)
        return nullptr;
    int **new_matrix =(int **)calloc(n, sizeof(int *));
    if (!new_matrix)
        return nullptr;
    for (size_t i = 0; i < n; i++)
    {
        new_matrix[i] = (int *)calloc(n, sizeof(int));
        if (!new_matrix[i])
        {
            free_matrix(new_matrix, i);
            return nullptr;
        }
    }
    return new_matrix;
}


