class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int pos = m + n -1;
		int i = m - 1, j = n - 1;
		while ( i >= 0 && j >= 0)
		{
			if (A[i] >= B[j]){
				A[pos--] = A[i--];
			}
			else{
				A[pos--] = B[j--];
			}

		}
		while (j >= 0)
		{
			A[pos--] = B[j--];
		}
	}
};