
# FunctionList

* Status InitList(Sqlist& L)
  > receive a list reference, initialize ten Elemtype of space, then return a status code.

* Status ClearList(Sqlist& L)
  > clear a list, then return a status code.

* Status DestoryList(Sqlist& L)
  > destory the given list.
  
* int GetLength(Sqlist L)
  > get length of the given list.
  
* Status ListInsert(Sqlist& L, int i, ElemType e)
  > insert the given elem into list according to the specified index, return a status code.
  
* Status ListDelete(Sqlist& L, int i)
  > delete the elem according to the specified index, return a status code.
  
* Status ListPop(Sqlist& L, int i, ElemType& e)
  > pop the elem according to the specified index, then store in a varaiable, return a status code.
  
* int LocateElem(Sqlist L, ElemType e)
  > locate the given elem, return index if exist in list, otherwise return 0.
  
* Status PrintElem(Sqlist L)
  > print all elem in a list, return a status code.
  
* Status UnionList(Sqlist& dest, Sqlist source)
  > find an union based on the list dest and source, then assign to list dest., return status code.
  
* Status GetElem(Sqlist L, int i, ElemType& e)
  > get a elem in the list accordind to the specified index, return status code.
  
* Status AddElem(Sqlist& L, ElemType e)
  >add the given elem to the end of list.
  
* Status ModifyElem(Sqlist& L, int i, ElemType e)
  > modify the elem in the list according to the given index, return status code.

* bool IsEmpty(Sqlist L)
  > check whether list if empty, return ture if true, ohterwise return false.
  
* bool IsFull(Sqlist L)
  > check whether list if full, return ture if true, ohterwise return false.
  
* void AscSortList(Sqlist& L)
  > ascending sort the given list.
 
* void MergeList(Sqlist La, Sqlist Lb, Sqlist& Lc)
  > find an union based on the list la and lb, then assign to list Lc.
  
* Status Intersection(Sqlist& La, Sqlist Lb)
  > find an intersaction based on list la and lb, then assign to list La.
