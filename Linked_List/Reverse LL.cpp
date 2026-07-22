
 //Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
  //For Brute Approach use Stack meathod that is used in DLL
    ListNode* reverseList(ListNode* head) {
        ListNode* Temp=head;
        ListNode* prev=nullptr;
        while(Temp!=nullptr){
            ListNode* front=Temp->next;
            Temp->next=prev;
            prev=Temp;
            Temp=front;
        }
        return prev;
    }
    /*
      Time Complexity->Brute->O(2*n)
                     ->Optimal->O(n)
      Space Complexity->Brute->O(n)
                      ->Optimal->O(1)
    */
};