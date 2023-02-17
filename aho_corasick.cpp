using namespace std;
#include <bits/stdc++.h>

int main() {
    unordered_set <string> dict = {
		"ahoc",
		"hoc",
		"cora",
		"corr"
    };

    string text = "ahocorasick";

    int n = 10; for (auto x : dict) n += x.size();
    int fail[n], trie[n][26];
    unordered_map <int, unordered_set <string>> word;

    memset(trie, -1, sizeof trie);
    memset(fail, -1, sizeof fail);

    // c <-- counter (root <- 0)
    // s <-- state
	for (auto [it, c, s] = tuple(dict.begin(), 0, 0); it != dict.end(); ++it, s = 0) {
		for (auto [j, w] = tuple(0, *it); j < w.size(); ++j) {
			if (trie[s][w[j] - 'a'] == -1) trie[s][w[j] - 'a'] = ++c;
			s = trie[s][w[j] - 'a'];
		}
		word[s].insert(*it);
	}

    // link root children to root
    for (int i = 0; i < 26; ++i) if (trie[0][i] == -1) trie[0][i] = 0;

    // put existent root children to queue
    queue <int> q;
    for (int i = 0; i < 26; ++i) if (trie[0][i] != 0) fail[trie[0][i]] = 0, q.push(trie[0][i]);

	// build fails
    for (;q.size();) {
        int s = q.front(); q.pop();
        for (int i = 0; i < 26; ++i) {
            if (trie[s][i] != -1) {
                int f = fail[s];
                for (;trie[f][i] == -1;) f = fail[f];
                f = trie[f][i];
                fail[trie[s][i]] = f;
                for (auto x : word[f]) word[trie[s][i]].insert(x);
                q.push(trie[s][i]);
            }

        }
    }

	// go through text processing states
    for (int i = 0, c = 0; i < text.size(); ++i) {
        for (;trie[c][text[i] - 'a'] == -1;) c = fail[c];
        c = trie[c][text[i] - 'a'];
		for (auto x : word[c]) {
			cout << i - x.size() + 1 << " " << i << "\n";
			cout << x << "\n\n";
		}
    }
    return 0;
}
