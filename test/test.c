/*
 * Filename   test.c
 * CreateTime 2017-03-20 21:21:15
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct _TreeNode TN;
struct _TreeNode {
    int val;
    TN *left;
    TN *right;
};

typedef struct ListNode LN; 
struct ListNode {
    int val;
    LN *next;
};

int main()
{
    LN *head = malloc(sizeof(LN));
    head->val = 0;
    head->next = NULL;
    LN *p = head;
    for (int i = 1; i < 7; i++) {
        p->next = malloc(sizeof(LN));
        p->next->val = i;
        p = p->next;
    } 

    p->next = NULL;

    printf("list val: \n");
    p = head;
    int len = 0;
    while(p) {
        //printf("%d ", p->val);
        len++;
        p = p->next;
    }
    printf("len: %d\n", len);

    return 0;
}

