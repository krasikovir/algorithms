#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; int a[n];
	int m; int b[m];

	int dp[n + 1][m + 1]; memset(dp, 0, sizeof dp);

	pair <int, int> p[n + 1][m + 1];
	for (int i = 0; i < n + 1; ++i) for (int j = 0; j < m + 1; ++j) p[i][j] = {-1, -1};

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1, p[i][j] = (dp[i - 1][j - 1] == 0 ? make_pair(-1, -1) : make_pair(i - 1, j - 1));
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				p[i][j] = (dp[i][j] > 0 ? (dp[i - 1][j] > dp[i][j - 1] ? make_pair(i - 1, j) : make_pair(i, j - 1)) : make_pair(-1, -1));
			}
		}
	}

	pair <int, int> idx = {n, m}; vector <int> ans;
	for (;idx != make_pair(-1, -1);) {
		// if this index is a mathcing point then put this elem to answer
		if (a[idx.first - 1] == b[idx.second - 1]) ans.push_back(a[idx.first - 1]);
		idx = p[idx.first][idx.second];
	}
	reverse(ans.begin(), ans.end());
	return 0;
}

