#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int arr[n + 1]; fill(arr, arr + n + 1, 0);

	function <void(int, int)> add = [&](int idx, int val) {
		++idx;
		for (; idx < n + 1; idx += idx & -idx) arr[idx] += val;
	};

	function <int(int)> pref = [&](int idx) {
		++idx;
		int res = 0;
		for (; idx > 0; idx -= idx & -idx) res += arr[idx];
		return res;
	};

	return 0;
}
