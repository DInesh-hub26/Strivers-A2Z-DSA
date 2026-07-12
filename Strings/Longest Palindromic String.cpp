#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.size();
       string ans="";
       int start=0;
       int max_length=0;
       for(int i=0;i<n;i++){
        //If ans is Odd Palindrome
        int left=i;
        int right=i;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>max_length){
                max_length=right-left+1;
                start=left;
            }
            left--;
            right++;
        }
        //If ans is Even Palindrome
            left=i;
            right=i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>max_length){
                max_length=right-left+1;
                start=left;
            }
            left--;
            right++;
        }
       }
       ans=s.substr(start,max_length);
       return ans;
    }
    /*
      Time Complexity->Brute->O(n*n*n)
                     ->Better->O(n*n)
                     ->Optimal->O(n) (Manachers algo learn in future)
      Space Complexity->Brute->O(n)
                      ->Better->O(1) returning ans not considered
                      ->Optimal->O(n)
     Manachers algo is difficult learn about it in future
    */
};