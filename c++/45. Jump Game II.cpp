
class Solution {
public:
	int jump(int A[], int n) {
	    
	    if(n == 1)
	        return 0;
	    
		int cur_idx = 0;
		int nxt_idx;
		int step = 0;

		if (A[cur_idx] >= n-1){
			return 1;
		}

		bool find = false;
		while (cur_idx < n - 1 && !find){
			step++;
			if (A[cur_idx] == 1){
				cur_idx = cur_idx + 1;
				continue;
			}
			int max_stp = 0;

			for (int i = 1; i <= A[cur_idx]; ++i){
				if (i + cur_idx >= n-1 ){
					find = true;
					break;
				}
				if (i+A[cur_idx+i] > max_stp){
					max_stp = i + A[cur_idx+i];
					nxt_idx = i + cur_idx;
				}

			}
			cur_idx = nxt_idx;
			
		}
	
		return step;
	}
};