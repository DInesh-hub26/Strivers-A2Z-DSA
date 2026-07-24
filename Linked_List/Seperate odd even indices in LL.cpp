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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* initialEven=head->next;
        ListNode* odd=head;
        ListNode* even=head->next;
        while(even!=nullptr && even->next !=nullptr){
            odd->next=even->next;
            odd=even->next;
            even->next=odd->next;
            even=odd->next;
        }
        odd->next=initialEven;
        return head;
    }
    /*
      Time Complexity->Brute->O(2*n)
                     ->Optimal->O(n)
      Space Complexity->Brute->O(n)
                      ->Optimal->O(1)
    */
};