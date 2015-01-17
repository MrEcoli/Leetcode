class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &nums, int target){
		vector<vector<int>> result;
		vector<int> path;
		sort(nums.begin(), nums.end());

		DFS_Combination(result, nums, path, 0, target, nums.size(), 0);
		return result;
	}

	void DFS_Combination(vector<vector<int>> &result, vector<int> &nums, vector<int> &path, int sum , int target, int len, int start){
		if(sum==target){
			result.push_back(path);
			return;
		}
		int previous=INT_MIN;
		for(auto i=start;i!=len;++i){
			if(nums[i]==previous)
				continue;
			previous=nums[i];
			if((nums[i]+sum)<=target){
				path.push_back(nums[i]);
				DFS_Combination(result, nums, path, sum+nums[i], target, len, i+1);
				path.pop_back();
			}
			if((nums[i]+sum)>target)
				break;

		}
	}
};