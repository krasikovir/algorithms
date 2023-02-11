#include <bits/stdc++.h>
using namespace std;

int main() {

	// {a, b, w}
	vector <tuple <int>> g(n);

	// shortest path
	int d[n][n]; 
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) d[i][j] = INT_MAX;
	for (auto & [a, b, w] : g) d[a][b] = w;

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], (d[i][k] == INT_MAX || d[k][j] == INT_MAX ? INT_MAX : d[i][k] + d[k][j]));
			}
		}
	}

	// shortest path
	int v1, v2;
	int ans = d[v1][v2];
	return 0;
}
