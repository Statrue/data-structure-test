#pragma once
#define OK 11
#define ERROR 0
#define OVERFLOW -11
#define List_Init_Size 10
#define ListIncrement 10

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType* elem;
	int length;
	int capacity;
}Sqlist;

Status InitList(Sqlist &L);
Status GetElem(Sqlist L, int i, ElemType& e);
int LocateElem(Sqlist L, ElemType e);
Status ListInsert(Sqlist& L, int i, ElemType e);
Status ListDelete(Sqlist& L, int i);
Status ListPop(Sqlist& L, int i, ElemType& e);
Status ClearList(Sqlist& L);
Status DestoryList(Sqlist& L);
bool IsEmpty(Sqlist L);
bool IsFull(Sqlist L);
Status AddElem(Sqlist& L, ElemType e);
Status PrintElem(Sqlist L);
Status ModifyElem(Sqlist& L, int i, ElemType e);
Status UnionList(Sqlist& dest, Sqlist source);
Status Intersaction(Sqlist& La, Sqlist lb);
void MergeList(Sqlist La, Sqlist Lb, Sqlist& Lc);
void AscSortList(Sqlist& L);
