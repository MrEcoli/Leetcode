class Solution {
public:
	bool isNumber(const char *s) {
		enum InputType {
			INVALID,		// 0 Include: Alphas, '(', '&' ans so on
			SPACE,		// 1
			SIGN,		// 2 '+','-'
			DIGIT,		// 3 numbers
			DOT,			// 4 '.'
			EXPONENT,		// 5 'e' 'E'
		};
		int transTable[][6] = {
		//0INVA,1SPA,2SIG,3DI,4DO,5E
			-1,  0,  3,  1,  2, -1,//0初始无输入或者只有space的状态
			-1,  8, -1,  1,  4,  5,//1输入了数字之后的状态
			-1, -1, -1,  4, -1, -1,//2前面无数字，只输入了Dot的状态
			-1, -1, -1,  1,  2, -1,//3输入了符号状态
			-1,  8, -1,  4, -1,  5,//4前面有数字和有dot的状态
			-1, -1,  6,  7, -1, -1,//5'e' or 'E'输入后的状态
			-1, -1, -1,  7, -1, -1,//6输入e之后输入Sign的状态
			-1,  8, -1,  7, -1, -1,//7输入e后输入数字的状态
			-1,  8, -1, -1, -1, -1,//8前面有有效数输入之后，输入space的状态
		};
		int state = 0;
		while (*s)
		{
			InputType input = INVALID;
			if (*s == ' ') input = SPACE;
			else if (*s == '+' || *s == '-') input = SIGN;
			else if (isdigit(*s)) input = DIGIT;
			else if (*s == '.') input = DOT;
			else if (*s == 'e' || *s == 'E') input = EXPONENT;
			state = transTable[state][input];
			if (state == -1) return false;
			++s;
		}
		return state == 1 || state == 4 || state == 7 || state == 8;
	}
};





class Solution {
public:
	bool isNumber(const char *s) {
		int n = strlen(s);
		int lf = 0;
		while (s[lf] == ' ' && lf != n)
		{
			lf++;
		}
		if (lf == n){
			return false;
		}

		while (s[n-1] == ' ' && n >= 0)
		{
			n--;
		}
		string str(s + lf, s + n);

		if (str.size() == 0){
			return false;
		}

		bool isfloat = false;
		bool isexponet = false;

		for (int i = 0; i != str.size(); ++i){
			if (str[i] == '.'){
				if (isfloat || isexponet ||str.size() == 1 || ((i == 0 || !isdigit(str[i-1])) && (i == str.size()-1 ||!isdigit(str[i+1])))){
					return false;
				}
				isfloat = true;
			}else if (str[i] == 'E' || str[i] == 'e'){
				if (isexponet|| i == 0 || i == str.size() -1){
					return false;
				}
				isexponet = true;
			}else if (isdigit(str[i])){
				continue;
			}else if (str[i] == '+' || str[i] == '-'){
				if (i == str.size() -1){
					return false;
				}
				if ((i != 0 && (str[i-1] != 'E' && str[i-1] != 'e')) || !(isdigit(str[i+1]) || str[i+1] == '.')){
					return false;
				}
			}
			else{
				return false;
			}
		}
		return true;
	}

};
