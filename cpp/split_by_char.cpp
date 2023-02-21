#include <bits/stdc++.h>
using namespace std;

int main() {
	string t = "hello/lol/lmao";
	string temp;
	vector <string> res;

	stringstream ss(t); for (; getline(ss, temp, '/');) res.push_back(temp);
	// {"hello", "lol", "lmao"}
	return 0;
}
