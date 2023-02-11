#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int vec[n];

	int N = n; while ((N - 1) & N != 0) ++N;
	int arr[2 * N]; memset(arr, 0, sizeof(arr));
	for (int i = 0; i < n; ++i) arr[N + i] = vec[i];

	// for (int i = n; i < N; ++i) arr[N + i] = INT_MAX;
	// minimum seg tree example

	for (int i = N - 1; i > 0; --i) arr[i] = arr[2 * i] + arr[2 * i + 1];

	function <void(int, int)> update = [&](int idx, int val) {
		arr[N + idx] = val;
		(idx += N) /= 2;
		for (; idx > 0; idx /= 2) arr[idx] = arr[2 * idx] + arr[2 * idx + 1];
		
	};

	function <int(int, int, int, int, int)> sum = [&](int v, int v_left, int v_right, int left, int right) {
		if (left <= v_left && v_right <= right) return arr[v];
		if (right < v_left || v_right < left) return 0;
		int border = (v_left + v_right) / 2;
		return 
			sum(2 * v, v_left, border, left, right) +
			sum(2 * v + 1, border + 1, v_right, left, right);
	};

	// query
	int left, right;
	int ans = sum(1, 0, N - 1, left, right);
	return 0;
}
