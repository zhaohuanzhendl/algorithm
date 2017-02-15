/*
 * Filename   implement_strstr1.c
 * CreateTime 2017-02-15 10:13:48
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_match(const char *s, const char *p)
{
    int slen = strlen(s);    
    int plen = strlen(p);    

    int i = 0;
    int j = 0;

    while (i < slen && j < plen) {
        if (s[i] == p[j] ) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j = plen) {
        return i - j;

    } else {
        return -1; 

    }
}

//unittest
int main()
{
    char s[] = "fuckcodeyeah!";
    char p[] = "code";

    int pos = str_match(s, p);

    printf("pos : %d\n", pos);

    return 0;
}
