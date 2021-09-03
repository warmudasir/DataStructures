#include <stdio.h>
#include <stdlib.h>
void Append();
void display();
void insertionb();
void insertionl();
int length();
void deletef();
int len;
struct node
{
    int data;
    struct node *link;
};
struct node *head=0;
int main()
{
    int choice;
    while(1){
    printf("1.Append\n2.display\n3.insertionb\n4.Insertionl\n5.Length\n6.Deletef\n7.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: Append();
            break;
        case 2: display();
            break;
        case 3: insertionb();
        	break;
        case 4: insertionl();
        	break;
        case 5: len=length();
        	printf("The length of the linked list is=%d\n",len);
        	break;
        case 6: deletef();
        	break;
        case 7: exit(1);
        
        
        default :printf("Invalid command:\n");
    }
}
}

void Append()
{
    struct node *fresh_node;
    fresh_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter any integer data:\n");
    scanf("%d",&fresh_node->data);
    fresh_node->link=0;
    if(head==0)
    {
        head=fresh_node;
    }
    else
    {
        struct node *p;
        p=head;
        while(p->link!=0)
        {
            p=p->link;
        
    }
    p->link=fresh_node;
    }
}

void display()
{
    struct node *disp;
    disp=head;
    if(head==0)
    {
    	printf("The list is Empty:\n");
	}
	else{
    while(disp!=0)
    {
        printf("%d\n",disp->data);
        disp=disp->link;
    }
}
}
void insertionb()
{
	int position;
	struct node *insert,*insertion=head;
	insert=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data you want to insert:\n");
	scanf("%d",&insert->data);
	insert->link=0;
//	printf("Enter the Node value where you want to insert the node:\n");
//	scanf("%d",&position);
//	if(insertion->data==position)
//	{
//		
//	}
	insert->link=head;
	head=insert;

	
	
	
}
void insertionl()
{
	struct node *lnode,*iter=head;
	lnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data field\n");
	scanf("%d",&lnode->data);
	lnode->link=0;
	while(iter!=0)
	{
		iter=iter->link;
	}
	iter->link=lnode;
	
}

int length()
{
	int count=0;
	struct node *len=head;
	while(len!=0)
	{
		count++;
		len=len->link;
	}
//	printf("The length of the linked list is=%d\n",count);
	return count;
}
//void deletef()
//{
//	struct node*del;
//	del=head->link;
//	head=del;
//}

void deletef()
{
	int loc;
	printf("Enter the location you want to delete:\n");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("Invalid location:\n");
	}
	else if(loc==1)
	{
	struct node*del,*tem;
	tem=head;
	del=tem->link;
	head=del;
	tem->link=NULL;
	free(tem);
}
	else
	{
		int i=1;
		struct node *prep=head,*post;
		while(i<loc-1)
		{
			prep=prep->link;
			i++;
		}
		post=prep->link;
		prep->link=post->link;
		post->link=NULL;
		free(post);
		
		
	}
	
		
}
