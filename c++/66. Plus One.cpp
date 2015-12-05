class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		reverse(digits.begin(), digits.end());
		int add = 1;
		
		for (size_t i = 0; i < digits.size(); i++)
		{
			int tmp = digits[i];
			digits[i] = (digits[i] + add) >9 ? 0 : digits[i] + add;
			
			add = (tmp + add) >9 ? 1 : 0;
		}

		if (add){
			digits.push_back(add);
		}

		reverse(digits.begin(), digits.end());

		return digits;
	}
};
