#include<stdio.h>
#define M 5
int a;
int b=0;
int c=3;
const int f=4;
void fun()
{
	const int h=3;
 }
int main()
{
	int c =M * M;
	printf("%d\n",c);//这里是注释
	printf("%d\n",h);
	return 0; 
}


