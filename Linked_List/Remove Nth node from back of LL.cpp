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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        ......Brute Approach

        if(head->next==nullptr){
            return nullptr;
        }
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        if(count==n){
            ListNode* ans=head->next;
            delete(head);
            return ans;
        }
        int ind=0;
        temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ind++;
            if(ind==count-n+1){
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete(temp);
        return head;
        */

        //Optimal soln
        if(head->next==nullptr){
            return nullptr;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=1;i<=n;i++){
            fast=fast->next;
            if(fast==nullptr){
                ListNode* ans=head->next;
                delete(head);
                return ans;
            }
        }
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* del=slow->next;
        slow->next=slow->next->next;
        delete(del);
        return head;
    }
    /*
      Time Complexity->Brute->O(2*n)
                     ->Optimal->O(n)
      Space Complexity->Brute->O(1)
                      ->Optimal->O(1)
    */
};