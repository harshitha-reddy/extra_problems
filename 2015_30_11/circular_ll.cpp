/*given a single, sorted, circular linked list and a value,
insert the value as a new node at the appropriate location (to keep the linked list sorted).
example 1->2->4->1 and value 3 output shoudl be 1->2->3->4->1*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *link;
}nodetype;
nodetype *createlist(char *);
nodetype *insert(nodetype *,int);
//void testcases();
void display(nodetype *);
struct test
{
	char input[40];
	int element;
	int output[20];
}test[10]=
		{
			{{"123,456,789"},900,{123,456,789,900}},
			{{"400,456,789,900"},0,{0,400,456,789,900}},
			{{"321,348,349,908"},349,{321,348,349,349,908}},
			{{"1,2,3,4,5,6,7,8,9,10"},5,{1,2,3,4,5,5,6,7,8,9,10}},
			{{"12,13,14,15,20"},19,{12,13,14,15,19,20}},
			{{"0,0,0,0,0,0,0"},0,{0,0,0,0,0,0,0,0}}
		};
int main()
{
	testcases();
	getch();
	return 0 ;
}
/*void testcases()
{
	int lv1,lv2=0;
	for(lv1=0;lv1<6;lv1++)
	{
		nodetype *head,*temp;
		head=createlist(test[lv1].input);
		head=insert(head,test[lv1].element);
		lv2=0;
		if(test[lv1].output[lv2++]==head->data)
		{
			temp=head->link;
			while(temp!=head)
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
		}
		else
		{
			printf("test%d is failed",lv1+1);
			return ;
		}
		display(head);
	}
	printf("tests are passed");
	return ;
}*/
nodetype *createlist(char *input)
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
			neew->link=head;
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
nodetype *insert(nodetype *first,int element)
{
	struct node * new1,*temp=first->link,*prev=first,*last=NULL;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=element;
	if(element < first->data)
	{
		while(temp!=first)
		{
			if(temp->link == first)
				last=temp;
			temp=temp->link;
		}
		 new1->link=first;
		 last->link=new1;
		 first=new1;
		 return first;
	}
	temp=first->link;
	while(temp!=first)
	{
			if(element<=temp->data)
			{
				prev->link=new1;
				new1->link=temp;
				return first;
			}
			prev=temp;
			temp=temp->link;
	}
	prev->link=new1;
	new1->link=first;
	return first;
}
void display(nodetype *head)
{
	nodetype *temp=head->link;
	printf("%d->",head->data);
	while(temp!=head)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("NULL");
	printf("\n");
	return;
}
