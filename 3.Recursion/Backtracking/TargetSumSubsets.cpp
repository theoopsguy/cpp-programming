#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printTargetSumSubsets(vector<int> arr, int idx, string set, int tar, int sum) 
{
    if (idx >= arr.size() || sum > tar)
    {
        if (sum == tar)
        {
            cout<<set<<"."<<endl;
        }

        return;
    }
    
    int ele = arr[idx];
    
    printTargetSumSubsets(arr, idx+1, set + to_string(ele) + ", ", tar, sum+ele);
    printTargetSumSubsets(arr, idx+1, set, tar, sum);
}

int main()
{
    int number;
    vector<int> arr;

    cin>>number;

    for (int idx = 0; idx < number; idx++)
    {
        int temp;

        cin>>temp;

        arr.push_back(temp);
    }

    int tar;

    cin>>tar;

    printTargetSumSubsets(arr, 0, "", tar, 0);

    return 0;

}