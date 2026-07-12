#include<iostream>
#include<string>
using namespace std;
// Function to count substrings with at most k distinct characters
int atMostKDistinct(string s, int k) {
    // Left pointer and result
    int left = 0, res = 0;
    // Frequency map
    unordered_map<char, int> freq;

    // Iterate through string with right pointer
    for (int right = 0; right < s.size(); right++) {
        // Add current character
        freq[s[right]]++;

        // Shrink window if distinct characters exceed k
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }

        // Count substrings in current window
        res += (right - left + 1);
    }
    return res;
}
/*
  Time Complexity->O(n)
  Space Complexity->O(k) O(1) if it only consists lower case
*/
