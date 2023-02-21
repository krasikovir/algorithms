#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	int p[n]; iota(p, p + n, 0);
	int sz[n]; fill(sz, sz + n, 1);

	function <int(int)> find = [&](int v) {
		return v == p[v] ? v : p[v] = find(p[v]);
	};

	function <void(int, int)> merge = [&](int u, int v) {
		u = find(u), v = find(v);
		if (u != v) {
			if (sz[u] > sz[v]) swap(u, v);
			sz[v] += sz[u];
			p[u] = v;
		}
	};

	return 0;
}
