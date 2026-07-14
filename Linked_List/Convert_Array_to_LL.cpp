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

int main(){
    vector<int>arr={1,2,3,4};
    Node* y=new Node(arr[0]);
    cout<<y->data;
}