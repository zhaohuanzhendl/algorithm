/*
 * Filename     : linerevers.c
 * Author       : zhz
 * Create Time  : 2016-12-15 14:04:54
 * Last Modified: 2017-04-14 23:15:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
revers_str(char *s, int from, int to)
{
    while (from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}


int main()
{
    char buf[] = "I am a NB student.";
    printf("sizeof(buf): %ld\n", sizeof(buf));
    revers_str(buf, 0, sizeof(buf)-2);
    printf("first revers: %s\n", buf);
   
    unsigned int dsize = sizeof(buf) - 2;
    unsigned int lc_t = 0;
    for (int i = 0; i < dsize; i++) {
        if ( buf[i] == ' ' ) {
            revers_str(buf, lc_t, i-1);
            lc_t = i + 1;
        }
    }

    printf("second revers: %s\n", buf);
    return 0;
}
