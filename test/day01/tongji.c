#include<stdio.h>
#incldue<stdlib.h>
int main(int argc,char *argv[])
{
	if(arc!=2)
	{
	fprintf(stderr,"%s filename\n",argv[0]);
	}
	FILE *fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
	fprintf(stderr,"open file err\n");
	exit (1);
}
}
