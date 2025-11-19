#include<iostream>
using namespace std;
   struct node{
        int data;
          node *next;
          node *prev;
   
   };
   node *head=NULL,*tail=NULL;
   void insertend(int x)
   {
   node *temp=new node;
  temp->data=x;
  temp->next=NULL;
  temp->prev=NULL;
   if(head==NULL)
   head=tail=temp;
   else
   {
   tail->next=temp;
   temp->prev=tail;
   tail=temp;
   }
   }
   void insertfront(int x)
   {
   node *temp=new node;
   temp->data=x;
   temp->next=NULL;
   temp->prev=NULL;
   if(head==NULL)
   head=tail=temp;
   else{
   head->prev=temp;
   temp->next=head;
   head=temp;
   }
   
   }
   void insertrightofvalue(int x,int y)
   {
   node *temp=new node;
   temp->data=x;
   temp->next=NULL;
   temp->prev=NULL;
   if(head==NULL)
   head=tail=temp;
  else if(head->data==y) 
  {
  if(head->next==NULL)
  tail=temp;
  temp->prev=head;
  temp->next=head->next;
  head->next->prev=temp;
  head->next=temp;
  }
  else{
  
  node *temp2=head;
  while(temp2->data!=y)
  {
  temp2=temp2->next;
  }
  if(temp2->next==NULL)
  tail=temp;
  temp->prev=temp2;
  temp->next=temp2->next;
  temp2->next->prev=temp;
  temp2->next=temp;
  }
  }
  void insertleftofvalue(int x,int y)
  {
  node *temp=new node;
   temp->data=x;
   temp->next=NULL;
   temp->prev=NULL;
  if(head==NULL)
  head=tail=temp;
  else if(head->data==y)
  {
  temp->next=head;
  head->prev=temp;
  head=temp;
  }
  else{
  node *temp2=head;
  node *temp3;
  while(temp2->data!=y)
  {
  temp3=temp2;
  temp2=temp2->next;
  }
  temp3->next=temp;
  temp->next=temp2;
  temp2->prev=temp;
  temp->prev=temp3;
  }
  }
  void deletefront(){
  if(head==NULL)
  cout << "no data insied anode " << endl;
  else{
 node *temp=head;
 head=head->next;
 head->prev=NULL;
 delete temp;
  
  }
  }
  void deleteend(){
  if(head==NULL)
  cout << "no data inside anode " << endl;
  else{
  node *temp=tail;
  tail=tail->prev;
  tail->next=NULL;
  delete temp;
  }
  
  }
  void deletespecifiedvalue(int y)
  {
  node *temp;
  node *temp2;
  if(head==NULL)
  cout << "no data inside the node " << endl;
  else if(head->data==y)
  {
  if(head->next==NULL)
  tail=tail->prev;
  temp=head;
  head=head->next;
  head->prev=NULL;
  delete temp;
  }
  else{
  temp=head;
  while(temp->data!=y)
  {
  temp2=temp;
  temp=temp->next;
  }
  if(temp->next==NULL)
  tail=tail->prev;
  temp2->next=temp->next;
  temp2->next->prev=temp2;
  delete temp;
  }
  }
   void display()
   {
   node *temp;
   if(head==NULL)
   cout << "nodata inside the list" << endl;
   else 
   {
   temp=head;
   while(temp!=NULL)
   {
   cout<<temp->data<<endl;
   temp=temp->next;
   }
   cout<< endl;
   cout<< endl;
   }
   }
   
   int main()
   {
   
   
   insertend(1);
   insertend(2);
   insertend(3);
   cout<<"after inserting 3 node"<<endl;
   display();
   insertfront(4);
   cout<<"after adding one node in front "<<endl;
   display();
   insertrightofvalue(5,2);
   cout<<"after adding one node in the right of 2"<<endl;
   display();
   insertleftofvalue(6,2);
   cout<<"after adding one node in the left of 2"<<endl;
   display();
   deletefront();
   cout<<"after deleting  one node at front "<<endl;
   display();
   deleteend();
   cout<<"after deleting one node at the end"<<endl;
   display();
   deletespecifiedvalue(2);
   cout<<"after deleting specified node 2"<<endl;
   display();
   
   return 0;
   }