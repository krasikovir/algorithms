#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector <vector <int>> g(n);
	int in[n]; memset(in, 0, sizeof in);

	// O(n + m)
	for (int i = 0; i < n; ++i) for (auto x : g[i]) ++in[x];

	queue <int> q; vector <int> ans;
	for (int i = 0; i < n; ++i) if (in[i] == 0) q.push(i);

	for (;q.size();) {
		int v = q.front(); q.pop();
		ans.push_back(v);
		for (auto x : g[v]) {
			--in[x];
			if (in[x] == 0) q.push(x);
		}
	}

	// detect cycle in directed graph
	ans.size() == n;
	return 0;
}
