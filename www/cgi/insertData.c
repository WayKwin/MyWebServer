#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include"mysql-connector-c/include/mysql.h"
void insert_data(char* name,char*sex,char*age,char* telphone)
{
  MYSQL* mysql_fd = mysql_init(NULL);
  if(mysql_real_connect(mysql_fd,"127.0.0.1","root","","people",3306,NULL,0) == NULL)
  {
    printf("connect mysql error!\n");
    goto out;
  }
  /*printf("connect mysql success!\n");*/

  char sql[1024];

  sprintf(sql,"INSERT INTO people_info (name,sex,brithday,telphone) VALUES (\"%s\",\"%s\",\"%s\",\"%s\")",name,sex,age,telphone);
  printf("%s",sql);
 if( mysql_query(mysql_fd,sql)!=  0)
 {
   printf("%d:%s\n",mysql_errno(mysql_fd),mysql_error(mysql_fd));
 }
out:
  //mysql_free_result(result);
  mysql_close(mysql_fd);
  mysql_library_end();
}
void dealMsg(char* info)
{
    char* name = NULL;
    char* sex = NULL;
    char* age = NULL;
    char* tel = NULL;
    strtok(info,"=&");
    name = strtok(NULL,"=&");

    strtok(NULL,"=&");
    sex= strtok(NULL,"=&");

    strtok(NULL,"=&");
    age= strtok(NULL,"=&");

    strtok(NULL,"=&");
    tel= strtok(NULL,"=&");
    insert_data(name,sex,age,tel);

}
int main()
{
  /*char info[1024] = "name=Jack&sex=male&age=1990-1-1&telphone=12345678901";*/
    /*[>strcpy(info,getenv("QUERY_STRING"));<]*/
    /*char* name = strtok(info,"=");*/

  //name=Jack&sex=male&age=1990-1-1&telphone=12345678901
  /*printf("im child process\n");*/
  char* method =  getenv("METHOD");
  char  info[1024];
  info[0] = 0;
  if(strcmp(method,"GET") == 0)
  {
    /*printf("GET: got QUERY_STRING:%s\n",getenv("QUERY_STRING"));*/
    strcpy(info,getenv("QUERY_STRING"));
  }
  else if(strcmp(method,"POST") == 0)
  {
    //读取长度
    /*char* content_length = getenv("CONTENT_LENGTH");*/
    int ret = read(0,info,sizeof(info) -1); 
    printf("POST: got info:%s\n",getenv("QUERY_STRING"));
    info[ret] = 0;
  }
  dealMsg(info);
  return 0;
}

