#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;

struct node{
  int number;
  struct node *next;
};

struct node* head=NULL; //global
void insert(int data){
  struct node* temp =head;
  temp->number=data;
  temp->next=head;
  head=temp;
  //}else{
  //while(temp->next!=NULL){
  //  temp=temp->next;
  //}
  //temp->number =data;
  //temp->next=NULL;
  //temp=head;
  //}
}
void print();
void Delete(int n){
  struct node* temp1=head;
  int i;
  if(n==1){
    head = temp1->next;
    free(temp1);
    return;
  } else{
  for(i=0;i<n-2;i++){
    temp1=temp1->next;
  }
  struct node* temp2= temp1->next;
  temp1->next = temp2->next;
  free(temp2);
  }
}
 //position


int main(){
 head =NULL;
 insert(2);
 insert(4);
 insert(6);
 insert(5);
 int n;
 cout<<("enter a position");
 cin>>n;
 Delete(n);
 return 0;
}
