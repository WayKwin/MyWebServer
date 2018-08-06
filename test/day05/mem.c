#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p = malloc(sizeof(int)*5);
	if(p==NULL)
	{
		return 0;
	}
	for(int i = 0;i < 5;i++)
	{
		p[i]=i;
	}
	for(int i = 0;i < 5;i++)
	{
		printf("p[%d]->%d\n",i,i);
	}
		free(p);
		return 0;
}
