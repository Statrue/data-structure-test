#pragma once
#include <stdio.h>
#include <stdlib.h>

#define OK 111
#define ERROR -111
#define OVERFLOW -11
#define List_Init_Size 10
#define ListIncrement 10
#define NOTFOUND -3

typedef int Status;

typedef struct {
	int num;
	char name[30];
}Elemtype;

typedef struct Lnode{
	Elemtype data;
	struct Lnode* next;
}LNode, *LinkedList;

Status InitList_L(LinkedList& L);
int ListLength(LinkedList L);
Status GetElem(LinkedList L, int i, Elemtype& e);
Status ListInsert(LinkedList& L, int i, Elemtype e);
Status ListDelete(LinkedList& L, int i);
Status ListPop(LinkedList& L, int i, Elemtype& e);
Status PriorElem_L(LinkedList L, Elemtype e, Elemtype& pre_e);
Status PrintList_L(LinkedList L);
Status MergeList(LinkedList La, LinkedList Lb, LinkedList& Lc);
Status ReverseList(LinkedList& L);
Status SeperateList(LinkedList SourceList, LinkedList La, LinkedList Lb);
bool equals(Elemtype s, Elemtype r);
int compare(Elemtype s, Elemtype r);
void AddElem(LinkedList& L, Elemtype e);
int LocateElem_L(LinkedList L, Elemtype e);
