/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. ::假装很难的题目...

*/



class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		int n = num.size();
		unordered_map<int, bool> visited;
		for(int i = 0; i != n; ++i)
			visited[num[i]] = false;
		int max_n = 1;
		int cur;
		for(int i = 0; i != n; ++i){
			int tmp = num[i];
			if(visited[tmp] == false){
				cur = find(tmp, visited);
				max_n = max(cur, max_n);
			}
		}
		return max_n;
	}

	int find(int candicate, unordered_map<int, bool> &visited){
		visited[candicate] = true;
		int low = candicate - 1;
		int high = candicate + 1;
		int n = 1;
		while(visited.find(low) != visited.end()){
			++n;
			visited[low] = true;
			--low;
		}

		while(visited.find(high) != visited.end()){
			++n;
			visited[high] = true;
			++high;
		}
		return n;
	}
};