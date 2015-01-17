class Solution {
public:
	vector<vector<int>> subsets(vector<int> &S){
		long len=S.size();
		sort(S.begin(),S.end());
		int num=pow(double(2),len);
		vector<vector<int>> result;
		for(int i=0;i!=num;++i){
			int index=i;
			vector<int> temp;
			for(int j=0;j!=len;++j){
				if(index>>j&1)
					temp.push_back(S[j]);
			}
			result.push_back(temp);
		}
		return result;
	}
};