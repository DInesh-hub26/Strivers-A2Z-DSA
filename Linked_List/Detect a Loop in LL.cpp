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
    bool hasCycle(ListNode *head) {
        /*
        ........ Brute Approach
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        unordered_map<ListNode*,int>mpp;
        ListNode* Temp=head;
        while(Temp!=nullptr){
            if(mpp.find(Temp)!=mpp.end()){
                return true;
            }
            mpp[Temp]=1;
            Temp=Temp->next;
        }
        return false;
        */
       if(head==nullptr || head->next==nullptr){
            return false;
        }
       ListNode* Slow=head;
       ListNode* Fast=head;
       while(Fast!=nullptr && Fast->next!=nullptr){
           Slow=Slow->next;
           Fast=Fast->next->next;
           if(Slow==Fast){
             return true;
           }
       }
       return false;
    }
    /*
      Time Complexity->Brute->O(n*3*1)(avg) O(n*3*n)(worst)
                     ->Optimal->O(n)
      Space Complexity->Brute->O(n)
                      ->Optimal->O(1)
    */
};