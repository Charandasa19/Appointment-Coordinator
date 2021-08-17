#include <iostream>
#include <cstring>
#include <time.h>
#include <ctype.h>

using namespace std;
  
  
 struct Node {
	 int data;
	 char name[50];
     Node* next;
    
};


void append(Node** head , char * name) 
{ 
   
	Node* newNode = new Node();
    strcpy(newNode->name , name);
    newNode->next = NULL;
   
	Node * temp = new Node();
	temp = *head;
   
    if (*head == NULL)
		{
			*head = newNode;
		}
    
	else
		{
				while(temp->next != NULL)
					temp = temp->next;
				temp->next = newNode;
		}
	

} 

void printList(struct Node* node)
{
	Node * temp = new Node();
	temp = node;
	
	int i = 1;
	while(temp!=NULL)
		{
				cout<<endl<<i<<":"<<temp->name;
				i++;
				temp = temp->next;
		}
	
 
    
}


void appendAt(Node** head , int pos ,char * name)
{
		
		
		Node * newNode = new Node();
		strcpy(newNode->name , name);
		
		Node * temp = new Node;
		temp->next = *head;
		
		
		
		if(temp != NULL && pos != 1)
			{
				for(int i = 0 ; i<pos-1 ; i++)
						temp = temp->next;
				
				newNode->next = temp->next;	
				temp->next = newNode;
				
				
				
				
			}
			
		if(temp != NULL && pos == 1)
			{
				
				strcpy(temp->name,name);
				*head = temp;	
				
			}
		
	
}


void deletePos(Node** head , int pos)
{
	Node * temp = new Node();
	temp = *head;
	Node ** n = NULL;

	if(pos == 1)
		{
			temp = temp->next;
			*head = temp;
		}
	else
		{	
			
			for(int i = 0; i<pos-2 ; i++)
				{
					temp = temp->next;	
				}
              
			n = &temp->next;
			temp = temp->next;
			*n = temp->next;
			
			
		}
		
	
}




int main()
{
	 
	int choice = -1 , n = 0,pos;
	char name[50];
	
	Node* head = NULL;
	
	while(choice != 1)
		{			
					
					cout<<endl<<"1.Exit\n2.Add member at the end\n3.Add member at specified position\n4.Remove member from the queue\n5.View queue\n  Your choice : ";
					cin>>choice;
					
					
					switch(choice)
						{
							
								case 1: exit(0);
								
								case 2:	cout<<endl<<"Enter Name :- ";
										cin>>name;
										append(&head ,name);
										n++;
										break;
										
								case 3: pos_error_ins:
										if(n == 0)
											{
												cout<<endl<<"Enter Position(0 < Pos < "<<n+2<<" ) :- ";
												cin>>pos;
										
												if(pos>=n+2 || pos<= 0 )
													goto pos_error_ins;
											}
											
										else
											{
												cout<<endl<<"Enter Position(0 < Pos < "<<n+2<<" ) :- ";
												cin>>pos;
										
												if(pos>=n+2 || pos<= 0 )
													goto pos_error_ins;
											
											}
											
										cout<<endl<<"Enter Name :-";
										cin>>name;
										appendAt(&head,pos,name);
										n++;
										break;
										
								case 4:	pos_error_del:
										cout<<endl<<"Enter Position(0 < Pos < "<<n+1<<" ) :- ";
										cin>>pos;
										if(pos>=n+1 || pos<= 0 )
											goto pos_error_del;
										deletePos(&head , pos);
										n--;
										break;
								
						
											
						
						
						}
					system("clear");
					cout<<endl<<"Your Appointments : ";
					printList(head);
					cout<<endl<<endl<<endl;
				
		}
	
	
	
}
