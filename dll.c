#include<stdio.h>
#include<stdlib.h>

struct node{
    char SSN[100];
    char name[100];
    char dept[100];
    char desig[100];
    char sal[100];
    char phno[100];
    struct node *next;
    struct node *prev;
};

struct node *create()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter SSN\n");
    scanf("%s",newnode->SSN);
    printf("Enter name\n");
    scanf("%s",newnode->name);
    printf("Enter dept\n");
    scanf("%s",newnode->dept);
    printf("Enter desig\n");
    scanf("%s",newnode->desig);
    printf("Enter sal\n");
    scanf("%s",newnode->sal);
    printf("Enter phno\n");
    scanf("%s",newnode->phno);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

struct node *insertatfront(struct node *head)
{
    struct node *NODE;
    NODE=create();
    if(head==NULL)
    {
        head=NODE;
        return head;
    }
    else
    {
        NODE->next=head;
        NODE->prev=NULL;
        head->prev=NODE;
        head=NODE;
        return head;
    }
}

struct node *insertatend(struct node *head)
{
    struct node *NODE;
    NODE=create();
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        head=NODE;
        return head;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NODE;
    NODE->next=NULL;
    NODE->prev=temp;
    return head;
}

struct node *deleteatend(struct node *head)
{
    struct node *temp,*p;
    p=temp=head;
    if(head==NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            p=temp;
            temp=temp->next;
        }
        p->next=NULL;
        free(temp);
        return head;
    }
}

struct node *deleteatfront(struct node *head)
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }

    temp=head->next;
    temp->prev=NULL;
    free(head);
    head=temp;
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    int n=1;
    if(head==NULL)
    {
        printf("the list is empty\n");
        return;
    }
    while(temp!=NULL)
    {
            printf("Details of employee %d\n",n);
            printf("SSN:%s\n",temp->SSN);
            printf("name:%s\n",temp->name);
            printf("dept:%s\n",temp->dept);
            printf("designation:%s\n",temp->desig);
            printf("Sal:%s\n",temp->sal);
            printf("Phno:%s\n",temp->phno);
            temp=temp->next;
            n++;
    }
}

void count(struct node *head)
{
    struct node *temp;
    temp=head;
    int c=0;
    if(head==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        printf("The number of nodes is %d",c);

    }
}

int main()
{
    struct node *head=NULL;
    int choice,num,i;
    while(1)
    {
        printf("\n1.create a list of N students\n2.insert at front\n3.Display\n4.Count\n5.insert at end\n6.Delete at end\n7.Deleteatfront\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the number of students\n");
                   scanf("%d",&num);
                   for(i=0;i<num;i++)
                   {
                       head=insertatend(head);
                   }
                   break;

            case 2:head=insertatfront(head);
                   break;

            case 3:display(head);
                   break;

            case 4:count(head);
                   break;

            case 5:head=insertatend(head);
                   break;

            case 6:head=deleteatend(head);
                   break;

            case 7:head=deleteatfront(head);
                   break;
        }
    }
    return 0;
}
