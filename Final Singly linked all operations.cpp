/*This is a simulation to singly linked list and all the operations on it
NAME:M.Mudasir.war
Reg.no:715520104030
2nd year cse
*/





#include <stdio.h>
#include <stdlib.h>
void creation();
void display();
void insertion();
void deletion();
void search();
void append();
void locate();
int len();
void value();
void update();
int a;
struct node
{
	int data;
	struct node *link;
};
struct node *head=0,*temp,*new_node;
int main()
{
	int choice=0,thi=1;
	printf("This is a simulation to Singly linked list and its operations:\n");
	while(thi==1){
	printf("Press 1 for creation\nPress 2 for Insertion\nPress 3 for Deletion\nPress 4 for Display\nPress 5 for Search\nPress 6 for Retrieve\nPress 7 for Locatte\nPress 8 for update\nPress 9 for Append\nPress 10 to exit:\n");
	printf("Enter your choice:	");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			creation();
			break;
		case 2:
			insertion();
			break;
		case 3:
			deletion();
			break;
		case 4:
			display();
			break;
		case 5:
			search();
			break;
		case 6:
			value();
		case 7:
			locate();
			break;
		case 8:
			update();
			break;
		case 9:
			append();
			break;
		case 10:
			exit(1);
		case 11:
			a=len();
			printf("The length of the list is = %d",a);
			break;
		default:
			printf("Please enter a valid command:\n");
			
	}
}
}
void creation(void)
{
int cre=1;
while(cre==1){
new_node=(struct node*)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d",&new_node->data);
new_node->link=0;
if(head==0)
{
	head=new_node;
	temp=new_node;
}
else
{
	temp->link=new_node;
	temp=temp->link;
}
printf("Press 1 to continue and 0 to discontinue:   ");
scanf("%d",&cre);
}
}



void display(void)
{
	temp=head;
	while(temp!=0)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}

void insertion(void)
{
	int position,insert=1;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data field for the node:\n");
	scanf("%d",&new_node->data);
	new_node->link=0;
	printf("Enter which position you want to insert a node:\n");
	scanf("%d",&position);
	if(position==0)
	{
		new_node->link=head;
		head=new_node;
	}
	else
 	{
	 temp=head;
	 while(insert!=position)
	 {
	     //printf("Hello testing:\n");
	     temp=temp->link;
	     insert++;
	 }
	 new_node->link=temp->link;
	 temp->link=new_node;
	 
	 }
}

void deletion(void)
{
	int loc;
	printf("Enter the location you want to delete:\n");
	scanf("%d",&loc);
//	if(loc>length())
//	{
	//	printf("Invalid location:\n");
//	}
     if(loc==1)
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
void search(void)
{
    int num,iter=0,n=0;
    printf("Enter the number you want to search for:    ");
    scanf("%d",&num);
    a=len();
    //printf("%d",a);
    temp=head;
    while(iter!=a)
    {
        if(temp->data==num)
        {
            printf("The number is present:\n");
            temp=temp->link;
        }
        else
        {
            temp=temp->link;
            n++;
        }
        
        //printf("Hello:\n");
        iter++;
    }
    //printf("The number is not present:\n");
    if(n==a)
    {
        printf("The number is not present:\n");
    }
}
int len(void)
{
	int length;
	temp=head;
	while(temp!=0)
	{
		length++;
		temp=temp->link;
	}
	//printf("The length of the linked list is %d",length);
	return length;
}

void append(void)
{
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data field:   ");
	scanf("%d",&new_node->data);
	new_node->link=0;
	temp=head;
	while(temp->link!=0)
	{
		temp=temp->link;
	}
	temp->link=new_node;
	
}


void locate(void)
{
    int num,iter=0,n=0;
    printf("Enter the number you want to find the location :    ");
    scanf("%d",&num);
    a=len();
    //printf("%d",a);
    temp=head;
    while(iter!=a)
    {
        if(temp->data==num)
        {
            printf("The location of the number is = %d",iter+1);
            temp=temp->link;
        }
        else
        {
            temp=temp->link;
            n++;
        }
        
        //printf("Hello:\n");
        iter++;
    }
    //printf("The number is not present:\n");
    if(n==a)
    {
        printf("The number is not present:\n");
    }
}

void value(void)
{
	int num,cox,iter=1;
	printf("Enter the location you want to print:\n");
	scanf("%d",&num);
	cox=len();
	temp=head;
	if(num>cox)
	{
		printf("Please enter a valid location:\n");
	}
	else
	{
		while(iter!=num)
		{
			temp=temp->link;
			iter++;
		}
		printf("%d",temp->data);
	}
}
void update(void)
{
	int update,pos,iter=1;
	printf("Enter the position where you want to update:	");
	scanf("%d",&pos);
	if(pos>len())
	{
		printf("Out of bounds:\n");
		
	}
	else{
		temp=head;
	while(iter!=pos)
	{
		temp=temp->link;
		iter++;
	}
	printf("Enter the data field to be updated:	");
	scanf("%d",&update);
	temp->data=update;
}
}

