class Solution {
public:
	vector<vector<int> > combine(int n, int k){
		vector<vector<int>> result;
		vector<int> input;
		vector<int> path;
		for(int i=1;i<=n;++i){
			input.push_back(i);
		}
		combine(result, input, path, n, k, 0);
		return result;
	}
	void combine(vector<vector<int>> &result, vector<int> &input, vector<int> &path, int n, int k, int start){
		if(k==0){
			result.push_back(path);
			return;
		}
		for(int i=start;i!=n-k+1;++i){
			path.push_back(input[i]);;
			combine(result,input,path,n,k-1,i+1);
			path.pop_back();
		}

	} 
};