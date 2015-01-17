class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> toindex;
		size_t n = numbers.size();
		for(int i = 0; i != n; ++i){
			toindex[numbers[i]] = i;
		}
		vector<int> res;
		for(int j = 0; j != n; ++j){
			int another = target - numbers[j];
			if(toindex.find(another) != toindex.end() && toindex[another] != j){
				res.push_back(j + 1);
				res.push_back(toindex[another] +1 );
				break;
			}
		}
		return res;
    }
};