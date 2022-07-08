#include <bits/stdc++.h>
using namespace std;

const int n = 100;
int arr[n];

void merge(int l, int r, int mid) {
	int lSz = mid - l + 1;
	int lArr[lSz + 1];
	int rSz = r - mid;
	int rArr[rSz + 1];

	for (int i = 0; i < lSz; i++) {
		lArr[i] = arr[l + i];
	}

	for (int i = 0; i < rSz; i++) {
		rArr[i] = arr[mid + 1 + i];
	}

	lArr[lSz] = rArr[rSz] = INT_MAX;
	int li = 0, ri = 0;
	for (int i = l; i <=r; i++) {
		if (lArr[li] <= rArr[ri]) {
			arr[i] = lArr[li++];
		}
		else {
			arr[i] = rArr[ri++];
		}
	}
}

void mergeSort(int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r)/2;
	mergeSort(l, mid);
	mergeSort(mid+1, r);
	merge(l, r, mid);
}

int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	mergeSort(0, n-1);
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}