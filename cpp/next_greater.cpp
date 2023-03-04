#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; 
	// 2, 1, 5, 6, 2, 3
	// 0  1  2  3  4  5
	vector <int> arr(n);

	// stack for idx
	vector <int> v;

	// right[i] -> idx for nextgreater of i pos
	vector <int> right(n);

	// monotonic stack
	for (int i = 0; i < n; ++i ){
		for (; v.size() && arr[v.back()] > arr[i];) {
			right[v.back()] = i;
			v.pop_back();
		}
		v.push_back(i);
	}

	// rest items doesn't have nextgreaters
	for (auto x : v) right[x] = -1;

	// 2  1  5  6  2  3   arr
	// 1 -1  4  4 -1 -1   right
	// 0  1  2  3  4  5
	vector <int> ans = right;
	return 0;
}



