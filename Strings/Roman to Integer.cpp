#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        //Can also use Switch to return these value of Romans
        unordered_map<char,int>mpp;
        //Initialise Roman numerals
        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;
        int ans=0;
        for(int i=0;i<n;i++){
           if(i+1<n && mpp[s[i]]<mpp[s[i+1]]){
            ans-=(mpp[s[i]]);
           }else{
           ans+=mpp[s[i]];
           }
        }
        return ans;
    }
    /*
      Time Complexity->O(n)
      Space Complexity->O(1)
    */
};