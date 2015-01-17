class Solution {
public:
	int search(int A[], int n, int target) {
		if (n == 0){
			return -1;
		}
		int left = 0, right = n;
		int mid;

		while (left <= right){
			mid = (left + right) >> 1;
			if (A[mid] == target){
				return mid;
			}else if (A[mid] < target){
				if (target < A[left]){
					left = mid + 1;
				}
				else{
					right = mid - 1;
				}
			}
			else{
				if (target >= A[left]){
					right = mid -1;
				}
				else{
					left = mid + 1;
				}
			}
		}

		return -1;
	}
};

class Solution {
public:
	int search(int A[], int n, int target) {
		int start = 0;
		int end = n - 1;

		while (start <= end) {
			int mid = (start + end) / 2;
			if (A[mid] == target) return mid;
			if (A[start] < A[mid]) {
				// situation 1, red line
				if (A[start] <= target && target <= A[mid]) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			else {

				if (A[mid] <= target && target <= A[end]) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}
		}
		return -1;
	}
};