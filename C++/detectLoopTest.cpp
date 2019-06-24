#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};
//struct Node *head = NULL;
struct Node *newNode(int data){
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data= data;
  temp->next = NULL;
  return temp;
}
void display(struct Node *head){
  struct Node *temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
void countLoopNodes(struct Node *slow){
  int count = 1;
  struct Node *temp = slow;
  while(temp->next!=slow){
    count++;
    temp= temp->next;
  }
  cout<< "Total node count of the loop is : "<<count<<endl;
    
}
void detectLoop(struct Node *head){
  struct Node *slow = head;
  struct Node *fast = head;
  while(slow && fast && fast->next) {
    slow = slow->next;
    fast= fast->next->next;
    if(slow == fast){
      countLoopNodes(slow);
      slow->next= NULL;
      break;
    }

  }
}
void printReverse(Node* head){
  if(head == NULL)
    return;
  printReverse(head->next);
  cout << head->data << " "; 
}
int main(){
  struct Node *head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);
  head->next->next->next->next->next = head->next;
  detectLoop(head);
  cout<<"After remove the loop:"<<endl;
  display(head);
  cout<<"\nReverse of the loop:"<<endl;
  printReverse(head);
  cout<<endl;
  
}
