#include "La.h"

int main(void)
{
	int i, e;
	Sqlist La, Lb, Lc;

	InitList(La);
	InitList(Lb);

	AddElem(La, 3);
	AddElem(La, 5);
	AddElem(La, 8);
	AddElem(La, 11);

	AddElem(Lb, 2);
	AddElem(Lb, 6);
	AddElem(Lb, 8);
	AddElem(Lb, 9);
	AddElem(Lb, 11);
	AddElem(Lb, 15);
	AddElem(Lb, 20);

	PrintElem(La);
	PrintElem(Lb);
	printf("------------------- Initailize La Lb -------------------\n\n");

	MergeList(La, Lb, Lc);
	PrintElem(Lc);
	printf("----------------------- Union Lc -----------------------\n\n");

	UnionList(La, Lb);
	AscSortList(La);
	PrintElem(La);
	printf("----------------------- Union La -----------------------\n\n");

	DestoryList(La);
	InitList(La);
	AddElem(La, 3);
	AddElem(La, 5);
	AddElem(La, 8);
	AddElem(La, 11);
	Intersaction(La, Lb);
	PrintElem(La);
	printf("-------------------- Intersaction La -------------------\n\n");

	return 0;
}
