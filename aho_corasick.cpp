#include <bits/stdc++.h>
using namespace std;

unordered_map <int, string> um;

struct node {
	int next[26], go[26];
	bool term = false;
	int p = -1, link = -1;
	char pch;

	node (int p = -1, char pch = '#') : p(p), pch(pch) {
		fill(next, next + 26, -1);
		fill(go, go + 26, -1);
	}
};

vector <node> trie = {node()};

void add(string & s) {
	int v = 0;
	for (char ch : s) {
		if (trie[v].next[ch - 'a'] == -1) {
			trie[v].next[ch - 'a'] = trie.size();
			trie.emplace_back(v, ch);
		}
		v = trie[v].next[ch - 'a'];
	}
	trie[v].term = true;
	um[v] = s;
}

int go(int v, char ch);

int getlink(int v) {
	if (trie[v].link == -1) {
		if (v == 0 || trie[v].p == 0) trie[v].link = 0;
		else trie[v].link = go(getlink(trie[v].p), trie[v].pch);
	}
	return trie[v].link;
}

int go(int v, char ch) {
	if (trie[v].go[ch - 'a'] == -1) {
		if (trie[v].next[ch - 'a'] != -1) trie[v].go[ch - 'a'] = trie[v].next[ch - 'a'];
		else trie[v].go[ch - 'a'] = (v == 0 ? 0 : go(getlink(v), ch));
	}
	return trie[v].go[ch -  'a'];
}

int main() {
	vector <string> dict = {"he", "she", "hers", "his"};
	string text = "ahishers";
	for (int i = 0, c = 0; i < text.size(); ++i) {
		c = go(c, text[i]);
		if (um.count(c)) {
			cout << um[c] << "\n";
			cout << i << "\n\n";
		}
	}
	return 0;
}
