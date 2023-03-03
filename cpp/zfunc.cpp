#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;

	int z[n]; memset(z, 0, sizeof z);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		for (;i + z[i] < n && s[z[i]] == s[i + z[i]]; ++z[i]);
		if (i + z[i] - 1 > r), l = i, r = i + z[i] - 1;
	}

	return 0;
}
