class Solution {
public:
	string minWindow(string S, string T) {
		int n = S.size(), m = T.size();

		unordered_map<char, int> positions;

		for (int i = 0; i != m; ++i){
			positions[T[i]]++;
		}

		unordered_map<char, int> cur_visted;

		queue<int> que;

		int fill_n = 0;
		int min_length = INT_MAX;
		int start = 0;
		int last = -1;
		for (int i = 0; i != n; ++i){
			char ch = S[i];
			if (positions.find(ch) != positions.end()){
				que.push(i);
				if (cur_visted.find(ch) == cur_visted.end() || cur_visted[ch] < positions[ch]){
					cur_visted[ch]++;
					fill_n++;
					if (last == -1){
						last = i;
					}
					if (fill_n == m && i-last+1 < min_length){
						min_length = i - last + 1;
						start = last;
					}
				}
				else{
					cur_visted[ch]++;

					while (cur_visted[S[last]] > positions[S[last]])
					{
						cur_visted[S[last]]--;
						que.pop();
						last = que.front();
					}

					if (fill_n == m && i - last + 1 < min_length){
						min_length = i - last + 1;
						start = last;
					}

				}
			}
		}

		if (min_length == INT_MAX){
			return "";
		}else
			return S.substr(start, min_length);
	}
};
