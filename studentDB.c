#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
	char name[40];
    int matricule;
    char phone[10];
    struct Student *next;
    
} *head;
void insert ( char* name, int matricule, char* phone) {
	struct Student *student=(struct Student*) malloc(sizeof(struct Student));
    strcpy(student->name, name);
    student->matricule = matricule;
    strcpy(student->phone, phone);
    student->next = NULL;
    
    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else{
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    
}
void search(int matricule)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->matricule==matricule){
            printf("matricule: %s\n", temp->matricule);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Student with matricule number %d is not found !!!\n", matricule);
}

void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
        
        printf("Matricule Number: %d\n", temp->matricule);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        temp = temp->next; 
		}
	}
int main()
{
    head = NULL;
    int choice;
    char name[20];
    char phone[15];
    int matricule;
    printf("*****WELCOME TO STUDENTS MANAGEMENT DATABASE SYSTEM*****\n");
    printf("1 To insert student details\n2 To search for student details\n3 To display all student details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter matricule: ");
                scanf("%d", &matricule);
                printf("Enter name and Phone number: ");
                scanf("%s", name);
                //printf("Enter phone number: ");
                scanf("%s", phone);
                insert (name, matricule,phone);
                break;
            case 2:
                printf("Enter matricule to search: ");
                scanf("%d", &matricule);
                search(matricule);
                break;
            
            case 3:
                display();
                break;
        }
        
    } while (choice != 0);
}
     
     
     
     
     
     