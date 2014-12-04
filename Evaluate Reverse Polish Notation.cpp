/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> res;
		for(auto iter = tokens.begin(); iter != tokens.end(); ++iter){
			string s = *iter;
			if(s.size() >1 || isdigit(s[0]))
				res.push(stoi(s));
			else{
				int val1 = res.top();
				res.pop();
				int val2 = res.top();
				res.pop();
				if(s == "+"){
					res.push(val1 + val2);
				}else if(s == "-"){
					res.push(val2 - val1);
				}else if(s == "*"){
					res.push(val2 * val1);
				}else{
					res.push(val2/val1);
				}
			}
		}
		return res.top();
    }
};

