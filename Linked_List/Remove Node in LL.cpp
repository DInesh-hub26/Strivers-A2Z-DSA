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
    Node* Head=new Node(arr[0]);
    Node* Mover=Head;
    for(int i=1;i<arr.size();i++){
        Node* Temp=new Node(arr[i]);
        Mover->next=Temp;
        Mover=Temp;
    }
    return Head;
}

Node* Remove_Node(Node* Head,int node){
    if(Head==nullptr){
        return Head;
    }
    if(Head->data==node){
        Node* Temp=Head;
        Head=Head->next;
        delete(Temp);
        return Head;
    }
    int val;
    Node* temp=Head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        val=temp->data;
        if(val==node){
           prev->next=prev->next->next;
           delete(temp);
           break;
        }
        prev=temp;
        temp=temp->next;
    }
    return Head;
}

void Print_New_LL(Node* Head){
    Node* temp=Head;
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
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* Initial_Head=Convert_A2LL(arr);
    Node* Final_Head=Remove_Node(Initial_Head,val);
    Print_New_LL(Final_Head);

    return 0;
}

//In leetcode only Node which has to be deleted is given 
//in that case we need to do
/*
   Node* temp=node->next;
   node->data=temp->data;
   node->next=temp->next;
   delete(temp);
*/