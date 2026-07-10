#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    //In Brute method use sorting technique and then compare every character
    bool isAnagram(string s, string t) {
        // int s1[256]={0};
        // int t1[256]={0};
        int freq[26]={0};
        int n=s.size();
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<n;i++){
           freq[s[i]-'a']++;
           freq[t[i]-'a']--;
            // s1[s[i]]++;
            // t1[t[i]]++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        // for(int i=0;i<256;i++){
        //     if(s1[i]!=t1[i]){
        //         return false;
        //     }
        //}
        return true;
    }
    /*
      Time Complexity->Brute->O(nlogn)
                     ->Optimal->O(n)
      Space Complexity->Brute->O(1)
                      ->Optimal->(1)
      Constant array size will not take any extra SC
    */
};