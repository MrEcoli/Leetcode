class Solution {
public:
	bool search(int A[], int n, int target) {
		if (!n)
			return false;

		int low_idx = 0, high_idx = n - 1, mid;

		while (low_idx < high_idx)
		{
			mid = (low_idx + high_idx ) >> 1;
			if (A[mid] == target){
				return true;
			}
			if (A[low_idx] == A[high_idx]){
				low_idx++;
				continue;
			}
			if (A[mid] > A[low_idx]){
				if (target < A[mid] && target >= A[low_idx]){
					high_idx = mid - 1;
				}
				else
				{
					low_idx = mid + 1;
				}

			}
			else if (A[mid] < A[low_idx]){
				if (target > A[mid] && target <= A[high_idx]){
					low_idx = mid + 1;
				}
				else{
					high_idx = mid - 1;
				}
			}
			else{
				low_idx = mid + 1;
			}
			
		}

		return A[low_idx] == target;
	}
};



