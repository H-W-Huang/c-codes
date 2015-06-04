#include<stdio.h>
#include<math.h>
int main()
{
    double item=1,sum=0;
    int j=1,flag=1;
    while(fabs(item)>0.0000001){
        item=1.0/(2*j-1)*flag;
        sum+=item;
        flag=-flag;
        j++;
    }
    printf("%.6lf\n",sum*4 );
    return 0;
}


