

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		
		return lower_bound(A, A + n, target) - A;
	}
};



class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if (n == 0){
			return 0;
		}

		int left = 0, right = n;
		int mid = (left + right) >> 1;

		while (left < right)
		{
			mid = (left + right) >> 1;

			if (A[mid] >= target){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
		return left;
	}
};