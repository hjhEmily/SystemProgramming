#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Line{//단어저장구조체
 int num;
 char word[10];
}LINE;

int File(LINE *word);//파일열고 한줄씩 읽어주는 함수
void Split(LINE *word,char *buf,FILE *out);//한줄 쪼개주는 함수

void main()
{
 int i;
 LINE *word=(LINE *)malloc(sizeof(LINE)*25);
 if(File(word))//파일열기 실패했을때
  printf("실패\n");
 else//파일열기 성공했을때
 {
  //printf("성공\n");
  for(i=0; i<word->num; i++)
   printf("%s\n",(word+i)->word);
 }
 
}

int File(LINE *word)
{
 FILE *f1, *out;
 char buf[80];
 f1=fopen("test.asm.txt","r");
 if(f1==NULL) {
  puts("파일오픈 실패");
  return 1;
 }
 while(!feof(f1))//파일존재하면 실행
 {
  fgets(buf,sizeof(buf),f1);//한줄읽어주기
  out=fopen("output.txt","w");//파일을 텍스트쓰기모드로 엽니다.
  if(buf[0]=='.') 
  {
   word->num=0;
   strcpy((word+(word->num))->word,".");
   //printf("%s\n",(word+(word->num))->word);
   fprintf(out,"%s\n",(word+(word->num))->word);
   word->num++;
  }
  else 
   Split(word,buf,out);
  //fclose(out);//파일을 닫습니다.
 }
 fclose(out);//파일을 닫습니다.
 return 0;
}

void Split(LINE *word, char *buf, FILE *out)
{
 char *token;
 token=strtok(buf,"\t");
 while(token)//token이 존재하면 실행
 {
  sprintf((word+(word->num))->word,"%s",token);
  if(token=="11")//17로변환
  {
   sscanf();
   //sprintf((word+(word->num))->word,"%s","17");
  }
  else
  {
   fprintf(out,"%s\n",(word+(word->num))->word);
   token=strtok(NULL,"\t,\n'");
  } 
  word->num++;
 }
} 
