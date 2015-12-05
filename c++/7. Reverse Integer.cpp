class Solution {
public:
	int reverse(int x) {

		bool sign = x < 0 ? false : true;

		unsigned y = x < 0 ? -x : x;

		unsigned ret = 0;

		while (y){
			ret = ret * 10 + y % 10;
			y = y / 10;
			if (y && ret > INT_MAX/10){
				return 0;
			}
		}

		if (ret > INT_MAX)
			return 0;
		int res = ret;

		if (res < 0){
			return 0;
		}

		return sign ? res : -res;

	}
};