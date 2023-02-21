const int MOD = 1000000000 + 7;

template <typename t1, typename t2> inline void add(t1 & a, t2 b) {
	a = a + b >= MOD ? a + b - mod : a + b;
}

template <typename t1, typename t2> inline void sub(t1 & a, t2 b) {
	a = a < b ? a + MOD - b : a - b;
}

// pow mod MOD
long long powmod(x, p) {
	long long res = 1;
	for (;p; p /= 2, (x *= x) %= MOD) if (p & 1) (res *= x) %= MOD;
	return res;
}

// pow without MOD
long long pow(x, p) {
	long long res = 1;
	for (;p; p /= 2, x *= x) if (p & 1) res *= x;
	return res;
}

int main () {
	int a = 20, b = 4;

	// a div b mod MOD if MOD is prime
	a *= powmod(b, MOD - 2);
	return 0;
}
