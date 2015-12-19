/*given a single, sorted linked list, find the median of the linked list
 median of 1,2,4,5,6 is 4 becuase that is middle element
 median of 1,2,3,4,5,6 is average of 3,4 becuase length is even
 */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *link;
}nodetype;
nodetype *createlist(char *);
void testcases();
void display(nodetype *);
int Median(nodetype *);
struct test
{
	char input[40];
	int output;
}test[10]=
		{
			{{"123,456,789"},456},
			{{"400,456,789,900"},622},
			{{"321,348,349,908"},348},
			{{"1,2,3,4,5,6,7,8,9,10"},5},
			{{"12,13,14,15,20"},14},
			{{"0,0,0,0,0,0,0"},0}
		};
int main()
{
	testcases();
	getch();
	return 0;
}
void testcases()
{
	int lv1,median=0;
	for(lv1=0;lv1<6;lv1++)
	{
		nodetype *head;
		head=createlist(test[lv1].input);
		median=Median(head);
		if(test[lv1].output==median)
		{}
		else
		{
			printf("test%d is failed",lv1+1);
			return ;
		}
		//display(head);
	}

	printf("tests are passed");
	return ;
}
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

int  Median(nodetype *head)
{
	struct node *one=head,*two=head,*prev=head;
	while(two!=NULL && two->link!=NULL)
	{
		prev=one;
		one=one->link;
		two=two->link->link;
	}
	if(two==NULL)
		return ((one->data + prev->data)/2);
	else
		return one->data;
	return 0;
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
