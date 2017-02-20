/*
 * Filename   kmp.c
 * CreateTime 2017-02-15 15:26:28
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_next(const char *p, int next[])
{
    //test start
    int plen = strlen(p);
    next[0] = -1;
    int j = 0;
    int k = -1;

    while (j < plen - 1) {
        if (k = -1 || p[j] == p[k]) {
            ++j;
            ++k;

            if (p[j] != p[k]) {
                next[j] = k;

            } else {
                next[j] = next[k];

            }
        
        } else {
            k = next[k];

        }
    }
}


int kmp(const char *s, const char *p, int next[])
{
    //start test
    int slen = strlen(s);
    int plen = strlen(p);
    int i = 0, j = 0;

    while (i < slen && j < plen) {
        if (j == -1 || s[i] == p [j]) {
            i++;
            j++;

        } else {
            j = next[j];
        }
    }

    if (j == plen) {
        return i - j;
    } else {
        return -1;
    }

}


//unittest

int main()
{
    char *s = "abdabcefabcdss"; 
    char *p = "abcd";

    int next[4] = {0};

    get_next(p, next);

    int pos = kmp(s, p, next);

    printf("after kmp, the pos: %d\n", pos);

    return 0;
}
