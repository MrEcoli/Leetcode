class Solution {
public:
	bool canJump(int A[], int n) {
		vector<int> visited(n, 0);
		if (n == 0){
			return false;
		}
		if (n == 1){
			return true;
		}

		int cur_pox = 0;
		while (cur_pox < n-1){
			int choices = A[cur_pox];
			if (A[cur_pox] == 0){
				return false;
			}
			if (A[cur_pox] == 1){
				cur_pox++;
				continue;
			}
			int max_step = 0;
			int nxt_pos = cur_pox;
			for (int i = 1; i <= A[cur_pox]; ++i){
				if (cur_pox + i >= n-1){
					return true;
				}
				if (i+A[cur_pox + i] > max_step){
					max_step = i + A[cur_pox + i];
					nxt_pos = cur_pox + i;
				}
			}
			cur_pox = nxt_pos;
			cout << cur_pox << endl;
		}
		return true;
	}
};