#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define INCREASESIZE 10
typedef struct
{
        int  *top;
        int  *base;
        int  stacksize;
}sqstack;

int Initstack(sqstack *s)
{
    s->base=(int *)malloc(sizeof(int)*MAXSIZE);
    if(!s->base)  
    {
       printf("�洢����ʧ��");
       exit(-1);
    }
   s->top=s->base;
   s->stacksize= MAXSIZE;
   return  OK;
}

int    push(sqstack *s,int e)
{  
      if(s->top-s->base==MAXSIZE)
      {
         s->base=(int *)realloc(s->base,(INCREASESIZE+MAXSIZE)*sizeof(int));
         if(!s->base)
         {
             printf("�洢����ʧ��");
             exit(-1);
             s->top=s->base+s->stacksize;
             s->stacksize+=INCREASESIZE;
         }
	  }
	  
      *(s->top)++=e;
      return  OK;
	  
	 

}
int    pop(sqstack *s,int *e)
{  
         if(s->top==s->base)
         {
             printf("ջ�ǿյ�");
             return ERROR;
         }
         s->top--;
         *e=*s->top;
         return  OK;
}

void    printstack(sqstack s)
{        
       
        int *p=s.top;
		while(p>s.base)
		{
		 p--;
         printf("%d  ",*p);
		
         
		}
         
         printf("\n");
}
int Gettop(sqstack *s,int  *e)
{
         if( s->top==s->base)    return  ERROR;
         s->top--;
         *e=*s->top;
         return   OK;
}

int   stacklength(sqstack  *s)
{
        if( s->top==s->base)    return  ERROR;
        else         return  (s->top-s->base);
} 

void main()
{
	  sqstack  s;
	  int i,n,e,flag=-1;
	  Initstack(&s);
      printf("����ջ�е�Ԫ�أ�\n");
	  scanf("%d",&e);
	  while(e!=flag)
	  {
		  push(&s,e);
		  scanf("%d",&e);
	  }
	  printf("ջ��Ԫ��Ϊ��\n");
	  printstack(s);
      printf("ջ�ĳ���Ϊ��%d\n", stacklength(&s));
	  printf("\n");
     
	  printf("ջ��Ԫ��Ϊ:  \n");
      Gettop(&s,&e);
	  printf("%d\n",e);
	  printf("\n");

      for(i=1;i<=5;i++)
	  {
		  pop(&s,&e);
         printf("��%d�γ�ջ��Ԫ��Ϊ��%d\n",i,e);

		 
	  }
	  printf("��ջ��ջ��ʣ��Ԫ��Ϊ:\n");
	  printstack(s);
	  printf("��ջ��ջ�ĳ���Ϊ��%d\n\n\n", stacklength(&s));
	  
	  
	  printf("��ջ��ʣ��Ԫ��ȫ������\n");
	  i=1;
	  while(s.top!=s.base)
	  {
	    pop(&s,&e);
		printf("��%d�γ�ջ��Ԫ��Ϊ��%d\n",i,e);
		i++;
	  }
	  printf("��ջ��ջ�ĳ���Ϊ��%d\n", stacklength(&s));


}