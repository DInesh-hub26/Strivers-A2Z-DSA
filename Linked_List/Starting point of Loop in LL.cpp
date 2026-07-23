 // Definition for singly-linked list.
 #include<iostream>
 #include<map>
 using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*
        .......Brute Approach
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        unordered_map<ListNode*,int>mpp;
        ListNode* Temp=head;
        while(Temp!=nullptr){
            if(mpp.find(Temp)!=mpp.end()){
                return Temp;
            }
            mpp[Temp]=1;
            Temp=Temp->next;
        }
        return nullptr;
        */
       //......Optimal soln
       if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;//fast
            }
        }
        return nullptr;
    }
    /*
       Time Complexity->Brute->O(n*3*1)(avg)O(n*3*n)(worst)
                      ->Optimal->O(n)
       Space Complexity->Brute->O(n)
                       ->Optimal->O(1)
    */
};