#include <bits/stdc++.h>
using namespace std;

const unsigned long long C = 0x9e3779b9;

template <typename T>
struct HASHER {
	unsigned long long operator()(const vector <T> & arr) const {
		unsigned long long ans = 0;
		for (const auto & x : arr) ans ^= hash<T>()(x) + C + (ans << 6) + (ans >> 2);
		return ans;
	}
};

int main() {
	unordered_set <vector <int>, HASHER<int>> us;
	us.insert({1, 2, 3});
	us.insert({2, 2, 8});
	return 0;
}
