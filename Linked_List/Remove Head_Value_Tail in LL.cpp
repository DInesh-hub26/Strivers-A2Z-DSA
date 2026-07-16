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

Node* Convert_Array2LL(vector<int>&arr,int n){
    Node* Head=new Node(arr[0]);
    Node* Mover=Head;
    for(int i=1;i<n;i++){
        Node* Temp=new Node(arr[i]);
        Mover->next=Temp;
        Mover=Temp;
    }
    return Head;
}
 /*
    ......Remove Head

    Node* Remove_Head(Node* Head){
    if(Head==nullptr){
        return Head;
    }
    Node* temp=Head;
    Head=Head->next;
    delete(temp);
    return Head;
}
    */

    /*
    ........Remove Tail

    Node* Remove_Tail(Node* Head){
    if(Head==nullptr || Head->next==nullptr){
          return nullptr;
    }
    Node* temp=Head;
    while(temp->next->next != nullptr){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return Head;
}
    */

    /*
    ..........Remove Kth Node

    Node* Remove_Kth_Node(Node* Head,int k){
    if(Head==nullptr){
        return Head;
    }
    if(k==1){
        Node* Temp=Head;
        Head=Head->next;
        delete(Temp);
        return Head;
    }
    int count=0;
    Node* Temp=Head;
    Node* Prev=nullptr;
    while(Temp!=nullptr){
        count++;
        if(count==k){
            Prev->next=Prev->next->next;
            delete(Temp);
            break;
        }
        Prev=Temp;
        Temp=Temp->next;
    }
    return Head;
}
    */

void Print_New_LL(Node* New_Head){
    Node* Temp=New_Head;
    while(Temp!=nullptr){
        cout<<Temp->data<<" ";
        Temp=Temp->next;
    }
}

int main(){
    int n;
    cin>>n;
    //int k;
    //cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head=Convert_Array2LL(arr,n);
    //Node* New_Head=Remove_Head(head);
    //Node* New_Head=Remove_Tail(head);
    //Node* New_Head=Remove_Kth_Node(head,k);
    //Print_New_LL(New_Head);
    //Print_New_LL(New_Head);
    //Print_New_LL(New_Head);

    return 0;
}