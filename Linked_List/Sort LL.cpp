// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* Find_Middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next !=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* Merge_LL(ListNode* left_head,ListNode* right_head){
        ListNode* dummy_Node=new ListNode(-1);
        ListNode* p1=left_head;
        ListNode* p2=right_head;
        ListNode* temp=dummy_Node;
        while(p1!=nullptr && p2!=nullptr){
            if(p1->val < p2->val){
                temp->next=p1;
                temp=p1;
                p1=p1->next;
            }else{
                temp->next=p2;
                temp=p2;
                p2=p2->next;
            }
        }
        if(p1 !=nullptr){
            temp->next=p1;
        }else{
            temp->next=p2;
        }
        return dummy_Node->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
       ListNode* Middle=Find_Middle(head);
       ListNode* left_head=head;
       ListNode* right_head=Middle->next;
       Middle->next=nullptr;
       left_head=sortList(left_head);
       right_head=sortList(right_head);
       return Merge_LL(left_head,right_head);
    }
    /*
      Time Complexity->Brute->O(n)+O(nlogn)+O(n)
                     ->Optimal->O(logn*(n+(n/2))
      Space Complexity->Brute->O(n)
                      ->Optimal->O(1) O(logn) if we consider recurisve stack space
    */
};