#include<stdio.h>
#include<stdlib.h>
struct animal_management
{
    int serial_No;
    char name[40];
    char colour[40];
    char sex[40];
    double breed;
    struct animal_management *link;

};
struct animal_management *head=NULL;
struct animal_management *ptr=NULL;
struct animal_management *tail=NULL;
struct animal_management *Node=NULL;
struct animal_management *prev=NULL;
void create_node(int value,char animal_name[40],char animal_colour[40],char animal_sex[40],double animal_breed)
{
    Node=(struct animal_management*)malloc(sizeof(struct animal_management));
    Node->serial_No=value;
    strcpy(Node->name,animal_name);
    strcpy(Node->colour,animal_colour);
    strcpy(Node->sex,animal_sex);
    Node->breed=animal_breed;
    Node->link=NULL;
    if(head==NULL)
        head=tail=Node;
    else
        tail->link=Node;
    tail=Node;

}


void display(struct animal_management*ptr)
{
    ptr=head;
    int n=1;
    while(ptr!=NULL)
    {
        printf("\n Serial No of animal .%d.  Animal name:%s   Animal colour:%s  Animal sex:%s",n,ptr->name,ptr->colour,ptr->sex);
        printf("\n Per year animal breeding frequency:%lf\n\n",ptr->breed);
        ptr=ptr->link;
        n++;
    }
}
void searchNode(char d[40])
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->name,d)==0)
        {
            printf("\n Item Found \n");
            break;
        }
        else
        {
            ptr=ptr->link;
        }
    }
    if(ptr==NULL)
    {
        printf("\n Item not Found\n");
    }
    printf("\n Search completed.operation proceed\n");
}


void insert_node(char new_animal_name[40],char new_animal_colour[40],char new_animal_sex[40],double new_animal_breed)
{
    struct animal_management *New=(struct animal_management*)malloc(sizeof(struct animal_management));
    strcpy(New->name,new_animal_name);
    strcpy(New->colour,new_animal_colour);
    strcpy(New->sex,new_animal_sex);
    New->breed=new_animal_breed;
    New->link=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        prev=ptr;
        ptr=ptr->link;
    }
    if(ptr==NULL)
    {
        prev->link=New;
    }
}
void deletenode(char f[40])
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->name,f)==0)
        {
            printf("\n Item found and deletion is progress \n");
            if(prev!=NULL)
                prev->link=ptr->link;
            else
                head=ptr->link;
            break;
        }
        else
        {
            prev=ptr;
            ptr=ptr->link;
        }
    }
}
void update( char aniN[40])
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->name,aniN)==0)
        {
            break;

        }
        else
            ptr=ptr->link;
    }
    printf("Please update %s Animal Color: ",aniN);
    scanf("%s",ptr->colour);
    printf("Please update %s Animal sex: ",aniN);
    scanf("%s",ptr->sex);
    printf("Please update %s breeding frequency per year: ",aniN);
    scanf("%lf",&ptr->breed);
}



void display_Title()
{
    system("cls");
    printf("\n\t\t\t\tAnimal Management System\n");
    printf("\n\tAbout Project : Using this program we can Insert,Display,Delete ,Update and known about the breeding frequency per year for animal\n");
    printf("\nUser MENU\n");

    printf("\nPress 1 to Insert.\n");
    printf("\nPress 2 to Display.\n");
    printf("\nPress 3 to Delete.\n");
    printf("\nPress 4 to Update.\n");
    printf("\nPress 5 to Search.\n");
    printf("\nPress 6 to Exit.\n");
}

void waiting()
{
    int i;
    for(i=0; i<1000000000; i=i+2)
    {
        if(i%100000000==0)
        {
            printf(".");
        }
    }
}


int main()
{
    char A_name[20][10]= {"Tiger","Lion","Elephant","Fox","Donkey","Monkey","Horse","Goat","Rabbit","Cow || cow"};
    char A_colour[20][50]= {"Orange/Yellow","Yellow/Orange","Brown/Gray","Black/White/Brown/Gray","Black/White/Brown","Brown","Gray/Brown/White/Black","Black/White","Gray/Brown/White/Black","Gray/Brown/White/Black"};
    char A_sex[30][20]= {"Male/Female","Male/Female","Male/Female","Male/Female","Male/Female","Male/Female","Male/Female","Male/Female","Male/Female","Male/Female"};
    double A_bfc[20]= {1,2,3,4,5,6,7,8,9,9};
    int i,j=1;
    for(i=0; i<10; i++)
    {
        create_node(j,A_name[i],A_colour[i],A_sex[i],A_bfc[i]);
        j++;
        display(ptr);
    }

    int new;
    display_Title();
    do
    {
        scanf("%d", &new);
        display_Title();
        switch(new)
        {
        case 1:
            printf("\nYou have pressed 1. Insert..\n");

            char a[40],b[40],c[40];
            double d;
            printf("Animal's Name: ");
            scanf("%s",a);
            printf("Animal's color: ");
            scanf("%s",b);
            printf("Animal's sex: ");
            scanf("%s",c);
            printf("Animal breeding's frequency per year: ");
            scanf("%lf",&d);
            printf("\n\n\t\tInsertion is under process....\n\n");
            waiting();
            insert_node(a,b,c,d);
            printf("\n\n New animal information your updated list is.... \n");
            display(ptr);
            printf("\nInsertion Completed. Proceed to operation\n");
            break;


        case 2:
            printf("\nYou have pressed 2. Displaying is under process....\n");

            waiting();
            display(ptr);
            printf("\nDisplaying Completed. Proceed to operation\n");
            break;



        case 3:
            printf("\nYou have pressed 3. Delete...\n");

            char e[40];
            printf("Animal Name: ");
            scanf("%s",e);
            deletenode(e);
            printf("\nAfter deletion New your expecting updating list is...... \n");
            printf("\nDeletion is under process....");
            waiting();
            display(ptr);
            printf("\nDeletion Completed. Proceed to operation\n");
            break;



        case 4:
            printf("Please enter here the name of animal to update it's information: ");
            char f[40];
            scanf("%s",&f);
            update(f);
            printf("\nAfter updating your expected animal information the list is in bellow: \n");
            waiting();
            display(ptr);
            break;



        case 5:
            printf("\nYou have pressed 5. Search...\n");
            char g[40];
            printf("Animal Name: ");
            scanf("%s",g);
            printf("\nSearching is under process....");
            waiting();
            searchNode(g);
            break;


        case 6:

            break;
        }
    }
    while(new!= 6);
    return 0;
}


