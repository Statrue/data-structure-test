#include "LinkedList.h"

int main(void)
{
	LinkedList La, Lb, Lc;

	InitList_L(La);
	InitList_L(Lb);
	InitList_L(Lc);

	AddElem(La, { 66, "胡" });
	AddElem(La, { 68, "双" });
	AddElem(La, { 69, "龙" });

	AddElem(Lb, { 66, "胡" });
	AddElem(Lb, { 67, "杨" });
	AddElem(Lb, { 70, "简" });
	AddElem(Lb, { 71, "罗" });
	AddElem(Lb, { 72, "魏" });

	PrintList_L(La);
	printf("-------------------- Initailize La --------------------\n\n");
	PrintList_L(Lb);
	printf("-------------------- Initailize Lb --------------------\n\n");

	MergeList(La, Lb, Lc);
	PrintList_L(Lc);
	printf("------------------ Merge La, Lb to Lc -----------------\n\n");

	ReverseList(Lc);
	PrintList_L(Lc);
	printf("---------------------- Reverse Lc ---------------------\n\n");

	InitList_L(La);
	InitList_L(Lb);
	ReverseList(Lc);
	SeperateList(Lc, La, Lb);
	PrintList_L(La);
	printf("----------------------- Odd L -------------------------\n\n");
	PrintList_L(Lb);
	printf("----------------------- Even L ------------------------\n\n");

	return 0;
}
