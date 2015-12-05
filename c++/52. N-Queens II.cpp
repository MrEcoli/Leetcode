class Solution {
public:
	vector<int> QueenInRow;
	vector<int> QueenInDiag1;
	vector<int> QueenInDiag2;
	int totalNQueens(int n) {
		if (n < 1)
			return 0;

		QueenInRow = vector<int>(n, 0);
		QueenInDiag1 = vector<int>(2 * n, 0);
		QueenInDiag2 = vector<int>(2 * n, 0);

		int row = 0;
		int start = 0;
		bool find = false;
		stack<int> stk;
		int total = 0;
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
					break;
				}
			}

			if (find && row == n-1){
				++total;
				int last = stk.top();
				stk.pop();
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
				int last = stk.top();
				stk.pop();
				QueenInRow[last] = 0;
				QueenInDiag1[last + row] = 0;
				QueenInDiag2[last - row + n - 1] = 0;
				start = last + 1;
			}
		}

		return total;
	}
};