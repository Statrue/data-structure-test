#include "La.h"

Status InitList(Sqlist& L) {
	L.elem = (ElemType*)malloc(sizeof(ElemType) * List_Init_Size);
	if (L.elem == NULL) exit(OVERFLOW);
	L.length = 0;
	L.capacity = List_Init_Size;
	return OK;
}

Status ClearList(Sqlist& L)
{
	if (L.elem == NULL) return ERROR;
	L.length = 0;
	return OK;
}

Status DestoryList(Sqlist& L)
{
	if (L.elem == NULL) return ERROR;
	free(L.elem);
	return OK;
}

int GetLength(Sqlist L)
{
	if (L.elem == NULL) return ERROR;
	return L.length;
}

Status ListInsert(Sqlist& L, int i, ElemType e)
{
	ElemType* p;
	if (i < 1 || i > L.length + 1) return ERROR;
	if (L.length >= L.capacity)
	{
		p = (ElemType*)realloc(L.elem, (List_Init_Size + ListIncrement) * sizeof(ElemType));
		if (p == NULL) exit(OVERFLOW);
		L.elem = p;
		L.capacity += ListIncrement;
	}
	for (int j = L.length; j >= i - 1; j--)
		L.elem[j] = L.elem[j - 1];
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

Status ListDelete(Sqlist& L, int i)
{
	if (i < 1 || i > L.length) return ERROR;
	for (int j = i; j < L.length; j++)
		L.elem[j - 1] = L.elem[j];
	L.length--;
	return OK;
}

Status ListPop(Sqlist& L, int i, ElemType& e)
{
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j < L.length; j++)
		L.elem[j - 1] = L.elem[j];
	L.length--;
	return OK;
}

int LocateElem(Sqlist L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e) return i + 1;
	return 0;
}

Status PrintElem(Sqlist L)
{
	if (L.length == 0) return ERROR;
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
	printf("\n");
	return OK;
}

Status UnionList(Sqlist& dest, Sqlist source)
{
	ElemType e;

	int dest_Len = GetLength(dest);
	int src_Len = GetLength(source);
	for (int i = 1; i <= src_Len; i++)
	{
		GetElem(source, i, e);
		if (!LocateElem(dest, e))
			AddElem(dest, e);
	}
	return OK;
}

Status GetElem(Sqlist L, int i, ElemType& e)
{
	if (i < 1 || i > L.length + 1) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

Status AddElem(Sqlist& L, ElemType e)
{
	if (L.length >= L.capacity)
	{
		ElemType* p = (ElemType*)realloc(L.elem, (List_Init_Size + ListIncrement) * sizeof(ElemType));
		if (p == NULL) exit(OVERFLOW);
		L.elem = p;
		L.capacity += ListIncrement;
	}
	L.elem[L.length] = e;
	L.length++;
	return OK;
}

Status ModifyElem(Sqlist& L, int i, ElemType e)
{
	if (i < 1 || i > L.length) return ERROR;
	L.elem[i - 1] = e;
	return OK;
}

bool IsEmpty(Sqlist L)
{
	return L.length == 0;
}

bool IsFull(Sqlist L)
{
	return L.length == L.capacity;
}

void AscSortList(Sqlist& L)
{
	for (int i = 0; i < L.length; i++)
	{
		int index = i;
		for (int j = i; j < L.length; j++)
			index = (L.elem[j] < L.elem[index]) ? j : index;
		if (index != i)
		{
			ElemType temp = L.elem[index];
			L.elem[index] = L.elem[i];
			L.elem[i] = temp;
		}
	}
}

void MergeList(Sqlist La, Sqlist Lb, Sqlist& Lc)
{
	Lc.length = 0;
	Lc.elem = (ElemType*)malloc(sizeof(ElemType) * Lc.length);
	UnionList(Lc, La);
	UnionList(Lc, Lb);
	AscSortList(Lc);
}

Status Intersection(Sqlist& La, Sqlist Lb)
{
	ElemType e;
	for (int i = 0; i < La.length; i++)
	{
		GetElem(La, i + 1, e);
		if (!LocateElem(Lb, e))
		{
			ListDelete(La, i + 1);
			i--;
		}
	}return OK;
}
