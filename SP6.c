#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sp{
 char name[10];//이름
 char instruction[10];//명령어
 char operand[10];//피연산자
}SP;

int File(SP *word);
void Split(SP *S_w, char *buf);
void DotFind(char *buf, SP *word, int i);
//void Store(char *token, char *buf, SP *word, int i);

void main()
{
 SP *word=(SP *)calloc(10,sizeof(SP));//0으로 초기화하면서 10개 정적할당
 if(File(word))
  printf("실패");
 else
  printf("성공");
}

int File(SP *word)//파일열고 Split함수불러오기  
{
 FILE *f1;
 char buf[100];
 f1=fopen("token.txt","r");
 if(f1==NULL) {
  puts("파일오픈 실패");
  return 1;
 }
 while(!feof(f1))
 {
  fgets(buf,sizeof(buf),f1);
  Split(word,buf);
 }
 return 0;
}

void Split(SP *word,char *buf)//한문장 쪼개기  
{
 int i=0;//구조체 갯수
 int j;
 char *token;

 DotFind(buf, word, i);

 //Store(token, buf, word, i);

 token=strtok(buf,"\t");

 //i가문제임

 while(token)
 {
  sprintf((word+i)->name,"%s",token);
  token=strtok(NULL,"\t\n");
  sprintf((word+i)->instruction,"%s",token);
  token=strtok(NULL,"\t\n");
  sprintf((word+i)->operand,"%s",token);
  token=strtok(NULL,"\t\n");
  i++;
  
 }
 for(j=0; j<i; j++)
  printf("%s  %s  %s\n",(word+j)->name, (word+j)->instruction, (word+j)->operand);
}

void DotFind(char *buf, SP *word, int i)//.찾아서 .넣어주는 함수
{
 i=0;
 if(buf[0]=='.')//.을넣어야함
 {
  sprintf((word+i)->name,"%c",'.');
  i++;
 }
}

/*void Store(char *token, char *buf, SP *word, int i)
{
 i=0;

 token=strtok(buf,"\t");
 while(token)
 {
  sprintf((word+i)->name,"%s",token);
  token=strtok(NULL,"\t\n");
  sprintf((word+i)->instruction,"%s",token);
  token=strtok(NULL,"\t\n");
  sprintf((word+i)->operand,"%s",token);
  token=strtok(NULL,"\t\n");
  i++;
  
 }
}*/
 
