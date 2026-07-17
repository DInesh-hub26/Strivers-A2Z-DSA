#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data_1){
        data=data_1;
        next=nullptr;
    }
};

Node* Convert_A2LL(vector<int>&arr){
    if(arr.size()==0){
        return nullptr;
    }
    Node* Head=new Node(arr[0]);
    Node* Mover=Head;
    for(int i=1;i<arr.size();i++){
        Node* Temp=new Node(arr[i]);
        Mover->next=Temp;
        Mover=Temp;
    }
    return Head;
}

/*
    .....Insert at Head
Node* Insert_at_Head(Node* Head,int val){
    Node* temp=new Node(val);
    temp->next=Head;
    return temp;
}
*/

/*
     .....Insert at Tail
Node* Insert_at_Tail(Node* Head,int val){
    Node* Temp=Head;
    Node* Fake=new Node(val);
    if(Head==nullptr){
        return Fake;
    }
    while(Temp->next!=nullptr){
        Temp=Temp->next;
    }
    Temp->next=Fake;
    return Head;
}
*/

/*
   .......Insert at K th position
Node* Insert_at_Kth_Place(Node* Head,int val,int k){
   Node* Fake=new Node(val);
   if(Head==nullptr){
    if(k==1){
        return Fake;
    }else{
        return Head;
    }
   }
   if(k==1){
    Fake->next=Head;
    return Fake;
   }
   int count=0;
   Node* Temp=Head;
   while(Temp!=nullptr){
     count++;
   if(count==k-1){
      Fake->next=Temp->next;
      Temp->next=Fake;
   }
   Temp=Temp->next;
}
return Head;
}
*/

Node* Insert_before_Node(Node*Head,int node,int val){
    Node* Fake=new Node(val);
    if(Head==nullptr){
        return Head;
    }
    if(node==Head->data){
        Fake->next=Head;
        return Fake;
    }
    Node* Prev=nullptr;
    Node* Temp=Head;
    while(Temp!=nullptr){
        if(Temp->data==node){
           Fake->next=Prev->next;
           Prev->next=Fake;
        }
        Prev=Temp;
        Temp=Temp->next;
}
  return Head;
}
void Print_New_LL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int n;
    cin>>n;
    int val;
    cin>>val;
    //int k;
    //cin>>k;
    int node;
    cin>>node;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* Initial_Head=Convert_A2LL(arr);
    //Node* Final_Head=Insert_at_Head(Initial_Head,val);
    //Node* Final_Head=Insert_at_Tail(Initial_Head,val);
    //Node* Final_Head=Insert_at_Kth_Place(Initial_Head,val,k);
    Node* Final_Head=Insert_before_Node(Initial_Head,node,val);
    Print_New_LL(Final_Head);
}