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

Node* ConvertArray2LL(vector<int>&arr,int n){
    Node* Head=new Node(arr[0]);
    Node* Mover=Head;
    for(int i=1;i<n;i++){
      Node* Temp=new Node(arr[i]);
      Mover->next=Temp;
      Mover=Temp;
    }
    return Head;
}

int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int present=0;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   Node* head=ConvertArray2LL(arr,n);
   Node* temp=head;
   while(temp!=nullptr){
    if(temp->data==target){
        present=1;
    }
    temp=temp->next;
   }
   cout<<present;
}