// 1016 �ַ��任

// ʱ������:1000MS  �ڴ�����:65536K
// �ύ����:4076 ͨ������:2872

// ����: �����   ����: C++;C
// Description

// �ɼ�������5���ַ��������еĴ�д�ַ����Сд���������͵��ַ����䣩����󣬰�����˳�������5���ַ���

#include<stdio.h>
#include<string.h>
int main(){
	char ch;
	int i;
	for(i=0;i<=4;i++){
			scanf("%c",&ch);
		if(ch>='A'&&ch<='Z'){
			ch=ch+'a'-'A';
		}
		printf("%c",ch );
	}
	return 0;
}