#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=0;
        for(auto it:s){ 
             if(it=='('){
                count++;
                maxi=max(count,maxi);
             }
             else if(it==')'){
                count--;
                maxi=max(count,maxi);
             }
        }
        return maxi;
    }
    /*
      Time Complexity->O(n)
      Space Complexity->O(1)
    */
};