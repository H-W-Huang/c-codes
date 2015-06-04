#include <stdio.h>  
  #include <stdlib.h>  
  #define TRUE 1  
  #define FALSE 0  
  #define OK 1  
  #define ERROR 0  
  #define OVERFLOW -2  
  typedef int Status;  
  #define LIST_INIT_SIZE 10  
  #define LISTINCREMENT 4  
  typedef int ElemType;  
  typedef struct SqList  
  {  
  ElemType * elem;  
  int length;        //表的初始长度  
  int listsize; //表的初始存储容量  
  }SqList;  
  Status InitList_Sq（SqList *L）； /*初始化建立线性表*/  
  Status IsFull_Sq（SqList *L）；    /*判断线性表是否满*/  
  Status IsEmpty_Sq（SqList *L）；    /*判断线性表是否为空*/  
  void DestoryList_Sq（SqList *L）； /*销毁线性表*/  
  void ClearList_Sq（SqList *L）；    /*置空线性表*/  
  int ListLength_Sq（SqList *L）；    /*获取线性表长度*/  
  Status ListInsert_Sq（SqList *L, int i, ElemType e）； /*在表L中第i个位置插入一个元素，元素值为e*/  
  Status ListDelete_Sq（SqList *L, int i, ElemType *e）； /*删除线性表中第i个位置元素*/  
  Status GetElem_Sq（SqList *L, int i, ElemType *e）；     /*获取线性表L中第i个位置的值*/  
  /*若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败*/  
  Status PriorElem（SqList *L, ElemType cur_e, ElemType *pre_e）；  
  /*若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败*/  
  Status NextElem（SqList *L, ElemType cur_e, ElemType *next_e）；  
  /*遍历输出顺序表中所有元素*/  
  Status ListTransver_Sq（SqList *L）；  
  /*对顺序表中元素进行排序*/  
  void ListSort_Sq（SqList *L）；  
  /*倒置顺序表中所有元素*/  
  void ListInvert_Sq（SqList *L）；  
  Status InitList_Sq（SqList *L）  
  {  
  L->elem = （ElemType *）malloc（LIST_INIT_SIZE * sizeof（ElemType））；  
  if （NULL == L->elem）  
  {  
  printf（"动态内存分配失败！\n"）；  
  return OVERFLOW;  
  }  
  L->length = 0;                    //表初始长度为0  
  L->listsize = LIST_INIT_SIZE;    //表的初始容量为LIST_INIT_SIZE  
  return OK;  
  }  
  /*销毁线性表*/  
  void DestroyList_Sq（SqList *L）  
  {  
  if（L->elem != NULL）  
  {  
  free（L->elem）；  
  L->elem = NULL; //释放elem所指内存空间后，置空elem指针  
  L->length = 0;  
  L->listsize = 0;  
  }  
  }  
  /*置空线性表*/  
  void ClearList_Sq（SqList *L）  
  {  
  L->length = 0;  
  }  
  /*获取线性表长度*/  
  int ListLength_Sq（SqList *L）  
  {  
  return L->length;  
  }  
  /*获取线性表L中第i个位置的值*/  
  Status GetElem_Sq（SqList *L, int i, ElemType *e）  
  {  
  //判断L是否为空  
  if （IsEmpty_Sq（L））  
  {  
  printf（"线性表L为空\n"）；  
  return ERROR;  
  }  
  //判断i是否合法  
  if （i < 1 || i > L->length）  
  {  
  printf（"不存在%d位置元素\n", i）；  
  return ERROR;  
  }  
  *e = L->elem[i - 1];  
  return OK;  
  }  
  /*判断线性表是否为空*/  
  Status IsEmpty_Sq（SqList *L）  
  {  
  if （L->length == 0）  
  return TRUE;  
  else  
  return FALSE;  
  }  
  /*判断线性表是否满*/  
  Status IsFull_Sq（SqList *L）  
  {  
  if （L->length >= L->listsize）  
  return TRUE;  
  else  
  return FALSE;  
  }  
  /*若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败*/  
  Status PriorElem（SqList *L, ElemType cur_e, ElemType *pre_e）  
  {  
  int i = 2; //从第二个元素开始  
  while （i <= L->length）  
  {  
  if （L->elem[i - 1] == cur_e）  
  {  
  *pre_e = L->elem[i - 2];  
  return OK;  
  }  
  i++;  
  }  
  return ERROR;  
  }  
  /*若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败*/  
  Status NextElem（SqList *L, ElemType cur_e, ElemType *next_e）  
  {  
  int i = 0;  
  while （i < L->length - 1）  
  {  
  if （L->elem[i] == cur_e）  
  {  
  *next_e = L->elem[i + 1];  
  return OK;  
  }  
  i++;  
  }  
  return ERROR;  
  }  
Status ListInsert_Sq（SqList *L, int i, ElemType e）  
  {  
  if （i < 1 || i > L->length + 1） //判断插入位置i是否合法  
  return ERROR;  
  if （L->length >= L->listsize） //判读存储空间是否已满  
  {  
  ElemType * newbase = （ElemType *）realloc（L->elem, （L->listsize + LISTINCREMENT） * sizeof（ElemType））；  
  if （！newbase）  
  exit（OVERFLOW）；  
  L->elem = newbase;  
  L->listsize = L->listsize + LISTINCREMENT;  
  }  
  ElemType *q = &（L->elem[i - 1]）； //q指向第i个元素  
  ElemType *p;                     //p指向最后一个元素  
  for （p= &（L->elem[L->length - 1]）； p >= q; p--） //从最后一个位置开始移动  
  {  
  *（p + 1） = *p;  
  }  
  *q = e;  
  L->length++;  
  return OK;  
  }  
  //删除线性表中第i个位置元素  
  Status ListDelete_Sq（SqList *L, int i, ElemType *e）  
  {  
  if （L->length == 0） //判断表是否为空  
  {  
  printf（"表为空\n"）；  
  return ERROR;  
  }  
  if （i < 1 || i > L->length） //判断删除位置是否合法  
  {  
  printf（"删除位置不合法\n"）；  
  return ERROR;  
  }  
  /* 
  int j; 
  *e = L->elem[i - 1]; 
  for （j = i; j < L->length; j++） 
  { 
  L->elem[j - 1] = L->elem[j]; 
  } 
  */  
  ElemType *p = &（L->elem[i - 1]）； //p指向待删除的元素  
  *e = *p;  
  ElemType *q = &（L->elem[L->length - 1]）；  
  //ElemType *q = L->elem + L->length - 1; //q指向最后一个元素  
  for （p = p + 1; p <= q; p++） //p从待删除的后一个元素开始，直到最后一个元素，每个元素一次向前移动一个位置  
  {  
  *（p - 1） = *p;  
  }  
  L->length--; //最后，线性表长度减一  
  return OK;  
  }  
  /*在表尾增加元素*/  
  Status ListAppend_Sq（SqList *L, ElemType e）  
  {  
  if （L->length >= L->listsize） //当前表已经满了，重新分配LISTINCREMENT个空间  
  {  
  ElemType *newbase = （ElemType *）realloc（L->elem, （L->length + LISTINCREMENT） * sizeof（ElemType））；  
  if （！newbase）  
  return ERROR;  
  L->elem = newbase; //L->elem指向新分配的内存开始地址  
  L->listsize += LISTINCREMENT; //表的容量增加LISTINCREMENT  
  }  
  L->elem[L->length] = e;  
  L->length++;  
  return OK;  
  }  
  /*倒置顺序表中所有元素*/  
  void ListInvert_Sq（SqList *L）  
  {  
  int i = 0, j = L->length - 1, tmp;  
  while （i < j）  
  {  
  tmp = L->elem[i];  
  L->elem[i] = L->elem[j];  
  L->elem[j] = tmp;  
  i++;  
  j--;  
  }  
  }  
  /*对顺序表中元素进行排序*/  
  void ListSort_Sq（SqList *L）  
  {  
  int i, j, tmp, min;  
  for （i = 0; i < L->length - 1; i++）  
  {  
  min = i;  
  for （j = i; j < L->length; j++）  
  {  
  if （L->elem[j] < L->elem[min]）  
  min = j;  
  }  
  tmp = L->elem[i];  
  L->elem[i] = L->elem[min];  
  L->elem[min] = tmp;  
  }  
  }  
/*遍历输出顺序表中所有元素*/  
  Status ListTransver_Sq（SqList *L）  
  {  
  int i;  
  if （L->length == 0）  
  {  
  printf（"表为空\n"）；  
  return ERROR;  
  }  
  else  
  {  
  for （i = 0; i < L->length; i++）  
  {  
  printf（"%d ", L->elem[i]）；  
  }  
  printf（"\n"）；  
  }  
  return OK;  
  }  
  int main（）  
  {  
  SqList L;  
  ElemType e;  
  if（InitList_Sq（&L））  
  {  
  printf（"--->顺序表初始化成功\n"）；  
  }  
  else  
  {  
  printf（"--->顺序表初始化失败，程序退出\n"）；  
  return ERROR;  
  }  
  printf（"--->顺序表是否为空？ \n"）；  
  if （IsEmpty_Sq（&L））  
  printf（"为空\n"）；  
  else  
  printf（"非空\n"）；  
  printf（"长度为： %d\n", ListLength_Sq（&L））；  
  printf（"--->在顺序表中插入元素： "）；  
  int i;  
  for （i = 1; i <= 5; i++）  
  ListInsert_Sq（&L, i, i * 2）；  
  ListTransver_Sq（&L）；  
  printf（"长度为： %d\n", ListLength_Sq（&L））；  
  printf（"--->在顺序表末尾添加元素： "）；  
  ListAppend_Sq（&L, 9）；  
  ListAppend_Sq（&L, 3）；  
  ListAppend_Sq（&L, 6）；  
  ListAppend_Sq（&L, 15）；  
  ListTransver_Sq（&L）；  
  printf（"长度为： %d\n", ListLength_Sq（&L））；  
  printf（"--->查找元素的前驱：\n"）；  
  printf（"输入要查找的值： "）；  
  scanf（"%d", &i）；  
  if （PriorElem（&L, i, &e））  
  {  
  printf（"存在前驱，前驱值为： %d\n", e）；  
  }  
  else  
  {  
  printf（"不存在前驱\n"）；  
  }  
  printf（"--->查找元素的后继：\n"）；  
  printf（"输入要查找的值： "）；  
  scanf（"%d", &i）；  
  if （NextElem（&L, i, &e））  
  {  
  printf（"存在后继，后继值为： %d\n", e）；  
  }  
  else  
  {  
  printf（"不存在后继\n"）；  
  }  
  printf（"--->删除顺序表中某个位置的元素： \n"）；  
  printf（"输入位置<1 ~ %d>: ", L.length）；  
  scanf（"%d", &i）；  
  printf（"删除前： "）；  
  printf（"长度为： %d\n", ListLength_Sq（&L））；  
  ListTransver_Sq（&L）；  
  ListDelete_Sq（&L, i, &e）；  
  printf（"删除后： "）；  
  printf（"长度为： %d\n", ListLength_Sq（&L））；  
  ListTransver_Sq（&L）；  
  printf（"--->倒置顺序表中的所有元素： \n"）；  
  printf（"倒置前： "）；  
  ListTransver_Sq（&L）；  
  printf（"倒置后： "）；  
  ListInvert_Sq（&L）；  
  ListTransver_Sq（&L）；  
  printf（"--->对顺序表中的元素进行排序： \n"）；  
  printf（"排序前： "）；  
  ListTransver_Sq（&L）；  
  printf（"排序后： "）；  
  ListSort_Sq（&L）；  
  ListTransver_Sq（&L）；  
  printf（"释放线性表\n"）；  
  DestroyList_Sq（&L）；  
  return 0;  
  }  