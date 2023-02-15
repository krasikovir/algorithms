include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const ull C = 0x9e3779b9;

struct HASHER {
	ull operator()(const vector <int> & arr) const {
		ull ans = 0;
		for (const auto & x : arr) ans ^= hash<int>()(x) + C + (ans << 6) + (ans >> 2);
		return ans;
	}
};

int main() {
	unordered_set <vector <int>, HASHER> us;
	us.insert({1, 2, 3});
	us.insert({2, 2, 8});
	return 0;
}
