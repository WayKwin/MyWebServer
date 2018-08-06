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
char* catstr(const char*src,const char*dst)
{
		int len=strlen(src)+2+strlen(dst);
		char *path=malloc(sizeof(len))
		sprintf(path,"%s/%s",dst,src);
		mkdir(path,sbuf_src.st_mode);
		return path;
}
void copy_dir(const char*src,const char*dst)
{
	DIR* dp_src=opendir(src);
	struct dir_src=NULL;
	struct sbuf_src=NULL;
	while((dir_src=readdir(dp_src))!=NULL)
	{
		lstat(src,&sbuf_src);
		if(S_ISREG(sbuf_src.st_mode))
		{
			//拼接目录
			 s_path=catstr(dir_src->d_name,src);
			copy_file(s_path,dst,sbuf_src.st_mode);
		}
		if(S_ISDIR(sbuf_src.st_mode))
		{
			int len=strlen(src)+2+strlen(dst);
			char *d_path=malloc(sizeof(len))
			sprintf(d_path,"%s/%s",dst,src);
			mkdir(d_path,sbuf_src.st_mode);
			copy_dir(src,d_path);
		}
	}
}
int main(int argc,char*argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"./mycp dst src");
	}
	struct stat sbuf_src;
	struct stat sbuf_dst;
	mode_t old=umask(0);
	int flag_src=lstat(argv[1],&sbuf_src);
	int flag_dst=lstat(argv[2].&sbuf_src);
	if(s_isreg(sbuf_src.st_mode))
	{
		if(flag_dst=-1)
		{
			printf("目标不存在.是否创建新文件[y\n]");
			char n;
			sscnaf("%[yynn]",&n);
			if(n=='y' || n =='y')
			{
				copy_file(src,dst,sbuf_src.st_mode);
			}
		}
		if(s_isreg(sbuf_dst.st_mode))
		{
			file_copy(argv[1],argv[2],sbuf_src.st_mode);
		}
		if(s_isdir(sbuf_dst.st_mode))
		{
			int len=strlen(argc[1])+2+strlen(argv[2])
			char *dst_path=(char *)malloc(sizeof(len));
			sprintf(dst_path,"%s/%s",argv[2],argv[1]);
			file_copy(src,dst_path);
			
			// a    c/d
			// a   c/d/a
		}
	}
	if(S_ISDIR(sbuf_src.st_mode))
	{
		if(S_ISREG(sbuf_dst.st_mode))
		{
			fprintf(stderr,"错误\n");
		}
		if(S_ISDIR(sbuf_dst.st_mode))
		{
			
			int len=strlen(argc[1])+2+strlen(argv[2])
			char *dst_path=(char *)malloc(sizeof(len));
			sprintf(dst_path,"%s/%s",argv[2],argv[1]);
			mkdir(dst_path, sbuf_src.st_mode);
			//在dst目录下创建一个src录
			copy_dir(argv[1],dst_path);


		}

	}
}













