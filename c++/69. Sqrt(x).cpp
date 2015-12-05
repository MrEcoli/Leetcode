class Solution {
public:
	int sqrt(int x) {
		if ( x == 0){
			return 0;
		}

		if (x <0){
			return -1;
		}

		int lower = 1, upper = x;

		int res = (lower + upper) >> 1;

		while (lower <= upper){
			res = (lower + upper) >> 1;

			if (x/res >= res && x/(res+1) < (res +1)){
				return res;
			}
			if (x/res > res){
				lower = res + 1;
			}
			else{
				upper = res - 1;
			}


		}

		return res;
	}
};
