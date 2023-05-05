#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[n];
	int nge[n]; memset(nge, -1, sizeof nge);

	vector <int> v;
	for (int i = 0; i < n; ++i) {
		for (;v.size() && arr[v.back()] <= arr[i]; nge[v.back()] = i, v.pop_back());
		v.push_back(i);
	}

	// 2   1   5   6   2   3   arr
	// 2   2   3  -1   5  -1   nge
	// 0   1   2   3   4   5   idx
	return 0;
}
