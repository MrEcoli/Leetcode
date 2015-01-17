class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int n = num.size();
		if (n<2){
			return;
		}
		int pos = -1;

		int swap_pos;

		for (int i = n - 2; i >= 0; --i){
			if (num[i] < num[i+1]){
				pos = i;
				cout << pos << endl;
				break;
			}
		}
		if (pos == -1){
			reverse(num.begin(), num.end());
			return;
		}

		for (int i = n - 1; i != pos; --i){
			if (num[i] > num[pos]){
				swap_pos = i;
				cout << swap_pos << endl;
				break;
			}
		}
		swap(num[pos], num[swap_pos]);

		reverse(num.begin() + pos+1, num.end());
	}
};
