/*
 * Filename   count_and_say.c
 * CreateTime 2017-03-02 06:40:30
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void count_say(char *str1, char *str2)
{
    int count = 1, i = 0,  j = 0;

    while (*(str1 + i + 1) != '\0') {
        if (*(str1 + i) == *(str1 + i + 1)) {
            i++;
            count++;

        } else {
            *(str2 + j++) = count + '0';
            *(str2 + j++) = *(str1 + i);
            i++;
            count = 1;

        }

    }

    *(str2 + j++) = count + '0';
    *(str2 + j++) = *(str1 + i);

}


char *count_and_say(int n)
{
    char *s, *p;
    s = (char *)malloc(9999 * sizeof(char));
    p = (char *)malloc(9999 * sizeof(char));

    memset(s, 0, 9999);
    memset(p, 0, 9999);
    strcpy(p, "1");
    for (int i = 1; i < n; i++) {
        count_say(p, s);
        strcpy(p, s);
    }

    return p;
}

int main()
{
    char *s = count_and_say(4);
    printf("res: %s\n", s);

    return 0;
}
