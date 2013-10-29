#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE  100
#define DATETYPE int

typedef	struct
{
	int size[10];
	int top;
}rode;

typedef	struct 
{
	DATETYPE data[MAXSIZE];
	int top;
}Seqstack;

Seqstack *Init_Seqstack()                    //�ÿ�ջ
{
	Seqstack  *s;
	s =  malloc(sizeof(Seqstack));
	s->top = -1;
	return s;
}

int Empty_Seqstack(Seqstack *s)              //��ջ�� ����գ�����1�����򷵻�0
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

int Push_Seqstack(Seqstack *s, DATETYPE x)                       //��ջ
{
	if(s->top == MAXSIZE - 1)
	{
		printf("the stack is full!\n");
		return 0;
	}
	else
	{
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

int Pop_Seqstack(Seqstack *s,DATETYPE *x)                    //��ջ
{
	if(Empty_Seqstack(s) )
		return 0;
	else
	{
		*x = s->data[s->top];
		s->top--;
		return 1;
	}
}

DATETYPE Top_Seqstack(Seqstack *s)
{
	if(Empty_Seqstack(s))
		return 0;
	else
		return s->data[s->top];
}

int main(void)
{
	Seqstack *s;
	DATETYPE ele;
	DATETYPE *le;

	s = Init_Seqstack();
	while(1)
	{
		scanf_s("%d",&ele);
		if( ele != -1)
			Push_Seqstack( s, ele);
		else
			break;
	}
/*	
	while(1)
	{
		Pop_Seqstack(s,le);
		printf("%d\n",*le);
	}
*/
	printf("%d\n",s->top );
	scanf_s("%d\n",ele);
	return 0;
}