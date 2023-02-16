#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int main() {
	// multiset
	tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> tree;

	// 1 2 2 5 7 7 9
	for (int k : {2, 2, 1, 5, 7, 7, 9}) tree.insert(k);

	// lower_bound <-> upper_bound are messed up
	
	// lower_bound
	auto lb = tree.upper_bound(5);
	// 1 2 2 5 7 7 9
	//       ^
	//       lb


	// upper__bound
	auto ub = tree.lower_bound(5);
	// 1 2 2 5 7 7 9
    //         ^
	//        ub

	
	// order_of_key 	
	int left = tree.order_of_key(7);
	// 1 2 2 5 7 7 9
	// ^ ^ ^ ^             
	// left = 4

	
	// find_by_order k = 0 ... n - 1
	auto kth_element = tree.find_by_order(5);
	// 1 2 2 5 7  7  9
	//            ^
	// 0 1 2 3 4  5  6
	//           kth
	
	
	// undefined
	auto f = tree.find(2);
	// if less_equal <int> --> less <int> it will bes set
	// in stl set there is no order_of_key and find_by_order

	return 0;
}
