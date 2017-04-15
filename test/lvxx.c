/*
 * Filename   lvxx.c
 * CreateTime 2017-04-14 23:11:25
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

void reverse(char s[], int from, int to)
{
    while (from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
        
    }
}



int main ()
{
    char s[] = "I am NICE man!";
    int len = sizeof(s) / sizeof(char);
    reverse(s, 0, len - 2);
    printf ("%s\n",s);

    int lct = 0;
    for (int i = 0; i < len -2; i++) {
        if (s[i] == ' ') {
            reverse(s, lct, i - 1);
            lct = i + 1;

        }
    }

    printf ("%s\n",s);

    return 0;
}
