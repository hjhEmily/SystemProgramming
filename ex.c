#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

typedef struct ReadLine {//한줄내용구조체-동적할당
 char symbolic[10];//이름
 char instruction[10];//명령어
 char operand[10];//피연산자
}READLINE;

typedef struct Line {//구조체가리키는 포인터
 int line_count;//문장수세주기
 READLINE *line;//READLINE구조체 주소저장
}LINE;

int File(LINE *line);
void Split(char *buf, LINE *line);

void main()
{
 int i;//출력할때 쓸변수
 LINE *line=(LINE *)calloc(1,sizeof(LINE));//LINE 구조체주소
 line->line=(READLINE *)calloc(1,sizeof(READLINE));//READLINE 구조체주소
 if(File(line))
  printf("파일읽기 실패\n");
 else
  printf("파일읽기 성공\n");
 //for(i=0; i<line->line_count; i++)
  //printf("%s",(line+i)->line->symbolic);
}

int File(LINE *line)
{
 FILE *f1;//읽어들일 파일
 char buf[100];//파일에서 읽어들인 한줄
 f1=fopen("ex.txt","r");
 if(f1==NULL) {
  puts("파일오픈 실패");
 }
 while(!feof(f1))//파일의 마지막 줄읽을때까지 실행
 {
  fgets(buf,sizeof(buf),f1);//파일에서 한줄 읽어들이기
  //fflush(stdin)//버퍼지워주기해야하나??
  if(buf[0]=='.')
  {
   //line->line_count++;
   //(line->line)->symbolic='.';//.넣어주기
  }
  else
  {
   line->line_count++;
   Split(buf,line);//Split 함수불러오기
  }
 }
 return 0;
}

void Split(char *buf, LINE *line)
{
 char *token;//buf에서 한단어 주소
 //token=strtok(NULL,"\t\n,'");
 token=strtok(buf,"\t\n,'");
 //token=strtok(NULL,"\t\n,'");
 line->line=(READLINE *)realloc(line->line,sizeof(READLINE)*(line->line_count+1));
 sprintf((line+(line->line_count))->line->symbolic,"%s",token);
 printf("%s\n",(line+(line->line_count))->line->symbolic);
 
}
 
