#include<stdio.h>
//�������ͱ�����for��ʹ�á�������˵for���á�ֻ��˵��
//���һ�㲻�Ǹ���ô��
int main(){
    int n;
    while(n--){
        /* codes */
    }
}


//����� 0 0Ϊ������־����
//�������ĺô����ڣ���while˳�������ж�
//ע�ⶺ�� �����
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b),!(a==0&&b==0)){
        /* codes */
    }         
}


//��������һ�������� û�о������������־ �����
//������������ scanf()���������ж�
int main(){
    int a,b;    
    while(scanf("%d%d",&a,&b)>0)
    {
        /* codes */
    }   
}