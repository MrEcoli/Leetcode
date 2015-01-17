




//深搜，大数据超时

class Solution {
public:

	int calculateMinimumHP(vector<vector<int> > &dungeon) {
		min_Kight = INT_MAX;
		m = dungeon.size();
		n = dungeon[0].size();
		dfs(dungeon, 0, 0, 1, 0);

		return min_Kight;
	}

	void dfs(vector<vector<int>> &dungeon, int x, int y, int cur_knight, int cur_min){

		if (x>= m || y>= n){
			return;
		}

		if (cur_knight + dungeon[x][y] >= 1){
			cur_knight += dungeon[x][y];
		}
		else
		{
			cur_knight = 1;
			cur_min += 1 - (cur_knight + dungeon[x][y]);
		}

		if (x == m-1 && y == n-1){
			if (cur_min <min_Kight){
				min_Kight = cur_min;
			}
			return;
		}

		dfs(dungeon, x + 1, y, cur_knight, cur_min);
		dfs(dungeon, x, y+1, cur_knight, cur_min);
		return;
	}

	int min_Kight;
	int m, n;

};