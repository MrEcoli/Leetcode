class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.size() == 0){
			return false;
		}
		if (board[0].size() == 0){
			return false;
		}

		int n = board.size(), m = board[0].size();
		int length = word.size();


		vector<vector<int>> visited(n, vector<int>(m, 0));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == word[0] &&search(visited, board, i, j, word, 0)){
					return true;
				}
			}
		}
		return false;

	}

	bool search(vector<vector<int>> &visited, vector<vector<char>> &board, int start, int end, string &word, int cur_pos){
		if (cur_pos == word.size()){
			return true;
		}
		int n = board.size(), m = board[0].size();
		int length = word.size();

		if (start < 0 || end < 0 || start >= n || end >= m || board[start][end] != word[cur_pos] || visited[start][end]){
			return false;
		}
		visited[start][end] = 1;
		if (search(visited, board, start + 1, end, word, cur_pos + 1) || search(visited, board, start - 1, end, word, cur_pos + 1) || search(visited, board, start, end + 1, word, cur_pos + 1) || search(visited, board, start, end - 1, word, cur_pos + 1))
			return true;
		visited[start][end] = 0;
		return false;
	}
};