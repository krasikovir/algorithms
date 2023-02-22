#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int arr[n];

	int p[n]; memset(p, -1, sizeof p);
	int dp[n]; fill(dp, dp + n, 1);

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < i; ++j) 
			if (arr[i] > arr[j] && dp[j] + 1 >= dp[i]) p[i] = j, dp[i] = dp[j] + 1;

	int idx = max_element(dp, dp + n) - dp;

	vector <int> ans; for (;p[idx] != -1; ans.push_back(idx), idx = p[idx]); ans.push_back(idx);

	reverse(ans.begin(), ans.end());
	return 0;
}

