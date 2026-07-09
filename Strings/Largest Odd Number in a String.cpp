#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    //Same question can have trailing zeros in that case find first non zero index and then same code
    string largestOddNumber(string num) {
        int n=num.size();
        string ans="";
        for(int i=n-1;i>=0;i--){
          if((num[i]-'0')%2==1){
            return num.substr(0,i+1);
          }
        }
        return ans;
    }
    /*
      Time Complexity->Optimal->O(n)
      Space Complexity->Optimal->O(1)
    */
};