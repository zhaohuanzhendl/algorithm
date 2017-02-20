/*
 * Filename   String_to_Integer_atoi.c
 * CreateTime 2017-02-17 16:56:02
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int new_atoi(const char *str)
{
    static const int MAX_INT = (int)((unsigned)~0 >> 1);
    static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
    //start test    
    
    int sign = 1;
    unsigned n = 0;
    int c = 0;

    if (str == 0) {
        return 0;
    }

    while (*str == ' ') {
        ++str;
    }

    if (*str == '+') {
        sign = 1;
        ++str;

    } else if (*str == '-') {
        sign = -1;
        ++str;

    }

    while (str) {
        if (*str < '0' || *str > '9') {
            //printf("not regular num input!!!"); // TODO: get the more appropriate solution
            break;
            //return -1; //do not return, othrewise get wrong result!
        }
        
        c = *str - '0';

        if (sign > 0 && n > 0 && (n > MAX_INT / 10 || (n == MAX_INT / 10 && c > MAX_INT % 10))) {
            return MAX_INT;
            break;

        } else if (sign < 0 && n > 0 &&(n > (unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT /10 && c > (unsigned)MIN_INT % 10))) {
            return MIN_INT;
            break;

        }

        n = n * 10 + c;
        ++str;

    }
    
    return sign > 0 ? n : -n;

}

//unittest

int main()
{
    char *s1 = " +1998234";
    char *s2 = " -797865";
    char *s3 = " -79*&^65";
    char *s4 = " 799999999999999999965";

    int r1 = new_atoi(s1);
    printf("result of s1 : %d\n", r1);
    
    int r2 = new_atoi(s2);
    printf("result of s2 : %d\n", r2);

    int r3 = new_atoi(s3);
    printf("result of s3 : %d\n", r3);

    int r4 = new_atoi(s4);
    printf("result of s4 : %d\n", r4);

    return 0;
}


