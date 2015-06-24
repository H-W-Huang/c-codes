#include <cstdio>


//
//与递归实现的不一样。递归实现的是逆向求编码，而当下这种方法是正向的
int code()
{
    HC=(HuffmanCode)malloc((n+1)*sizeof(char *));  //为哈夫曼编码数组申请空间
    for(i=1;i<m;i++)
        HT[i].weight=0; //遍历哈夫曼树时用作结点状态标志
    while(p)
    {
        if(HT[p].weight==0)
        {
            HT[p].weight=1; //表示左结点已经访问过
            if(HT[p].lchild!=0)
            {
                p=HT[p].lchild;
                cd[cdlen++]="0";
            }
            else if(HT[p].rchild==0)
            {
                HC[p]=(char *)malloc(cdlen+1)*sizeof(char);
                cd[cdlen]="\0";
                strcpy(HC[p],cd);
            }
        }
        else if(HT[p].weight==1)
        {
            HT[p].weight=2;
            if(HT[p].rchild!=0)
            {
                p=HT[p].rchild;
                cd[cdlen++]="1";
            }
        }
        else 
        {
            HT[p].weight=0;
            p=HT[p].parent;
            --cdlen;    //退回到父节点，编码长度减1
        }
    }//while
}
