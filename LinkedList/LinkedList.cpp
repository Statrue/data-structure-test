#include "LinkedList.h"

Status InitList_L(LinkedList& L)
{
	L = (LinkedList)malloc(sizeof(LNode));
	if (L == NULL) exit(OVERFLOW);
	/* L->data = 0 */
	L->next = NULL;
	return OK;
}

int ListLength(LinkedList L)
{
	LinkedList p = L;
	int j = 0;

	while (p->next != NULL)
	{
		j++;
		p = p->next;
	}
	return j;
}

Status GetElem(LinkedList L, int i, Elemtype& e)
{
	LinkedList p = L->next;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

Status ListInsert(LinkedList& L, int i, Elemtype e)
{
	LinkedList p = L;
	int j = 0;
	while (p != NULL && j < i - 1) //find the i - 1th node
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > i + 1) return ERROR;
	LinkedList node = (LinkedList)malloc(sizeof(LNode));
	if (node == NULL) exit(OVERFLOW);
	node->data = e;
	node->next = p->next;
	p->next = node;
	return OK;
}

Status ListDelete(LinkedList& L, int i)
{
	LinkedList p = L;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || (p->next) == NULL || j > i - 1) return ERROR;
	p->next = p->next->next;
	return OK;
}

Status ListPop(LinkedList& L, int i, Elemtype& e)
{
	if (L == NULL) return ERROR;
	LinkedList p = L;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || (p->next) == NULL || j > i - 1) return ERROR;
	e = p->next->data;
	p->next = p->next->next;
	return OK;
}

Status PriorElem_L(LinkedList L, Elemtype e, Elemtype& pre_e)
{
	LinkedList p = L->next, q = L;
	int length = ListLength(L);
	int flag = 0;
	for (int i = 0; i < length && p != NULL; i++)
	{
		if (equals(e, p->data))
		{
			flag = 1;
			break;
		}
		p = p->next;
		q = q->next;
	}
	if (flag)
	{
		pre_e = q->data;
		return OK;
	}
	else
		return ERROR;
}

Status PrintList_L(LinkedList L)
{
	LinkedList p = L->next;
	if (p == NULL) return ERROR;
	while (p != NULL)
	{
		printf("{ num = %d, name = %s }\n", p->data.num, p->data.name);
		p = p->next;
	}
	return OK;
}

bool equals(Elemtype s, Elemtype r)
{
	return  s.num == r.num;
}

int compare(Elemtype s, Elemtype r)
{
	return s.num - r.num;
}

int LocateElem_L(LinkedList L, Elemtype e)
{
	int index = 1;
	LinkedList p = L->next;

	while (p != NULL)
	{
		if ( p->data.num == e.num )
			return index;
		p = p->next;
		index++;
	}
	return NOTFOUND;
}

void AddElem(LinkedList& L, Elemtype e)
{
	LinkedList p = L;
	while (p->next != NULL)
		p = p->next;
	LinkedList node = (LinkedList)malloc(sizeof(LNode));
	if (node == NULL) exit(OVERFLOW);
	node->data = e;
	node->next = NULL;
	p->next = node;
}

/*
void MergeList(LinkedList La, LinkedList Lb, LinkedList& Lc)
{
	LinkedList pa = La->next, pb = Lb->next, pc = Lc;
	while (pc->next != NULL)
		pc = pc->next;
	while (pa != NULL && pb != NULL)
	{
		int flag = compare(pa->data, pb->data);
		if (flag > 0) // pa > pb
		{
			pc->next = pb;
			pb = pb->next;
			pc = pc->next;
			pc->next = NULL;
		}
		else if (flag < 0) // pa < pb
		{
			pc->next = pa;
			pa = pa->next;
			pc = pc->next;
			pc->next = NULL;
		}
		else // pa = pb
		{
			pb = pb->next;
			pc->next = pa;
			pa = pa->next;
			pc = pc->next;
			pc->next = NULL;
		}
	}
	if (pa != NULL)
	{
		while (pa != NULL)
		{
			pc->next = pa;
			pa = pa->next;
			pc = pc->next;
			pc->next = NULL;
		}
	}
	if (pb != NULL)
	{
		while (pb != NULL)
		{
			pc->next = pb;
			pb = pb->next;
			pc = pc->next;
			pc->next = NULL;
		}
	}
	free(La);
	free(Lb);
}
*/

Status MergeList(LinkedList La, LinkedList Lb, LinkedList& Lc)
{
	LinkedList pa = La->next, pb = Lb->next, pc = Lc;
	while (pc->next != NULL)
		pc = pc->next;
	while (pa != NULL)
	{
		Elemtype min = pa->data;
		if (pb->data.num < min.num)
		{
			min = pb->data;
			pb = pb->next;
		}
		else
			pa = pa->next;
		if (LocateElem_L(Lc, min) == NOTFOUND)
			AddElem(Lc, min);
	}
	while (pb != NULL)
	{
		if (LocateElem_L(Lc, pb->data) == NOTFOUND)
			AddElem(Lc, pb->data);
		pb = pb->next;
	}
	return OK;
}

Status ReverseList(LinkedList& L)
{
	LinkedList walker = L->next, next, anchor = L;
	anchor->next = NULL;
	while (walker != NULL)
	{
		next = walker->next;
		walker->next = anchor->next;
		anchor->next = walker;
		walker = next;
	}
	return OK;
}

Status SeperateList(LinkedList SourceList, LinkedList OddL, LinkedList EvenL)
{
	LinkedList p = SourceList->next;
	int index = 1;
	while (p != NULL)
	{
		if (index % 2 == 1)
			AddElem(OddL, p->data);
		else
			AddElem(EvenL, p->data);
		index++;
		p = p->next;
	}
	return OK;
}
