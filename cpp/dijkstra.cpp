#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	// a -> {b, w}
	vector <pair <int, int>> g[n];

	// initial vertex
	// find shortest paths
	int k; int d[n];
	fill(d, d + n, INT_MAX);
	d[k] = 0;


	// min heap
	auto cmp = [&](const pair <int, int> & a, const pair <int, int> & b) {
		return a.first > b.first;
	};

	priority_queue <pair <int, int>, vector <pair <int, int>>, cmp> pq;
	pq.push({0, k});

	while (pq.size()) {
		int v = pq.top().second; pq.pop();
		for (auto & [u, w] : g[v]) {
			if (d[v] + w < d[u]) {
				d[u] = d[v] + w;
				pq.push({d[u], u});
			}
		}
	}

	int res = *max_element(d, d + n);
	res = (res == INT_MAX ? -1 : res);
	return 0;
}
