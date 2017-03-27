/*
 * Filename   insert_sort.c
 * CreateTime 2017-03-27 02:05:12
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

void insert_sort(int r[], int n)
{
    int i = 0, j = 0;

    for (i = 2; i < n; i++) {
        if (r[i] < r[i-1]) {
            r[0] = r[i];
            j = i - 1;

            while(r[0] < r[j]) {
                r[j+1] = r[j];
                j--;
            
            }
            r[j+1] = r[0];
        }
    
    }
}

int main()
{
    int a[] = {0, 43, 21, 89, 15, 43, 28};
    
    insert_sort(a, sizeof(a) / sizeof(int));
    
    for (int i = 1; i< sizeof(a) / sizeof(int); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

