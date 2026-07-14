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
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2LL(arr,n);
    Node* temp=head;
    //int count=0;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
        //count++;
    }
    //return count;
    //For Length of LL return count
}
/*
  Time Complexity->O(n)
*/