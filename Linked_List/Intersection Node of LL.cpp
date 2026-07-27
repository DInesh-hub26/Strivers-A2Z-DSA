//Definition for singly-linked list.
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
   /*
   .......Better Approach
    ListNode* findIntersection(ListNode* smaller,ListNode* greater,int distance){
        ListNode* temp_2=greater;
        while(distance>0){
            temp_2=temp_2->next;
            distance--;
        }
        ListNode* temp_1=smaller;
        while(temp_1 != temp_2){
            temp_1=temp_1->next;
            temp_2=temp_2->next;
        }
        return temp_1;
    }
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        ........Brute Approach

        unordered_map<ListNode*,int>mpp;
        ListNode* temp=headA;
        while(temp!=nullptr){
            mpp[temp]++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=nullptr){
            if(mpp.find(temp)!=mpp.end()){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
        */

        /*
          int lengthA=0;
        ListNode* temp=headA;
        while(temp!=nullptr){
            lengthA++;
            temp=temp->next;
        }
        int lengthB=0;
        temp=headB;
        while(temp!=nullptr){
            lengthB++;
            temp=temp->next;
        }
        if(lengthA>lengthB){
            return findIntersection(headB,headA,lengthA-lengthB);
        }
        else{
            return findIntersection(headA,headB,lengthB-lengthA);
        }
        return nullptr;
        */
       //........Optimal
        ListNode* p1=headA;
        ListNode* p2=headB;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
            if(p1==p2){
                return p1;
            }
            if(p1==nullptr){
                p1=headB;
            }
            if(p2==nullptr){
                p2=headA;
            }
        }
        return p1;
    }
    /*
      Time Complexity->Brute->O(n1*1)+O(n2*1) O(n1*n1)+O(n2*n2) in worst case
                     ->Better->O(n1)+O(n2)+O(n2-n1 (or) n1-n2)+O(min(n1,n2)
                     ->Optimal->O(n1+n2)
      Space Complexity->Brute->O(n1) or O(n2)
                      ->Better->O(1)
                      ->Optimal->O(1)
    */
};