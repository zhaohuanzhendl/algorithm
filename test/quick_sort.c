/*
 * Filename   quick_sort.c
 * CreateTime 2017-03-27 05:23:32
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

/*
 * ref: http://blog.csdn.net/morewindows/article/details/6684558
 */
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int s, int l, int r)
{
    int i = l, j = r, x = s[l];

    while (i < j) {
        while (i < j && s[j] >= x) {
            j--;
        }

        if (i < j) {
            s[i++] = s[j];
        }

        while (i < j && s[i] <= x) {
            i--;
        }

        if (i < j) {
            s[j--] = s[i];
        }
    
    }
    s[i] = x;
    quick_sort(s, l, i-1);
    quick_sort(s, i+1, r);
}
