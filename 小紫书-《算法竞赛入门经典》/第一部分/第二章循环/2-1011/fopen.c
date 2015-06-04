#include<stdio.h>
int main(){
    FILE *fin,*fout;
    fin=fopen("datain.txt","w");
    fout=fopen("dataout.txt","r");
    int a;
    char b[50];
    scanf("%s",&b);
    fprintf(fin,"%s",b);
    fscanf(fout,"%d",&a);
    printf("%d\n", a);
    return 0;
}