#include<iostream>
#include<stack>
using namespace std;
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* Reverse(ListNode* node){
        ListNode* Temp=node;
        ListNode* Prev=nullptr;
        while(Temp!=nullptr){
            ListNode* front=Temp->next;
            Temp->next=Prev;
            Prev=Temp;
            Temp=front;
        }
        return Prev;
    }
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        /*
         ......Brute Approach
        
        stack<int>st;
        ListNode* Temp=head;
        while(Temp!=nullptr){
            st.push(Temp->val);
        }
        Temp=head;
        while(Temp!=nullptr){
            if(st.top()!=Temp->val){
                return false;
            }
            st.pop();
            Temp=Temp->next;
        }
        return true;
        */

       //......Optimal soln
         if(head==nullptr || head->next==nullptr){
            return true;
        }
         ListNode* slow=head;
         ListNode* fast=head;
         while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
         }
         ListNode* new_head=Reverse(slow->next);
         ListNode* temp=new_head;
         ListNode* temp_2=head;
         while(temp !=nullptr){
            if(temp_2->val != temp->val){
                Reverse(new_head);
                return false;
            }
            temp_2=temp_2->next;
            temp=temp->next;
         }
        Reverse(new_head);
        return true;
    }
    /* 
       Time Complexity->Brute->O(2n)
                      ->Optimal->O(4*(n/2))
       Space Complexity->Brute->O(n)
                       ->Optimal->O(1)
     */
};