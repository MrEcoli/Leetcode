class Solution {
public:
	int atoi(const char *str) {
		if (str == nullptr){
			return 0;
		}

		while (*str == ' ' || *str == '\t')
		{
			str++;
		}

		if (*str == '\0'){
			return 0;
		}

		bool sign = true;

		if (*str == '+'){
			sign = true;
			str++;
		}else if (*str == '-'){
			sign = false;
			str++;
		}
		
		unsigned val = 0;

		while (*str)
		{
			if (!isdigit(*str)){
				break;
			}

			val = val * 10 + (*str - '0');
			cout << "current val = " << val << endl;
			str++;
			if (isdigit(*str) && val > INT_MAX/10){
				return sign ? INT_MAX : INT_MIN;
			}
		}
		
		int res = val;
		if (res < 0){
			return sign ? INT_MAX : INT_MIN;
		}
		
		return sign ? res : -res;
	}
};
