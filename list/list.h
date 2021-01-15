#pragma once

#include <stdlib.h>
#include <iostream>
#define ERROR -1
#define OVERFLOW 1
#define OK 1
#define MAXSIZE 100
typedef bool Status;
typedef int Elem;
struct List
{
    int *elem;
    int length;
};

Status InitList(List &l)
{
    l.elem = new int[MAXSIZE];
    if (!l.elem) exit(OVERFLOW);
    l.length = 0;
    return OK;
}

void DestroyList(List& l)
{
    delete l.elem;
    l.elem = NULL;
    l.length = 0;
}
    
void ClearList(List&);

bool ListEmpty(List l)
{
    if (!l.elem) return false;
    if (l.elem && l.length == 0) return false;
    else return true;
}

int ListLength(List l)
{
    return l.length;
}

Status GetElem(List l, int i, Elem &e)
{
    if (i < 1 || i > l.length) return ERROR;
    e = l.elem[i - 1];
    return OK;
}

int LocateElem(List l, Elem e)
{
    for (int i = 0; i < l.length; ++i) {
        if (l.elem[i] == e)
            return i + 1;
    }
    return 0;
}

Status PriorElem(List l, Elem cur_e, Elem &pre_e)
{
    for (int i = 0; i < l.length; ++i) {
        if (l.elem[i] == cur_e) {
            if (i == 0) {
                printf("the %d is the first number, has not pre_e", cur_e);
                return 0;
            }
            else {
                pre_e = l.elem[i - 1];
                return OK;
            }
        }
    }
    printf("%d is not in it\n", cur_e);   
    return 0;
}

Elem NextElem(List, Elem cur_e, Elem &next_e);

Status ListInsert(List& l, int i, Elem e)
{
    if (i < 1 || i > l.length + 1) return ERROR;
    if (l.length == MAXSIZE) return ERROR;
    for (int j = l.length; j >= i; --j) {
        l.elem[j] = l.elem[j - 1];
    }
    l.elem[i - 1] = e;
    ++l.length;
    return OK;
}

void ListDelete(List&, int);

void TraverseList(List l)
{
    for (int i = 0; i < l.length; ++i)
       std::cout << l.elem[i] << " "; 
}




