#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	unordered_set <int> g[n];
	vector <int> cycle;
	bool vis[n]; memset(vis, false, sizeof vis);

	function <int(int, int)> dfs = [&](int v, int prev) {
		if (vis[v]) return v;
		vis[v] = true;
		for (auto x : g[v]) {
			if (x == prev) continue;
			int k = dfs(x, v);
			if (k != -1) {
				cylce.push_back(v);
				if (k == v) {
					cout << "cycle detected\n"; 
					for (auto x : cycle) cout << x << " "; cout << "\n";
					exit(0);
				}
				return k;
			}
		}
		return -1;
	};

	for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i, -1);
	cout << "no cycle\n";
	return 0;
}
