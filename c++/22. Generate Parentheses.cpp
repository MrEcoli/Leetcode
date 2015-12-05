class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return vector<string>(1, "") ;
		if (n == 1) return vector<string>(1, "()") ;

		vector<string> ret;
		for (int i = 0; i != n; ++i){
			for (string s1 : generateParenthesis(i)){
				for (string s2 : generateParenthesis(n - i - 1)){
					ret.push_back(s2 + "(" + s1 + ")");
				}
			}
		}
		return ret;
	}
};
