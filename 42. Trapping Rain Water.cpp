class Solution {
public:
	int trap(int A[], int n) {
		if (n < 3){
			return 0;
		}

		vector<int> left(n, 0);
		left[0] = A[0];
		vector<int> right(n, 0);
		right[n - 1] = A[n - 1];

		for (int i = 1; i != n - 1; ++i){
			left[i] = max(left[i - 1], A[i]);
		}
		
		for (int i = n - 2; i >= 0; --i){
			right[i] = max(A[i], right[i + 1]);
		}
		
		int total = 0;
		
		for (int i = 1; i < n - 1; ++i){
			if (A[i] <left[i] && A[i] < right[i]){
				total += min(left[i], right[i]) - A[i];
			}
		}

		return total;
	}
};