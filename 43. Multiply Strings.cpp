class Solution {
public:
	string multiply(string num1, string num2) {
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		string res;

		for (int idx = 0; idx != num1.size(); ++idx){
			res = str_plus(multiply(num2, num1[idx] - '0', idx), res);
		}

		reverse(res.begin(), res.end());

		int pos = res.find_first_not_of('0');

		if (pos == string::npos){
			return string("0");
		}


		return res.substr(pos);


	}



	string multiply(string num1, int digit, int pos){
		int over_flow = 0;

		if (digit == 0){
			return string("0");
		}

		for (int i = 0; i != num1.size(); ++i){
			char c = num1[i] - '0';
			num1[i] = (c * digit + over_flow) % 10 + '0';
			over_flow = (c*digit + over_flow) / 10;
		}

		if (over_flow){
			num1.push_back('0' + over_flow);
		}


		return string(pos, '0') + num1;
	}

	string str_plus(string s1, string s2){
		if (s1.size() < s2.size()){
			return str_plus(s2, s1);Multiply Strings 
		}

		int over_flow = 0;

		for (int i = 0, j = 0; i < s1.size(); ++i, ++j){
			int c1 = s1[i] - '0';
			int c2 = j >= s2.size() ? 0 : (s2[j] - '0');

			s1[i] = (c1 + c2 + over_flow) % 10 + '0';
			over_flow = (c1 + c2 + over_flow) / 10;

		}

		if (over_flow){
			s1.push_back('1');
		}

		/*for (int i = s1.size()-1, j = s2.size()-1; i >= 0; --i, --j){
			int ch1 = s1[i]-'0';
			int ch2 = j < 0 ? 0 : (s2[j] - '0');
			
			s1[i] = (ch1 + ch2 + over_flow) % 10 + '0';
			over_flow = (ch1 + ch2 + over_flow) / 10;
		}
		if (over_flow){
			s1.insert(s1.begin(), '1');
		}*/
		return s1;
	}

};