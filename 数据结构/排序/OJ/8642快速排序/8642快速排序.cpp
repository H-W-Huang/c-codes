// 8642 ��������

// ʱ������:1000MS  �ڴ�����:1000K
// �ύ����:2105 ͨ������:1352

// ����: �����   ����: G++;GCC
// Description

// �ú���ʵ�ֿ������򣬲����ÿ�η���������Ľ��



// �����ʽ

// ��һ�У��������������ؼ��ĸ���n
// �ڶ��У�����n��������ؼ��֣��ÿո�ָ�����


// �����ʽ

// ÿ�����ÿ������Ľ��������֮����һ���ո�ָ�


// ��������

// 10
// 5 4 8 0 9 3 2 6 7 1


// �������

// 1 4 2 0 3 5 9 6 7 8
// 0 1 2 4 3 5 9 6 7 8
// 0 1 2 4 3 5 9 6 7 8
// 0 1 2 3 4 5 9 6 7 8
// 0 1 2 3 4 5 8 6 7 9
// 0 1 2 3 4 5 7 6 8 9
// 0 1 2 3 4 5 6 7 8 9


// ��ʾ



// ����

// yqm


#include <cstdio>
int para(int *a,int n)
{
    int povitkey,low,high,temp;
    low=1;high=n;
    povitkey=a[low];
    a[0]=a[low];
    //ѭ������ low < high
    while(low<high)
    {
        while(low<high && a[high]>=povitkey) high--;
        temp=a[high]; a[high]=a[low]; a[low]=temp;
        while(low<high && a[low]<=povitkey) low++;
        temp=a[low]; a[low]=a[high]; a[high]=temp;
    }
    a[low]=povitkey;
    return low;
}

int Quick_Sort(int *a,int low,int high)
{
    //������ѭ�������ܵ�ԭ����û���������� low< high
    if(low < high)
    {
        int i,povit=para(a,n);
        for(i=1;i<=len;i++) printf("%d ", a[i]); putchar('\n');
        Quick_Sort(a,povit+1,len);
        Quick_Sort(a,povit-1,len);
    }
    return 0;
}

int main()
{
    int a[30],n,i,len;
    scanf("%d",&n);
    len=n;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);

    return 0;
}