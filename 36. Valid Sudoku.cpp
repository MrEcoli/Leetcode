class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		vector<int> visited(10, 0);

		for (int i = 0; i != 9; ++i){
			for (int j = 0; j != 9; ++j){
				if (board[i][j] != '.' ){
					int val = board[i][j] - '0';
					if (visited[val]){
						return false;
					}
					visited[val] = true;
				}
			}
			fill(visited.begin(), visited.end(), 0);
		}
		for (int i = 0; i != 9; ++i){
			for (int j = 0; j != 9; ++j){
				if (board[j][i] != '.'){
					int val = board[j][i] - '0';
					if (visited[val]){
						return false;
					}
					visited[val] = 1;
				}
			}
			fill(visited.begin(), visited.end(), 0);
		}
		fill(visited.begin(), visited.end(), 0);

		for (int k = 0; k != 9; ++k){
			int x = (k / 3) * 3, y = (k % 3) * 3;
			for (int i = 0; i != 3; ++i){
				for (int j = 0; j != 3; ++j){
					if (board[x+i][y+j] != '.'){
						int val = board[x + i][y + j] - '0';
						if (visited[val]){
							return false;
						}
						visited[val] = 1;
					}
				}
			}
			fill(visited.begin(), visited.end(), 0);
		}
		return true;
	}
};
