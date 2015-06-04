//B  安全的密码
//
//Time Limit:1000MS  Memory Limit:65535K
//题型: 编程题   语言: 无限制
//描述
//
//小明网上做题的帐号又被盗了，为了防止自己的新帐号再次被盗，小明决定增强密码安全，定期的更换密码
//为了容易记住每次更改的密码，小明决定所有密码都是6位数码（每位数码可以是0-9中任意一个）且满足另外两个共同特征：
//（1）密码中包含自己的幸运数码（包含的含义是指从密码中去掉0个或若干个数码，剩下的数码按顺序能构成幸运数码）；
//（2）密码的所有数码加起来的和为一个质数；
//例如假设幸运数码是01314，则021314，801314都是满足条件的密码
//
//现要求由键盘输入不超过6位的幸运数码，由程序输出满足条件的不同6位密码的个数
//
//输入格式
//
//不超过6位的幸运数码
//输出格式
//
//不同的6位密码的个数
//输入样例
//
//01314
//输出样例
//
//17
//Provider
//
//admin
/******
方法1.
    计算lucknum的位数，得到还需要测试的数的范围，对每个数一一检查是否符合条件，再通过排列组合计算个数
    私以为这种方法具体实现复杂，暂时不用了。
方法2.
    枚举
方法3.
    换成字符串来操作？
*******/




#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
//检查是否为素数
int Is_prime(int sum)
{
    int i;
    for(i=0;i<=sum/2;i++)
        if(sum%i==0) break;
    if(i>sum/2) return 1;
    else return 0;
}


////计算luck_number的长度
//int luck_number_length(int n)
//{
//    int length=0;
//    do{
//        n/=10;
//        length++;
//    }while(n!=0);
//    return length;
//}
//
////
int num_split(int n)
{
    int m,sum=0;
    do{
        m=n%10;
        n/=10;
        sum+=m;
    }while(n!=0);
    return sum;
}
//
//
////计算密码的个数
//int Amount_of_Passwords()
//{
//    int i,sum,luck_num=0,a[6],num_to_test=1,amount=0;
//    scanf("%d",&luck_num);
//    //开始枚举
//    printf("The length of the luck number is %d \n",luck_number_length(luck_num));
//    for(i=0;i<=(6-luck_number_length(luck_num));i++)
//    {
//        num_to_test*=10;
//    }
//    num_to_test--;
//    printf("Numbers to be tested start from %d to 0\n",num_to_test);
//    while(num_to_test!=0)
//    {
//        if(!Is_prime(num_split(num_to_test)+num_split(luck_num)))
//        {
//
//        }
//    }
//    return amount;
//}
int Amount_of_Passwords()
{
    int luck_num=0,i=0;
    scanf("%d",&luck_num);
    for(i=0;i<=10000l;i++)
    {
        if(Is_prime(num_split(i))
        {
            for()
        }
    }

}

int main()
{
    Amount_of_Passwords();
    return 0;
}
