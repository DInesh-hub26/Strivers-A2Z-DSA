//Definition of singly linked list:
#include<iostream>
#include<map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        /*
         ......Brute approach
          int count=1;
         unordered_map<ListNode*,int>mpp;
         ListNode* Temp=head;
         while(Temp!=nullptr){
            if(mpp.find(Temp)!=mpp.end()){
                return count-mpp[Temp];
            }
            mpp[Temp]=count;
            count++;
            Temp=Temp->next;
         }
         return 0;
        */

        //......Optimal soln
         ListNode* slow=head;
         ListNode* fast=head;
         int count=1;
         while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                fast=fast->next;
               while(fast!=slow){
                fast=fast->next;
                count++;
               }
               return count;
            }
         }
         return 0;
    }
    /*
      Time Complexity->Brute->O(n*3*1)(avg)O(n*3*n)(worst)
                     ->Optimal->O(n)
      Space Complexity->Brute->O(n)
                      ->Optimal->O(1)
    */
};