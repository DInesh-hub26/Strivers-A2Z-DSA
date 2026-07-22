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
    ListNode* middleNode(ListNode* head) {
        /*
        .......Brute
        ListNode* Temp=head;
        int size=0;
        while(Temp!=nullptr){
            size++;
            Temp=Temp->next;
        }
        Temp=head;
        int count=0;
        while(Temp!=nullptr){
            count++;
            if(count==(size/2)+1){
                break;
            }
            Temp=Temp->next;
        }
        return Temp;
        */

    //......Optimal
    //This Algo is known as slow fast pointers
    //(or)Tortoise-Hare algo(or)Flyods algo
       ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next !=nullptr){
            //For 1st middle use fast->next !=nullptr && fast->next->next !=nullptr
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
/*
   Time Complexity->Brute->O(n+(n/2))
                  ->Optimal->O(n/2)
   Space Complexity->Brute->O(1)
                   ->Optimal->O(1)
*/
};