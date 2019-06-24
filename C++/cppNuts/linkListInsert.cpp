#include <iostream>
#include <stdlib.h>

using namespace std;
struct Node { 
   int data; 
   struct Node *next; 
}; 

struct Node* head = NULL;   
void insert(int new_data) { 
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node; 
} 

void display() { 
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   } 
   cout<<endl;
} 

void Delete(int n){
  struct Node* temp1 = head; 
  if(n==1){
    head = temp1->next;
    free(temp1);
    return;
  } else{
  int i;
  for(i=0;i<n-2;i++)
    temp1=temp1->next;

  struct Node* temp2= temp1->next;
  temp1->next = temp2->next;
  free(temp2);
  }
}
void reverse(){
  Node *current =head;
  Node *prev = NULL,*next = NULL;
  while(current != NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current =next;
  }
  head=prev;
}
int main() { 
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The linked list is: "<<endl;
   display();
   Delete(2); 
   cout<<"The linked list after delete of 2 position is: "<<endl;;
   display();
   reverse();
   cout<<"The linked list after reverse is: ";
   display();
   return 0; 
} 
