


class Solution {
public:
	double pow(double x, int n) {
		if (n == 0)
			return 1;

		double val = pow(x, n / 2);

		if ((n & 1) == 0)
			return val *val;
		else{
			if (n < 0)
				return val*val / x;
			else
				return val*val*x;
		}
	}

};