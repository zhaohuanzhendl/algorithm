/*
 * Filename   ./xx.c
 * CreateTime 2017-04-14 14:37:35
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>


void quick_sort(int s[], int l, int r)
{
    if (l < r) {
        int i = l, j = r, x = s[l];

        while (i < j) {
            
            while (i < j && s[j] >= x) {
                j--;
            }

            if (i < j) {
                s[i++] = s[j];
            }

            while (i < j && s[i] < x) {
                i++;
            }

            if (i < j) {
                s[j--] = s[i];
            }
        
        }//end while

        s[i] = x;

        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);

    }//end if

}

int main()
{
    int r[] = {0, 3, 9, 1,7,4,8};
    int n = sizeof(r) / sizeof(int);
    printf("n-value: %d\n", n);

    quick_sort(r, 0, n - 1);

    for (int i= 1; i < n; i++ ) {
        printf("%d ", r[i]);
    
    }
    printf("\n");

    return 0;

}
