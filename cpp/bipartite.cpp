#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_set <int> g[n];

	// color = {0, 1}
	int col[n]; memset(col, 0, sizeof col);
	bool vis[n]; memset(vis, false, sizeof vis);

	function <void(int)> dfs = [&](int v) {
		vis[v] = true;

		for (auto x : g[v]) {
			if (vis[x] && col[x] == col[v]) {
				cout << "FAIL\n"; exit(0);
			}
			if (!vis[x]) 	col[x] = 1 - col[v]; dfs(x);
		}
	};

	for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i);
	cout << "GOOD\n";
	return 0;
}
