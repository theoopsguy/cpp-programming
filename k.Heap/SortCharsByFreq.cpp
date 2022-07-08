#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> pq;
        
        for (char c : s) {
            map[c]++;
        }
        
        for(auto &it: map) {
            pq.push({it.second, it.first}); //max heap will be constructed on the basis of frequency
        }
        
        string ans;
        
        while (!pq.empty()) {
            ans += string(pq.top().first, pq.top().second); //Fills the string with n consecutive copies of character c.
            pq.pop();
        }

        return ans;
    }
};