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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0;
        int sum=0;
        while(p1 != nullptr || p2 != nullptr){
            sum=carry;
            if(p1 != nullptr){
                sum+=p1->val;
            }
            if(p2 != nullptr){
                sum+=p2->val;
            }
            ListNode* temp=new ListNode(sum%10);
            carry=sum/10;
            curr->next=temp;
            curr=temp;
            if(p1 != nullptr){
                p1=p1->next;
            }
            if(p2 != nullptr){
                p2=p2->next;
            }
        }
        if(carry){
            ListNode* last=new ListNode(carry);
            curr->next=last;
            last->next=nullptr;
        }
        return dummy->next;
    }
    /*
      Time Complexity->O(max(n1,n2))
      Space Complexity->auxilary space->O(1)(excluding output list)
    */
};