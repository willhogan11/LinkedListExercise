#include <stdlib.h>
#include <stdio.h>

#define MAXLEN 20

struct node
{
	int data;
	char name[MAXLEN + 1];
	struct node *next;

}; // End of struct node

// typedef struct node NEWEMP

// Functions Declaration
int showMenu();
void addToStart (struct node **head);
void addToEnd (struct node *head);
void listNodes (struct node *head);
void displayLength(struct node *head);
void searchList(struct node *head, int num);
void deleteFromEnd(struct node* head);
// void deleteFromStart(struct node  **head);



int main()
{

	int num = 0;
	int iNum = 0;
	int userChoices;

	// Initialising of the data and members. 
	struct node *head = NULL; //  This is a pointer to a struct node called head
	struct node *second = NULL; 
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));

	//head->data = 1;
	head->next = second;

	//second->data = 2;
	second->next = NULL;

	do
	{
		switch( userChoices = showMenu() )
		{
			case 1: 
				{
					addToStart(&head); // &head give me the memory address of head. 
					break;
				}
			case 2:
				{
					addToEnd(head);
					break;	
				}
			case 3: 
				{
					listNodes(head);
					break;
				}
			case 4:
				{
					displayLength(head);
					break;	
				}
			case 5:
				{
					printf("\nEnter data to search: ");
					scanf("%d", &num);
					searchList(head, num);
					system("Pause");
					break;	
				}
			case 6:
				{
					// deleteFromStart(&head);
					break;	
				}
			case 7:
				{
					/*printf("\nEnter a node to delete");
					scanf("%d", &iNum);
					deleteFromEnd(head);
					system("Pause");
					break;	*/
				}
			case 8: 
				{
					exit(0);
					break;
				}
			default:
				{
					printf("\nInvalid Selection");
					break;
				}
		}
	}
	while ( userChoices < 8 );


	system("Pause");
	printf("\n\n\n");

	return(0);

} // End of Main





// Menu to display function
int showMenu()
{
	int userChoices;

	do
	{
		system("cls");

		printf("1. Add a new node to the start of the list\n");
		printf("2. Add a new node to the end of the list\n");
		printf("3. Display all of the nodes in the list\n");
		printf("4. Display the length of the list\n"); // Write a Function for this
		printf("5. Search the linked list for a data value\n");
		printf("6. Delete a Node from the Start of list\n");
		printf("7. Delete a Node from the End of list\n");
		printf("8. Exit\n\n\n\t\tSELECTION = ");

		fflush(stdin);
		scanf("%d", &userChoices);
		fflush(stdin);

	}
	while ( (userChoices < 0) || (userChoices > 8) );
	// End of do While loop

	return( userChoices );

} //  End of showmenu() Function






// * Relates to indirection, passing a copy
// ** Allows us to change the value of what the pointer is pointing to. 

void addToStart (struct node **head)
{
	struct node * newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	
	system("cls");

	printf("\nEnter data for this node");
	fflush(stdin);
	scanf("%d", &newNode->data);

	newNode->next = *head;
	*head = newNode; // This part allows head to be changed. 
	

} //  End of addToStart() Function




void addToEnd(struct node *head)
{
	struct node *temp;
	struct node *newNode;

	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	newNode = (struct node*)malloc(sizeof(struct node));

	system("cls");

	fflush(stdin);
	printf("\nEnter data for this node: ");
	fflush(stdin);
	scanf("%d", &newNode->data);

	printf("\nEnter data a name: ");
	fflush(stdin);
	scanf("%s", &newNode->name);

	newNode->next = NULL;
	temp->next = newNode;
	
	system("Pause");

		} // End of addToEnd function




void listNodes (struct node *head)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	system("cls");

	do
	{
		printf("Data: %d %s\n\n", temp->data, temp->name);
		
	}
	while(temp->next != NULL && (temp = temp->next));

	system("Pause");

} //  End listNodes function




void displayLength(struct node *head)
{
	int length = 0;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));

    
    temp = head;

	while(temp !=NULL)
    {
        length++;
        temp = temp->next;
    }

	system("cls");

	printf("\nLength of Linked List : %d\n\n", length);

	system("Pause");

} //  End of displayLength() function




void searchList(struct node *head, int num)
{
	struct node *temp; 
	temp =(struct node*)malloc(sizeof(struct node));   
	temp = head; 

	// system("cls");
	while( temp != NULL )
	{
		if(temp->data == num) 
		{
			printf("\nData Found is %d and name is %s\n", num, temp->name);
			return;
		} 
		temp = temp->next;
	} 
	printf("\nData not found");
	

} // End of searchList() function




//void deleteFromStart(struct node  **head)
//{
//	struct node *temp;
//	temp = (struct node*)malloc(sizeof(struct node));
//	temp = *head;
//	*head = temp->next;
//	free(temp);
//	
//} // End of deleteFromStart function



// Deletes the last node in the LinkedList
//void deleteFromEnd(struct node* head, int iNum)
//{ 
//	struct node *temp1;
//	struct node *old_temp;
//
//	temp1 = (struct node*)malloc(sizeof(struct node));
//	temp1 = head;
//	
//	old_temp = (struct node*)malloc(sizeof(struct node));
//	
//	while(temp1->next !=NULL)
//	{
//		if(iNum == temp1->data){
//			*(old_temp)->next = *(temp1)->next;
//			//temp1 = NULL;
//			return;
//		}
//		old_temp = temp1;
//		temp1 = temp1->next;
//	}
//	// old_temp->next = NULL;
//
//	free(temp1);
//	
//} // End of deleteFromEnd function