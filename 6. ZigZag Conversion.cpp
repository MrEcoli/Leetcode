class Solution {
public:
	string convert(string s, int nRows) {
		vector<string> strs(nRows);
		if (nRows == 1){
			return s;
		}

		int n = s.size();
		int cycle = nRows * 2 - 2;

		for (int i = 0; i != n; ++i){
			int pos = i % cycle;
			if (pos >= nRows){
				pos = (nRows - 1) - (pos % (nRows - 1));
			}
			strs[pos].insert(strs[pos].end(), s[i]);
		}
		string res;
		for (string s: strs){
			res.append(s);
		}
		return res;
	}
};