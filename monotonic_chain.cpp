#include <bits/stdc++.h>
using namespace std;

int CROSS
(const pair <int, int> & a,
 const pair <int, int> & b,
 const pair <int, int> & c) 
{
	// {. . . a, b} ... c <- new
	// a -> b = {X, Y}
	// a -> c = {M, N}
	// | X  Y |
	// | M  N |
	
	// X Y
	int X = b.first - a.first;
	int Y = b.second - a.second;

	// M N
	int M = c.first - a.first;
	int N = c.second - a.second;

	return X * N - Y * M;
}

int main() {
	// points : {x, y};
	vector <pair <int, int>> arr;
	sort(arr.begin(), arr.end());


	// L - lower part of convex hull
	// U - upper one
	vector <pair <int, int>> L, U;

	for (int i = 0; i < arr.size(); ++i) {

		// take 2 last dots and current one
		// while angle is bad we poping_back existent ones
		for(; L.size() > 1 && CROSS(L.rbegin()[1], L.rbegin()[0], arr[i]) < 0; L.pop_back());
		L.push_back(arr[i]);
	}

	for (int i = arr.size() - 1; i > -1; --i) {
		for(; U.size() > 1 && CROSS(U.rbegin()[1], U.rbegin()[0], arr[i]) < 0; U.pop_back());
		U.push_back(arr[i]);
	}

	// (U v L) = convex hull
	return 0;
}
