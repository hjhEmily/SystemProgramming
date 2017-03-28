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
 //printf("%s",buf);
 char *token=strtok(buf,"\t");
 //sprintf((S_w+i)->word,"%s",token);
 //printf("%s\n",token);
 //i++;
 /*token=strtok(NULL,"\t");
 printf("%s\n",token);
 token=strtok(NULL,"\t");
 printf("%s\n",token);
 token=strtok(NULL,",");
 printf("%s\n",token);*/
 while(token)
 {
  sprintf((S_w+i)->word,"%s",token);
  //printf("%s\n",token);
  sprintf((S_w+i)->word,"%s",token);
  token=strtok(NULL,"\t,\n'");
  //sprintf((S_w+i)->word,"%s",token);
  i++;
  //printf("%s\n",token);
 }
 for(j=0; j<i; j++)
 printf("%s\n",(S_w+j)->word);
} 
