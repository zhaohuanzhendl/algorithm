/*
 * Filename   bubble_sort.c
 * CreateTime 2017-03-27 02:53:40
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int r[], int n)
{
    int i = 0, j = 0;

    unsigned int change = 1;
    for (i = 1; i < n && change; i++) {
        change = 0;
        
        //for (j = i + 1; j < n; j++) {
        for (j = 1; j < n - i; j++) {
            if (r[j] > r[j+1]) {
                r[0] = r[j+1];
                r[j+1] = r[j];
                r[j] = r[0];

                change = 1;
            }
        }
    }
}

int main()
{
    int a[] = {0, 43, 21, 89, 15,43, 28};
    bubble_sort(a, sizeof(a) / sizeof(int));

    for (int i = 1; i < sizeof(a) / sizeof(int); i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
