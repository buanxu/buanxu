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
       printf("存储分配失败");
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
             printf("存储分配失败");
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
             printf("栈是空的");
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
      printf("输入栈中的元素：\n");
	  scanf("%d",&e);
	  while(e!=flag)
	  {
		  push(&s,e);
		  scanf("%d",&e);
	  }
	  printf("栈中元素为：\n");
	  printstack(s);
      printf("栈的长度为：%d\n", stacklength(&s));
	  printf("\n");
     
	  printf("栈顶元素为:  \n");
      Gettop(&s,&e);
	  printf("%d\n",e);
	  printf("\n");

      for(i=1;i<=5;i++)
	  {
		  pop(&s,&e);
         printf("第%d次出栈的元素为：%d\n",i,e);

		 
	  }
	  printf("弹栈后栈中剩余元素为:\n");
	  printstack(s);
	  printf("弹栈后栈的长度为：%d\n\n\n", stacklength(&s));
	  
	  
	  printf("将栈中剩余元素全部弹出\n");
	  i=1;
	  while(s.top!=s.base)
	  {
	    pop(&s,&e);
		printf("第%d次出栈的元素为：%d\n",i,e);
		i++;
	  }
	  printf("弹栈后栈的长度为：%d\n", stacklength(&s));


}