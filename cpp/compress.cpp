#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <int> init = {1, 9, 4, 2, 4};

	vector <int> v = init;
	sort(v.begin(), v.end());

	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());

	vector <int> res;
	for (auto x : init) {
		int val = lower_bound(v.begin(), v.end(), x) - v.begin();
		res.push_back(val);
	}

	// res = {0, 3, 2, 1, 2}

}
