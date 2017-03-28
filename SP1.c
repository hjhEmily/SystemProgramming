#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST "test.txt"

typedef struct store{
 int num;
 char *word;
}Store;

int Test(Store *t_w);
void Split(char *buf);

void main()
{
 int i;
 Store *m_w=(Store*)malloc(sizeof(Store));//r구조체틀만들어주기
 if(Test(m_w))
   printf("test 파일열기가 실패되어 종료합니다\n");
 else
   printf("test 파일을 정상적으로 읽었습니다\n");
 /*for(i=0; i<(m_w->num); i++)
  printf("%s\n", (m_w+i)->word);*/
}

//파일열고 Split함수부르기
int Test(Store *t_w)
{
 FILE *f1;
 char buf[500];//읽어온한줄 저장임시버퍼
  
 f1=fopen(TEST,"r");
 if(f1==NULL) {
  puts("파일오픈 실패");
  return 1;
 }

 //구조체에 넣기
 while(!feof(f1))
 {
  fgets(buf,sizeof(buf),f1);//파일에서 한줄읽어들이기
  Split(buf);//한줄쪼개기
 }
 
 return 0;//true
}

//한줄쪼개고 구조체에 넣기      .이랑 10진수변환 아직안함
void Split(Store *s_w,char *buf)
{
 char *token=strtok(buf,"\t");
 printf("%s\n",token);
 (s_w+(s_w->num))->word=(char *)malloc(sizeof(strlen(token)+1));//한단어길이만큼 공간할당
 (s_w+(s_w->num))->word=(char *)calloc(0,strlen(token)+1);//할당한공간 1로초기화
 sprintf((s_w+(s_w->num))->word,"%s",token);//문자열로 token값을 구조체에 넣어라
 s_w->num++;

 while(token)
 {
  token=strtok(NULL," \t\n,'");
  (s_w+(s_w->num))->word=(char *)malloc(sizeof(strlen(token)+1));//한단어길이만큼 공간할당
  //(s_w+(s_w->num))->word=(char *)calloc(0,strlen(token)+1);//할당한공간 1로초기화    s_w->num때문에 빼줌
  sprintf((s_w+(s_w->num))->word,"%s",token);//문자열로 token값을 구조체에 넣어라
  s_w->num++;
 }
} 

