#include <bits/stdc++.h>
using namespace std;

int main() {

	// numeration from left upper to right down angle;
	int n, m;
	int arr[n + 1][m + 1]; 
	for (int i = 0; i < n + 1; ++i) for (int j = 0; j < m + 1; ++j) arr[i][j] = 0;

	// r, c - idx
	function <void(int, int, int)> add = [&](int r, int c, int val) {
		++r, ++c;
		for (int R = r; R < n + 1; R += R & -R)
			for (int C = c; C < m + 1; C += C & -C)
				arr[R][C] += val;
	};

	function <int(int, int)> pref = [&](int r, int c) {
		++r, ++c;
		int res = 0;
		for (int R = r; R > 0; R -= R & -R)
			for (int C = c; C > 0; C -= C & -C)
				res += arr[R][C];

		return res;
	};

	// query
	int row_upper, row_lower; // row_upper <= row_lower (0 1 2 3 ... up to down);
	int col_left, col_right;

	int ans =
		pref(row_lower, col_right) + 
		pref(row_upper - 1, col_left - 1) -
		pref(row_upper - 1, col_right) - 
		pref(row_lower, col_left - 1);

	return 0;
}
