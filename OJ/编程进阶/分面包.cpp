//L  ·ÖÃæ°ü
//
//Time Limit:1000MS  Memory Limit:65535K
//ÌâÐÍ: ±à³ÌÌâ   ÓïÑÔ: ÎÞÏÞÖÆ
//ÃèÊö
//ÔÚ´óÒ»µÄÊ±ºò£¬XCC»¹ÔÚstu union´ò½´ÓÍ~~~~ºÍÊ®Èý»¹ÓÐÄÌ×ÓËûÃÇÈ¥ÍâÃæ³Ô³ÔºÈºÈÊÇ³£ÓÐµÄÊÂ¡£
//´ó¼Ò¶¼ÖªµÀ¿Õ¸¹ºÈ¾ÆÊÇÓÐº¦¶Ç×ÓµÎ£¬ËùÒÔÄØ£¬ÒªÂòÒ»Ð©Ãæ°üÀ´ÏÂ¾Æ¡£²»¹ýÎÒÃÇÓÐ¸öÏ°¹ß£¬
//¾ÍÊÇËùÓÐµÄn¸öÈË£¬Ã¿¸öÈË·ÖµÃµÄÃæ°ü±ØÐë³¤¶ÈÏàµÈ£¨³¤¶ÈÏàµÈµÄÃæ°üµÄÁ¿ÊÇÒ»ÑùµÄ£©£¬
//Í¬Ê±¸øÃ¿¸öÈË·ÖÃæ°üÊ±£¬·ÖµÃµÄÐ¡Ãæ°ü±ØÐëÊÇÀ´×ÔÍ¬Ò»¿éÃæ°üµÄ£¬¼´²»ÄÜ°ÑÁ½¸ö²»Í¬Ãæ°ü¸÷ÇÐÒ»²¿·ÖÏÂÀ´´ÕºÏ³ÉÒ»·ÝÃæ°üÀ´·Ö¡£
//ÏÖÔÚÒ»ÆðÀ´µÄÓÐn¸öÈË£¬ÂòÁËm¸öÃæ°ü£¬ÇóÃ¿ÈË·ÖµÃµÄ×î³¤Ãæ°ü³¤¶È¡£
//
//ÊäÈë¸ñÊ½
//
//µÚÒ»ÐÐÊÇÈËÊý n ºÍÃæ°üÊýÄ¿ m (3<= n <= 16 , 1 <= m <= 100)£¬µÚ¶þÐÐ m ¸öÊý×Ö±íÊ¾ m ¸öÃæ°üµÄ³¤¶È L £¬¾ùÎªÕûÊý( 1 <= L <= 1000000)
//Êä³ö¸ñÊ½
//
//Ã¿ÈË·ÖµÃµÄ×î³¤Ãæ°ü³¤¶È£¬±£Áô2Î»Ð¡Êý
//ÊäÈëÑùÀý
//
//3  3
//3  3  3
//Êä³öÑùÀý
//
//3.00
//Hint
//
//×¢ÒâÌâÄ¿ÃèÊö
//Provider
//
//scau_acm



//´ð°¸·¶Î§ÔÚ 0 µ½ maxl Ö®¼ä maxl=L/n
// 

#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;


int check(int n,int m,double bread[],double mid)
{
    int sum=0;
    for(int i=0;i<m;i++)
    {
        sum+=(int)(bread[i]/mid);
    }
    // printf("sum==%d\n",sum);
    if(sum>=n) return 1;
    else return 0;
}



float Bread_Dispatch(int  n,int  m,double bread[],double L)
{
//    printf("Bread_Dispatching ....\n");
//    printf("L==%lf\n",L );
    double r=L,len=0,mid=0;
//    printf("r==%lf\n",r);
    while(fabs(len-r)>0.0002)
    {
        mid=(r+len)/2;
//         printf("mid==%lf\n",mid);
//         printf("r==%lf\n",r );
        if(check(n,m,bread,mid)) len=mid;
        else r=mid;
//         printf("len==%lf\n",len);
    }
    return len;
}



double bread[1000005];
int main()
{
    int n,m;
    double L=0.0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {scanf("%lf",&bread[i]); L+=bread[i];}
    printf("%.2f",Bread_Dispatch(n,m,bread,L));
}
