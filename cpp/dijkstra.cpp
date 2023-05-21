#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	
	// a -> {b, w};
	vector <pair <int, int>> g[n];

	// src - start vertex
	int src; int d[n];
	fill(d, d + n, INT_MAX);
	d[src] = 0;

	set <pair <int, int>> st;
	st.insert({0, src});

	for (;st.size();) {
		auto [dist, v] = *st.begin();
		st.erase({dist, v});

		for (auto [u, w] : g[v]) {
			if (d[v] + w < d[u]) {
				st.erase({d[u], u});
				d[u] = d[v] + w;
				st.insert({d[u], u});
			}
		}
	}
}
