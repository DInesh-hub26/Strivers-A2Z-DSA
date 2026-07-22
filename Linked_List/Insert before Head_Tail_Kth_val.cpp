#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
int data;
Node* back;
Node* next;

Node(int data_1,Node* prev,Node* front){
    data=data_1;
    back=prev;
    next=front;
}
};

Node* Convert_A_DLL(vector<int>&arr){
    if(arr.size()==0){
      return nullptr;
    }
    Node* Head=new Node(arr[0],nullptr,nullptr);
    Node* prev=Head;
    for(int i=1;i<arr.size();i++){
        Node* Temp=new Node(arr[i],prev,nullptr);
        prev->next=Temp;
        prev=Temp;
    }
    return Head;
}
//......Insert before Head

Node* Insert_before_Head(Node* Head,int val){
  if(Head==nullptr){
    return new Node(val,nullptr,nullptr);
  }
  Node* Temp=new Node(val,nullptr,Head);
  Head->back=Temp;
  return Temp;
}

//......Insert before Tail
Node* Insert_before_Tail(Node* Head,int val){
  if(Head==nullptr){
    return new Node(val,nullptr,nullptr);
  }
  if(Head->next==nullptr){
    return Insert_before_Head(Head,val);
  }
  Node* before=Head;
  while(before->next->next!=nullptr){
    before=before->next;
  }
  Node* front=before->next;
  Node* fake=new Node(val,before,front);
  before->next=fake;
  front->back=fake;
  return Head;
}

//......Insert before Kth
Node* Insert_before_Kth(Node* Head,int k,int val,int n){
 if(k==1){
   return Insert_before_Head(Head,val);
 }
 if(k==n){
  return Insert_before_Tail(Head,val);
 }
 Node* temp=Head;
 int count=0;
 while(temp->next!=nullptr){
   count++;
   if(count==k){
    break;
   }
   temp=temp->next;
 }
 Node* front=temp;
 Node* before=temp->back;
 Node* fake=new Node(val,before,front);
 before->next=fake;
 front->back=fake;
 return Head;
}

//......Insert before Node

Node* Insert_before_Node(Node* Head,int val,int node){
   //Given Node is not head because we need to change head again
   Node* temp=Head;
   while(temp->data!=node){
    temp=temp->next;
   }
   Node* front=temp;
   Node* before=temp->back;
   Node* fake=new Node(val,before,front);
   before->next=fake;
   front->back=fake;
   return Head;
}

void Print_DLL(Node* Head){
  Node* temp=Head;
  while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
int main(){
    int n;
    cin>>n;
    //int k;
    //cin>>k;
    int node;
    cin>>node;
    int val;
    cin>>val;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* Initial_Head=Convert_A_DLL(arr);
    //Node* final_Head=Insert_before_Head(Initial_Head,val);
    //Node* final_Head=Insert_before_Tail(Initial_Head,val);
    //Node* final_Head=Insert_before_Kth(Initial_Head,k,val,n);
    Node* final_Head=Insert_before_Node(Initial_Head,val,node);
    Print_DLL(final_Head);
    return 0;
}
