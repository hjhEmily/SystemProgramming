#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word{
 char word[10];
}word;

int F(word *F_w);
void S(word *S_w, char *buf);

void main()
{
 word *m_w=(word *)malloc(sizeof(word));
 if(F(m_w))
  printf("실패");
 else
  printf("성공");
}

int F(word *F_w)
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
  S(F_w,buf);
 }
 return 0;
}

void S(word *S_w,char *buf)
{
 int i=0;//구조체 갯수
 int j;
 char *token;
 token=strtok(buf,"\t");

 if(buf[0]=='.')//.을넣어야함
 {
  sprintf((S_w+i)->word,"%c",'.');
  i++;
 }
 
 //else if(token=="INPUT")//16->10진수로 변환, But char형일것이므로 16진수->10으로가야한다
 //{
 // //숫자를만나면 sprintf( ,"%d", )써서 변환
 //}

 else
 {
  while(token)
  {
   sprintf((S_w+i)->word,"%s",token);
   token=strtok(NULL,"\t,\n'");
   i++;
  }
 }
 for(j=0; j<i; j++)
 printf("%s\n",(S_w+j)->word);
} 
