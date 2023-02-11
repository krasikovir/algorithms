#include <bits/stdc++.h>
using namespace std;

int main() {
	string base;
	string find;

	string s = find + '#' + base;
	int n = s.size();

	int lps[n]; memset(lps, 0, sizeof(lps));
	for (int i = 1; i < n; ++i) {
		int k = lps[i - 1];
		for (; s[i] != s[k] && k != 0; k = lps[k - 1]);
		if (s[i] == s[k]) ++k;
		lps[i] = k;
	}

	vector <int> entrance;
	for (int i = 0; i < n; ++i)
		if (lps[i] == find.size()) 
			entrance.push_back(i - 2 * find.size());

	return 0;
}

