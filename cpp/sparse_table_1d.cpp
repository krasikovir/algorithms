#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;

	// bin log
	int log[n + 1]; log[0] = log[1] = 0;
	for (int i = 2; i < n + 1; ++i) log[i] = log[i / 2] + 1;

	// sparse table
	int st[log[n] + 1][n];
	for (int i = 0; i < n; ++i) cin >> st[0][i]; // original array
	for (int p = 1; p < log[n] + 1; ++p) {
		for (int i = 0; i < n; ++i) {
			int a = st[p - 1][i];
			int b = i + (1 << (p - 1)) < number ? st[p - 1][i + (1 << (p - 1))] : INT_MAX;
			st[p][i] = min(a, b);
		}
	}

	// query
	int left, right; // idx
	int dist = right - left + 1;
	int pow = log[dist];

	// tow segments
	int first = st[pow][left];
	int second = st[pow][right + 1 - (1 << pow)];

	// ans
	int ans = min(first, second);
	return 0;
}
