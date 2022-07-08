#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int *arr = new int[n];

	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	for(int i = 0; i < n; i++) {
		int minIdx = i;
		for (int j = i+1; j < n; j++) {
			if (arr[j]<arr[minIdx]) {
				minIdx = j;
			}
		}
		swap(arr[i], arr[minIdx]);
	}

	for(int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}