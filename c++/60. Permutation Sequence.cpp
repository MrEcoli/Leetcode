class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> arr(n+1);
		arr[1] = 1;

		for (int i = 2; i != n + 1; ++i){
			arr[i] = arr[i - 1] * i;
		}

		set<char> candicate;

		for (int i = 1; i != n + 1; ++i){
			candicate.insert('0' + i);
		}

		string s = getPermutation(arr, candicate, n, k - 1);
		
		return s;
	}

	string getPermutation(vector<int> &arr, set<char> &candicate, int n, int k){
		if (n == 1){
			return string(1, *candicate.begin());
		}
		int skip = k / arr[n - 1];
		auto iter = candicate.begin();
		while (skip--)
		{
			iter++;
		}
		char ch = *iter;
		candicate.erase(iter);
		return string(1, ch) + getPermutation(arr, candicate, n - 1, k%arr[n - 1]);

	}
};