#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(char & a, char & b) const {
		return a == b && a == ' ';
	}
};

int main() {
	string t = "       hello    my                friends!  ";
	auto it = unique(t.begin(), t.end(), cmp());

	// " hello my friends "
	t.erase(it, t.end());
	return 0;
}


