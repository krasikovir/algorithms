#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_set <int> us = {1, 8, 7, 4, 11};

	// 1, 8, 7, 4, 11  --->  8, 4
	for (auto it = us.begin(); it != us.end()) {
		if (*it & 1) it = us.erase(it);
		else ++it;
	}
	return 0;
}
