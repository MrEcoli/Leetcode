
class Solution {
public:
	string countAndSay(int n) {
		string str("1");

		while (--n){
			str = getNext(str);
		}
		return str;
	}

	string getNext(string str){
		string ret;
		if (str.size() == 1){
			return string("11");
		}

		for (int i = 0; i != str.size(); ++i){
			int count = 1;

			while (i < (str.size()-1) && str[i] == str[i+1])
			{
				i++;
				count++;
			}
			ret = ret + to_string((long long)(count)) + string(1, str[i]);
		}
		return ret;
	}
};