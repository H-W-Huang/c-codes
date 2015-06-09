// 8646 基数排序

// 时间限制:1000MS  内存限制:1000K
// 提交次数:1581 通过次数:1071

// 题型: 编程题   语言: G++;GCC
// Description

// 用函数实现基数排序，并输出每次分配收集后排序的结果



// 输入格式

// 第一行：键盘输入待排序关键的个数n
// 第二行：输入n个待排序关键字，用空格分隔数据


// 输出格式

// 每行输出每趟每次分配收集后排序的结果，数据之间用一个空格分隔


// 输入样例

// 10
// 278 109 063 930 589 184 505 069 008 083


// 输出样例

// 930 063 083 184 505 278 008 109 589 069 
// 505 008 109 930 063 069 278 083 184 589 
// 008 063 069 083 109 184 278 505 589 930 


// 提示



// 作者

// yqm

/*****************
    ATTENTION!!
非自己过脑实现，不算数的啊！！！！
*****************/


#include <stdio.h>
#define MAX_NUM_OF_KEY 8 //关键字项数的最大值
#define RADIX     10     //关键字基数，此时是十进制整数的基数
#define MAX_SPACE 10000
typedef int KeysType;
 
typedef struct 
{
        KeysType keys; //关键字
        int next;
}SLCell;
typedef struct 
{
        SLCell r[MAX_SPACE];       //静态链表的可利用空间，r[0]为头结点
        int keynum;                //记录当前关键字个数
        int recnum;                                   //静态链表的当前长度
}SLList;                       //静态链表类型
 
typedef int ArrType[RADIX];    //指针数组类型
 
int ord(KeysType key, int digitally)
{
        int i;
 
        if(digitally)
        {//根据位数，返回不同的数位
                for(i = 0; i < digitally; ++i)
                {
                        key /= 10;
                }                
        }
        return key % 10;
}
 
 
void Distribute(SLCell *r, int i, ArrType f, ArrType e)
{
        //静态链表L的r域中记录已按keys[0].....keys[i-1]有序。
        //本算法按第i个关键字keys[i]建立RADIX个子表，使同一子表中记录的keys[i]相同
        //f[0..RADIX-1]和e[0..RADIX-1]分别指向各子表中第一个和最后一个记录
        int j, p;
 
        for(j = 0; j < RADIX; ++j)
        {
                f[j] = e[j] = 0;   //初始化指针
        }
        for(p = r[0].next; p; p = r[p].next)
        {
                j = ord(r[p].keys, i); //取得相应数位上的值
                if(!f[j])
                        f[j] = p; //头指针为空，则取得结点位置
                else
                        r[e[j]].next = p; //原来的尾指针指向第i位数相同的新结点
                e[j] = p;  //尾指指向新结点作为最后结点
        }
}
 
void Collect(SLCell *r, int i, ArrType f, ArrType e)
{
        //本算法按keys[i]自小至大地将f[0..radix-1]所指各子表依次链接成一个链表
        //e[0..radix-1]为各子有的尾指针
        int j, t;
 
        for(j = 0; !f[j]; ++j); //找第一个非空子表
        r[0].next = f[j]; //r[0].next指向第一个非空结点
        t = e[j];
        while(j < RADIX-1)
        {
                for(j = j + 1; j < RADIX - 1 && !f[j]; ++j); //找下一个非空子表
                if(f[j])
                {
                        r[t].next = f[j];      //链接两非空子表
                        t = e[j];  //指向尾结点
                }
        }
        r[t].next = 0;  //t指向最后一个非空子表中的最后一个结点
}
 
void RadixSort(SLList *L)
{
        //L是采用静态链表表示的顺序表
        //对L作基数排序，使得L成为按关键字自小到大的有序静态链表，
        //L.r[0]为头结点
        int i;
        ArrType f, e;
 
        for(i = 0; i < L->recnum; ++i)
        {
                L->r[i].next = i + 1;
        }
        L->r[L->recnum].next = 0;  //L改造为静态链表
        for(i = 0; i < L->keynum; ++i)//按最低位优先依次对各关键字进行分配和收集
        {
                Distribute(L->r, i, f, e); //第i趟分配
                Collect(L->r, i, f, e);    //第i趟收集
                char temp[5];
                for(int k = L->r[0].next; k ; k= L->r[k].next)
                {
                    //字符串格式化输出
                    sprintf(temp, "%03d",L->r[k].keys);
                    printf("%s ",temp);
                }
                
                putchar('\n');

        }
}
 
int main(void)
{
        int a[1000],temp,n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]); //初始化数组
        SLList L;
        int i, nLen, nCount;
        nCount = 0;
        // nLen = n;
        L.recnum = n; //取得关键字个数
        temp = a[0];
        while(temp)
        {
                temp /= 10;
                nCount++;
        }
        L.keynum = nCount; //取得数据位数
 
        for(i = 0; i < L.recnum; ++i)
        {
                L.r[i + 1].keys = a[i]; //取得元素
        }
        RadixSort(&L);

        return 0;
}