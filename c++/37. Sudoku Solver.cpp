class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {

		solveSudoku(board, 0);
		return;
	}

	bool solveSudoku(vector<vector<char> > &board, int start){

		for (int r = start; r != 9; ++r){
			for (int c = 0; c != 9; ++c){
				if (board[r][c] == '.'){
					for (int k = 1; k != 10; ++k){
						board[r][c] = k + '0';
						if (isvalid(board, r, c) && solveSudoku(board, r)){
							return true;
						}
						board[r][c] = '.';
					}
					return false;
				}
			}
		}
		
		return true;
	}

	bool isvalid(vector<vector<char>> &board, int x, int y){
		vector<int> visited(10, 0);

		for (int i = 0; i != 9; ++i){
			if (board[i][y] != '.'){
				int val = board[i][y] - '0';
				if (visited[val]){
					return false;
				}
				visited[val] = 1;
			}
		}

		fill(visited.begin(), visited.end(), 0);

		for (int i = 0; i != 9; ++i){
			if (board[x][i] != '.'){
				int val = board[x][i] - '0';
				if (visited[val]){
					return false;
				}
				visited[val] = 1;
			}
		}

		fill(visited.begin(), visited.end(), 0);

		int m = (x / 3) * 3, n = (y % 3) * 3;

		for (int i = 0; i != 3; ++i){
			for (int j = 0; j != 3; ++j){
				if (board[m+i][n+j] != '.'){
					int val = board[m + i][n + j] - '0';
					if (visited[val]){
						return false;
					}
					visited[val] = 1;
				}
			}
		}
		
		return true;
	}


};