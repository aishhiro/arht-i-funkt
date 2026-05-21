#include <stdio.h>
#include <math.h>

#define EPSILON 1e-9

void print_arr(double* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%.6f ", arr[i]);
    }
    printf("\n");
}

int contains(double* arr, int size, double val) 
{
    for (int i = 0; i < size; i++) 
    {
        if (fabs(arr[i] - val) < EPSILON) 
        {
            return 1; 
        }
    }
    return 0;
}

void filter_arr(double* orig, double* copy, int orig_size, int* new_size) 
{
    *new_size = 0;

    for (int i = 0; i < orig_size; i++) 
    {
        if (!contains(copy, *new_size, orig[i])) 
        {
            copy[*new_size] = orig[i];
            (*new_size)++;
        }
    }
}

int main() {
    double ardouble[] = 
    {
        23.43, 34.43, 342.43432, 432432.42423,
        424.423, 234.43, 23.43, 34.43, 342.43432,
        432432.42423, 424.423, 234.43, 424.423
    };

    int size_arr = sizeof(ardouble) / sizeof(double);
    double copy_arr[size_arr];
    int new_size;

    printf("start: ");
    print_arr(ardouble, size_arr);
    filter_arr(ardouble, copy_arr, size_arr, &new_size);
    printf("copy: ");
    print_arr(copy_arr, new_size);

    return 0;
}
