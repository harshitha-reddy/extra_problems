/*given two sorted linked lists,
merge them into single sorted linked list using same nodes of bboth the lists. */
/*
given two sorted linked lists, write a function to merge the two linked lists to one sorted linked list
*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *link;
}nodetype;
nodetype *Create_list(char *);
nodetype *merge_lists(nodetype *,nodetype *);
void testcases();
void display(nodetype *);
struct test
{
	char input1[40];
	char input2[40];
	int output[20];
}test[10]=
		{
			{{"123,456,789"},{"00,11,22"},{00,11,22,123,456,789}},
			{{"121,767"},{"400,456,700,900"},{121,400,456,700,767,900}},
			{{"348,448,908"},{"1,2,3,4"},{1,2,3,4,348,448,908}},
			{{"1,2,3,4,5,6,7,8,9,10"},{"34,44"},{1,2,3,4,5,6,7,8,9,10,34,44}},
			{{"12,33,44"},{"12,52,82,92"},{12,12,33,44,52,82,92}},
			{{""},{""},{}},
			{{NULL},{NULL},{NULL}},
			{{"0,0,0,0,0,0,0"},{"12,72"},{0,0,0,0,0,0,0,12,72}}
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
	nodetype *head1,*head2,*temp,*head;
	for(lv1=0;lv1<10;lv1++)
	{
		head1=Create_list(test[lv1].input1);
		head2=Create_list(test[lv1].input2);
		head=merge_lists(head1,head2);
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
nodetype *merge_lists(nodetype *head1, nodetype *head2)
{
    nodetype *result=NULL;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    if(head1->data<=head2->data)
	{
        result=head1;
        result->link=merge_lists(head1->link, head2);
	}
    else
	{
        result=head2;
        result->link=merge_lists(head1,head2->link);
	}
    return result;
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

