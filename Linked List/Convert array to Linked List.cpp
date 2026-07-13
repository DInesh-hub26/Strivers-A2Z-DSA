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

Node* Convert2toLL(vector<int>&arr){
    Node* Head=new Node(arr[0]);
    Node* Mover=Head;
    for(int i=1;i<arr.size();i++){
       Node* temp=new Node(arr[i]);
       Mover->next=temp;
       Mover=temp;
    }
    return Head;
}

int main(){
    vector<int>arr={9,2,3,4};
    Node* head=Convert2toLL(arr);
    cout<< head->data;
}