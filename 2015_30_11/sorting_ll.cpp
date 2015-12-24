/*given an unsorted linked list as input, sort the linked list. dont use values to move, use pointers to make it sorted
*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void testcases();
typedef struct node
{
	int data;
	struct node * link;
}nodetype;
nodetype* Create_list(char *);
nodetype* Sort_list(nodetype *);
void display(nodetype *);
struct test
{
	char input[40];
	int output[20];
}test[10]=
		{
            {{"123,789,456"},{123,456,789}},
			{{"4,2,1,5,3"},{1,2,3,4,5}},
			{{"1"},{1}},
			{{"1,2,3,4"},{1,2,3,4}},
			{{"67,89,23,45,12,68,90"},{12,23,45,67,68,89,90}},
			{{""},{}},

			{{NULL},{NULL}},
			{{"4,3,1,2,5"},{1,2,3,4,5}}
		};

int main()
{
    //nodetype *head;
	testcases();
	getch();
	return 0 ;
}
void testcases()
{
	int lv1,lv2=0;
	nodetype *head,*temp;
	for(lv1=0;lv1<10;lv1++)
	{
		head=Create_list(test[lv1].input);
		head=Sort_list(head);
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
nodetype* Sort_list(nodetype *head)
{
	if(head == NULL || head->link == NULL)
		 return head;
	nodetype  *curr, *largest,*largestPrev,*prev,*temp;
	curr = head;
	largest = head;
	prev = head;
	largestPrev = head;
	while(curr != NULL)
	{
        if(curr->data < largest->data)
		{
            largestPrev = prev;
            largest = curr;
        }
        prev = curr;
        curr = curr->link;

	}

	nodetype *tmp;
	if(largest != head)
	{
		 largestPrev->link = head;
		 tmp = head->link;
		 head->link = largest->link;
		 largest->link = tmp;
	}


	largest->link = Sort_list(largest->link);
	return largest;
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
