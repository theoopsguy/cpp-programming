#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int* arr, int size) {
    vector<int> ans;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++) {
        if (seen.count(arr[i]) > 0)
            continue;
        
        seen[arr[i]] = true;
        ans.push_back(arr[i]);
    }
    return ans;
}

int main() {
    int arr[] = {1,2,3,3,2,1,4,3,6,5,5};
    vector<int> output = removeDuplicates(arr, 11);
    for(int i = 0; i < output.size(); i++) {
        cout<<output[i]<<endl;
    }
    
    return 0;
}