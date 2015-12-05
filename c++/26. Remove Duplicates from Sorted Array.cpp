class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int index = 0;
		for (int i = 0; i != n; ++i){
			if (i == n-1 || A[i] != A[i+1]){
				A[index++] = A[i];
			}
		}
		return index;
	}
};
