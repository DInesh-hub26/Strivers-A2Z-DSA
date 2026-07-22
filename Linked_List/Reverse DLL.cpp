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

Node* Convert_A_to_DLL(vector<int>&arr){
    Node* Head=new Node(arr[0],nullptr,nullptr);
    Node* Prev=Head;
    for(int i=1;i<arr.size();i++){
        Node* Temp=new Node(arr[i],Prev,nullptr);
        Prev->next=Temp;
        Prev=Temp;
    }
    return Head;
}
/*
......Brute approach

Node* Reverse_DLL(Node* Head){
  Node* temp=Head;
  stack<int>st;
  while(temp!=nullptr){
    st.push(temp->data);
    temp=temp->next;
  }
  temp=Head;
  while(temp!=nullptr){
    temp->data=st.top();
    st.pop();
    temp=temp->next;
  }
  return Head;
}
*/

//Optimal Approach
Node* Reverse_DLL(Node* Head){
    Node* current=Head;
    Node* last=nullptr;
    while(current!=nullptr){
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    return last->back;
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
    Node* Initial_Head=Convert_A_to_DLL(arr);
    Node* final_Head=Reverse_DLL(Initial_Head);
    Print_DLL(final_Head);
    return 0;
}
/*
  Time Complexity->Brute->O(2*N)
                 ->Optimal->O(N)
  Space Complexity->Brute->O(N)
                  ->Optimal->O(1)
*/