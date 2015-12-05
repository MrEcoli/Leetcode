class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m + n;

		if (total&1){
			return find_Kth(A, m, B, n, total / 2 + 1);
		}
		else{
			return (find_Kth(A, m, B, n, total / 2 + 1) + find_Kth(A, m, B, n, total / 2)) / 2.0;
		}
	}

	double find_Kth(int A[], int m, int B[], int n, int k){
		if (m < n){
			return find_Kth(B, n, A, m, k);
		}

		if (n == 0) return A[k-1];

		if (k == 1 ) return A[0] < B[0] ? A[0] : B[0];

		int ib = min(k / 2, n), ia = k - ib;

		if (A[ia-1] < B[ib-1]){
			return find_Kth(A + ia, m - ia, B, n, k - ia);
		}else if (A[ia-1] > B[ib-1]){
			return find_Kth(A, m, B + ib, n - ib, k - ib);
		}else
			return A[ia-1];
	}
};