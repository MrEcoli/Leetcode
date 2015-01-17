class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &S){
		sort(S.begin(),S.end());
		set<vector<int>> sort_vec;
		const int len=S.size();
		const unsigned int num=1U<<len;
		for(int i=0;i!=num;++i){
			vector<int> one_vec;
			for(int j=0;j!=len;++j){
				if(i>>j&1)
					one_vec.push_back(S[j]);
			}
			sort_vec.insert(one_vec);
		}
		return vector<vector<int>>(sort_vec.begin(),sort_vec.end());
	}
};