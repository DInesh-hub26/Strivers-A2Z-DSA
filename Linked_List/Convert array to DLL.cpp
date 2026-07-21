#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
int data;
Node* back;
Node* next;

Node(int data_1,Node* prev){
    data=data_1;
    back=prev;
    next=nullptr;
}
};

Node* Convert_A_to_DLL(vector<int>&arr){
    Node* Head=new Node(arr[0],nullptr);
    Node* Prev=Head;
    for(int i=1;i<arr.size();i++){
        Node* Temp=new Node(arr[i],Prev);
        Prev->next=Temp;
        Prev=Temp;
    }
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
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head=Convert_A_to_DLL(arr);
    Print_DLL(head);
    return 0;
}