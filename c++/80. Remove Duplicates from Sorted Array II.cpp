class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0 || n == 1 || n == 2){
			return n;
		}
		int cur_pos = 2;
		int prev_pos = 1;

		while (cur_pos != n)
		{
			if (A[cur_pos] == A[prev_pos] && A[cur_pos] == A[prev_pos -1]){
				cur_pos++;
			}
			else{
				prev_pos++;
				A[prev_pos] = A[cur_pos];
				cur_pos++;
			}
		}
		return prev_pos + 1;
	}
};