class Solution {
public:
	int divide(int dividend, int divisor) {
		int result = 0;

		if (dividend == INT_MIN && divisor == -1)
		{
			return INT_MAX;
		}

		bool sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

		unsigned x = dividend > 0 ? dividend : -dividend;
		unsigned y = divisor >0 ? divisor : -divisor;

		while (x >= y)
		{
			int cur_multipy = 1;
			unsigned yy = y;
			while (x >= yy)
			{
				x -= yy;
				result += cur_multipy;

				if (yy < INT_MAX>>1){
					yy <<= 1;
					cur_multipy <<= 1;
				}
			}
		}
		
		return sign ? result : -result;
	}
};
