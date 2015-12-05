

//深搜


class Solution {
public:
	vector<int> QueenInRow;
	vector<int> QueenInDiag1;
	vector<int> QueenInDiag2;
	vector<vector<string> > solveNQueens(int n) {
		QueenInRow = vector<int>(n, 0);
		QueenInDiag1 = vector<int>(2 * n, 0);
		QueenInDiag2 = vector<int>(2 * n, 0);
		vector<vector<string>> ret;
		
		dfs(ret, vector<string>(), 0, n);

		return ret;
	}
	
	void dfs(vector<vector<string>> &ret, vector<string> cur, int row, int n){
		if (row == n){
			ret.push_back(cur);
			return;
		}

		for (int col = 0; col != n; ++col){
			if (QueenInRow[col] == 0 && QueenInDiag1[col+row] == 0 && QueenInDiag2[col - row + n-1] == 0){
				QueenInRow[col] = 1;
				QueenInDiag1[col + row] = 1;
				QueenInDiag2[col - row + n - 1] = 1;
				string s(n, '.');
				s[col] = 'Q';
				cur.push_back(s);

				dfs(ret, cur, row + 1, n);

				cur.pop_back();
				QueenInRow[col] = 0;
				QueenInDiag1[col + row] = 0;
				QueenInDiag2[col - row + n - 1] = 0;
			}
		}
	}
};



//回溯，剪枝

class Solution {
public:
	vector<int> QueenInRow;
	vector<int> QueenInDiag1;
	vector<int> QueenInDiag2;
	vector<vector<string> > solveNQueens(int n) {
		QueenInRow = vector<int>(n, 0);
		QueenInDiag1 = vector<int>(2 * n, 0);
		QueenInDiag2 = vector<int>(2 * n, 0);
		vector<vector<string>> ret;
		
		vector<string> cur;

		int row = 0;
		int start = 0;
		bool find = false;
		stack<int> stk;
		while (row >= 0)
		{
			for (int col = start; col < n; ++col){
				if (QueenInRow[col] == 0 && QueenInDiag1[row + col] == 0 && QueenInDiag2[col - row + n - 1] == 0){
					find = true;
					
					QueenInRow[col] = 1;
					QueenInDiag1[col + row] = 1;
					QueenInDiag2[col - row + n - 1] = 1;
					stk.push(col);
					string s(n, '.');
					s[col] = 'Q';
					cur.push_back(s);
					break;
				}
			}

			if (find && row == n-1){
				ret.push_back(cur);
				int last = stk.top();
				stk.pop();
				cur.pop_back();
				QueenInRow[last] = 0;
				QueenInDiag1[last + row] = 0;
				QueenInDiag2[last - row + n - 1] = 0;

				start = last + 1;
				find = false;
			}else if (find){
				row++;
				start = 0;
				find = false;
			}
			else{
				if (stk.empty()){
					break;
				}
				row--;
				cur.pop_back();
				int last = stk.top();
				stk.pop();
				QueenInRow[last] = 0;
				QueenInDiag1[last + row] = 0;
				QueenInDiag2[last - row + n - 1] = 0;
				start = last + 1;
			}
		}

		return ret;
	}
};