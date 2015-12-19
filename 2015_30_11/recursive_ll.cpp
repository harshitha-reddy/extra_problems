/*
given a single linked list, write a program to reverse the single linked list.
for example 1->2->3 should be converted to 3->2->1.
please write this program using recursion,without recursion
*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *link;
}nodetype;
void non_recrev();
nodetype* rec_rev(struct node *,struct node *);
nodetype* Create_list(char *);
void display(nodetype *);
void testcases();
struct test
{
	char input[40];
	int output[20];
}test[10]=
		{
			{{"123,456,789"},{789,456,123}},
			{{"456,789,400,500"},{500,400,789,456}},
			{{"348,908,321,100"},{100,321,908,348}},
			{{"1,2,3,4,5,6,7,8,9,10"},{10,9,8,7,6,5,4,3,2,1}},
			{{"67,89,23,45,12,68,90"},{90,68,12,45,23,89,67}},
			{{"0,0,0,0,0,0,0"},{0,0,0,0,0,0,0}}
		};
int main()
{
	testcases();
	getch();
	return 0 ;
}
void testcases()
{
	int lv1,lv2=0;
	for(lv1=0;lv1<6;lv1++)
	{
		nodetype *head,*temp;
		head=Create_list(test[lv1].input);
		head=rec_rev(head,head);
		temp=head;
		lv2=0;
		while(temp)
		{
			if(test[lv1].output[lv2++]==temp->data)
			{
				temp=temp->link;
			}
			else
			{
				printf("test%d is failed",lv1+1);
				return ;
			}
		}
		display(head);
	}
	printf("tests are passed");
	return;

}
nodetype *Create_list(char *input)
{
	int num=0;
	nodetype *head=NULL,*prev,*neew;
	while(*input)
	{
		if(*input!=',')
		{
			num=num*10+(*input-'0');
		}
		else
		{
			neew=(nodetype *)malloc(sizeof(nodetype));
			neew->data=num;
			neew->link=NULL;
			if(head==NULL)
			{
				head=neew;
				prev=head;
			}
			else
			{
				prev->link=neew;
				prev=neew;
			}
			num=0;
		}
		if(*(input+1)=='\0')
		{
			neew=(nodetype *)malloc(sizeof(nodetype));
			neew->data=num;
			neew->link=NULL;
			if(head==NULL)
			{
				head=neew;
				prev=head;
			}
			else
			{
				prev->link=neew;
				prev=neew;
			}
			num=0;
		}
		*input++;
	}
	return head;
}

/*void non_recrev()
{
	struct node *r,*q=NULL,*p=first;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->link;
		q->link=r;
	}
	first=q;
}*/
nodetype* rec_rev(struct node *p,struct node *head)//p=head first time
{

	if(p->link==NULL)
	{
		head=p;
		return head;
	}
	head=rec_rev(p->link,head);
	p->link->link=p;
	p->link=NULL;
	return head;
}
void display(nodetype *head)
{
	while(head)
	{
		printf("%d->",head->data);
		head=head->link;
	}
	printf("NULL");
	printf("\n");
	return;
}

