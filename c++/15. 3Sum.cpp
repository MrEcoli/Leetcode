
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());

		vector<vector<int>> ret;

		if (num.size()<3){
			return ret;
		}
		int n = num.size();

		for (int i = 0; i < n - 2; ++i){
			int start = i + 1, end = n - 1;
			int target = 0 - num[i];
			if (i > 0 && num[i] == num[i - 1])
				continue;

			while (start < end){
				if (num[start] + num[end] == target){
					ret.push_back(vector<int>{num[i], num[start], num[end]});
					while (start < end && num[start] == num[start + 1]){
						start++;
					}
					start++;

					while (start < end && num[end] == num[end -1])
					{
						end--;
					}
					end--;
					
				}
				else if (num[start] + num[end] > target){
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
