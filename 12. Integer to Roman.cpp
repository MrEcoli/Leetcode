class Solution {
public:
	string intToRoman(int num) {
		string roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int arr[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string res;

		for (int i = 0; num > 0; ++i){
			int count = num / arr[i];
			num %= arr[i];

			while (count--){
				res += roman[i];
			}
		}
		return res;
	}
};
