class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
        
    
        
		string ret;
		int n = strs.size();
        if(n == 0)
            return ret;
        
		bool find = false;
		int i = 0;
		for (i = 0; i != strs[0].size(); ++i){
			char ch = strs[0][i];
			for (int j = 0; j != n; ++j){
				if (strs[j].size() <= i || strs[j][i] != ch){
					find = true;
					break;
				}
			}
			if (find){
				break;
			}
		}
		
		return ret = strs[0].substr(0, i);
	}
};