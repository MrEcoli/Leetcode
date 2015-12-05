class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());

		int n = num.size();
		
		int ret = num[0] + num[1] + num[2];

		for (int i = 0; i < n - 2; ++i){
			int start = i + 1, end = n - 1;

			while (start < end){
				int cur_sum = num[start] + num[end] + num[i];

				if (abs(cur_sum-target) < abs(ret -target)){
					ret = cur_sum;
				}

				if (cur_sum > target){
					end--;
				}
				else{
					start++;
				}
			}
		}
		return ret;
	}

};

