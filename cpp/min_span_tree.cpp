#include <bits/stdc++.h>
using namespace std;

// kruskal + dsu

struct cmp {
	bool operator()(const vector <int> & a, const vector <int> & b) {
		asc by w
		return a[2] > b[2];
	}
};

int main() {
	// {u, v, w};
	vector <vector <int>> g(n);


	// dsu 
	int p[n]; int sz[n];
	function <int(int)> find;
	function <void(int, int)> merge;

	sort(g.begin(), g.end(), cmp());

	// total weight and amount of connected components
	int W = 0, C = n;

	// over all edges
	for (int i = 0; i < g.size(); ++i) {
		int u, v, w;
		u = g[i][0], v = g[i][1], w = g[i][2];

		if (find(u) != find(v)) {
			--C;
			W += w;
			merge(u, v);
		}

		if (C == 1) break;
	}

	int ans = C;
	return 0;
}
