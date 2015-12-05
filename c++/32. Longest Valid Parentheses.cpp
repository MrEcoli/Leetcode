


class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		if (n <2){
			return 0;
		}

		int last = -1;
		stack<int> stk;
		int max_length = 0;
		for (int i = 0; i != s.size(); ++i){
			if (s[i] == '('){
				stk.push(i);
			}
			else{
				if (stk.empty()){
					last = i;
				}
				else{
					stk.pop();
					if (stk.empty()){
						max_length = max(max_length, i - last);
					}
					else{
						max_length = max(max_length, i - stk.top());
					}
				}
			}
		}
		return max_length;
	}
};