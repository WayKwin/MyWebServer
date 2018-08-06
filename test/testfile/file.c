#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
void copy_file(const char*src,const char*dst,mode_t st_mode)
{
	umask(0);
	chmod(dst,st_mode);
	FILE * f_src=fopen(src,"r");
	FILE * f_dst=fopen(dst,"w");
	char buf[4096];
	int r;
	//此时r恰好就是实际读取的字节数
	//fread返回的是实际读取的个数(当size=1,就是字节数)也就是实际的count
	while((r=fread(buf,1,sizeof(buf),f_src))>0)
	{
		fwrite(buf,1,r,f_dst);
	}
	fclose(f_src);
	fclose(f_dst);
}
int main(int argc,char*argv[])
{
	struct stat sbuf;
	lstat(argv[1],&sbuf);
	copy_file(argv[1],argv[2],sbuf.st_mode);


}

