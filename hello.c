// 1016 字符变换

// 时间限制:1000MS  内存限制:65536K
// 提交次数:4076 通过次数:2872

// 题型: 编程题   语言: C++;C
// Description

// 由键盘输入5个字符，将其中的大写字符变成小写（其它类型的字符不变），最后，按输入顺序输出这5个字符。

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