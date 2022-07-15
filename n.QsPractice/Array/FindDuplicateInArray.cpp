// https://www.interviewbit.com/problems/find-duplicate-in-array/

#include <iostream>
#include <vector>
using namespace std;

// Make a map like sieve with idx as no. and value at that idx as the freq of that respective no.
// Iterate over map to return no. whose freq > 1
// Space: O(n)  Time: O(1)

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> map(n+1, 0);
    
    for(int i = 0; i < n; i++) {
        map[A[i]]++;
    }
    
    for(int i = 1; i < n+1; i++) {
        if(map[i] > 1)
            return i;
    }
    
    return -1;
}

