#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s1[256]={0};
        int t1[256]={0};
        int n=s.size();//t.size()
        for(int i=0;i<n;i++){
            if(s1[s[i]]!=t1[t[i]]){
                return false;
            }
            //Here i+1 indicates that that character is seen last at (i+1)-1 index
            //0 means unseen
            s1[s[i]]=i+1;
            t1[t[i]]=i+1;
        }
        return true;
    }
    /*
      Time Complexity->Optimal->O(n)
      Space Complexity->Optimal->O(1)
      s1,t1 doesn't use any extra space because they are constant size arrays
    */
};