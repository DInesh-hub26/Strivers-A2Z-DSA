#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int n=s.size();
        int k=0;
        int Minus_Present=0;
        //Goes on until first non space is found
        while(k<n && s[k]==' '){
            k++;
        }
        //Skips starting + or -
        if(k<n && (s[k]=='-'||s[k]=='+')){
            if(s[k]=='-'){
            Minus_Present=1;
            }
            k++;
        }
        //isdigit is a function which returns true if it is digit(0-9)
        while(k<n && isdigit(s[k])){
            int digit=s[k]-'0';
            //Overflow Check before Multiplication
            if(ans>(INT_MAX-digit)/10){
                if(Minus_Present){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            ans= ans*10+ digit;
            k++;
        }
        if(Minus_Present==1){
            ans=ans*-1;
        }
        return ans;
    }
    /*
      Time Complexity->O(n)
      Space Complexity->O(1)
    */
};