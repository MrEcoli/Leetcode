// Unique Binary Search Trees
// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
// Show Tags
// Have you met this question in a real interview? Yes  No
// Discuss



class Solution {
public:
	int numTrees(int n) {
		if(n==0)
			return 0;
		vector<int> f(n+1,0);
		f[0]=1;
		f[1]=1;

		for(int i = 2; i <= n; ++i){
			for(int j = 0; j < i; ++j){
				f[i] += f[j]*f[i-1-j];
			}
		}
		return f[n];
	}
};