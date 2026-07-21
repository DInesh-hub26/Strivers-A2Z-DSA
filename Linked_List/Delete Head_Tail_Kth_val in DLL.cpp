#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* back;
  Node* next;

  Node(int data_1,Node* Prev){
    data=data_1;
    back=Prev;
  }
};

Node* Convert_A_DLL(vector<int>&arr){
    Node* Head=new Node(arr[0],nullptr);
    Node* prev=Head;
    for(int i=1;i<arr.size();i++){
        Node* Temp=new Node(arr[i],prev);
        prev->next=Temp;
        prev=Temp;
    }
    return Head;
}
/*
......Remove Head

Node* Remove_Head(Node* Head){
 if(Head==nullptr){
    return Head;
 }
 if(Head->next==nullptr){
    return nullptr;
 }
 Node* prev=Head;
 Head=Head->next;
 Head->back=nullptr;
 prev->next=nullptr;
 delete(prev);
 return Head;
}
*/

/*
......Remove Tail

Node* Remove_Tail(Node* Head){
  if(Head==nullptr){
    return Head;
  }
  if(Head->next==nullptr){
    return nullptr;
  }
  Node* Temp=Head;
  while(Temp->next->next!=nullptr){
    Temp=Temp->next;
  }
  Temp->next->back=nullptr;
  delete(Temp->next);
  Temp->next=nullptr;
  return Head;
}
*/

/*
....Remove Kth Node

Node* Remove_Kth_Node(Node*Head,int k){
  Node* Temp=Head;
  int count=0;
  while(Temp->next!=nullptr){
    count++;
    if(count==k){
      break;
    }
    if(Temp->next==nullptr){
      return nullptr;
    }
    Temp=Temp->next;
  }
  Node* front=Temp->next;
  Node* Back=Temp->back;
  if(front==nullptr && Back==nullptr){
    return nullptr;
  }
  if(front==nullptr){
    return Remove_Tail(Head);
  }
  else if(Back==nullptr){
   return Remove_Head(Head);
  }
  else{
     front->back=Temp->back;
     Back->next=Temp->next;
     Temp->next=nullptr;
     Temp->back=nullptr;
     delete(Temp);
     return Head;
  }
}
*/

Node* Remove_Node(Node* Head,int node){
   //given node is not head
   Node* temp=Head;
   while(temp->next !=nullptr){
    if(temp->data==node){
      break;
    }
    temp=temp->next;
   }
   Node* Back=temp->back;
   Node* front=temp->next;
   if(front==nullptr && Back==nullptr){
    return nullptr;
   }
   else if(front==nullptr){
    Back->next=nullptr;
    temp->back=nullptr;
    delete(temp);
    return Head;
   }
   else{
    Back->next=temp->next;
    front->back=temp->back;
    temp->next=nullptr;
    temp->back=nullptr;
    delete(temp);
    return Head;
   }
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
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head=Convert_A_DLL(arr);
    //Node* final_head=Remove_Head(head);
    //Node* final_head=Remove_Tail(head);
    //Node* final_head=Remove_Kth_Node(head,k);
    Node* final_head=Remove_Node(head,node);
    Print_DLL(final_head);
    return 0;
}