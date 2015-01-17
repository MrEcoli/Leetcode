class Solution {
public:
	void solve(vector<vector<char>> &board){
		if(board.empty()) return;
		auto hgt=board.size();
		auto len=board[0].size();
		for(size_t i=0;i!=len;++i){
			block_bfs(board,0,i);
			block_bfs(board,hgt-1,i);
		}
		for(size_t j=0;j!=hgt;++j){
			block_bfs(board,j,0);
			block_bfs(board,j,len-1);
		}

		for(size_t i=0;i!=hgt;++i){
			for(size_t j=0;j!=len;++j){
				if(board[i][j]=='O')
					board[i][j]='X';
				if(board[i][j]=='A')
					board[i][j]='O';
			}
		}
		return;
	}
	void block_bfs(vector<vector<char>> &board, int i, int j){
		int hgt=board.size();
		int len=board[0].size();
		if(board[i][j]=='X')
			return;
		board[i][j]='A';
		typedef pair<int,int> state;
		auto is_valid=[&](const state &pos)->bool{
			int m=pos.first;
			int n=pos.second;
			if(m<0||n<0||m>=hgt||n>=len||board[m][n]!='O')
				return false;
			board[m][n]='A';
			return true;
		};
		auto find_next_block=[&](const state &pos)->vector<state>{
			vector<state> result;
			int x=pos.first;
			int y=pos.second;
			state adjcent_pos[4]={make_pair(x,y-1),make_pair(x,y+1),make_pair(x-1,y),make_pair(x+1,y)};
			for(int k=0;k!=4;++k){
				if(is_valid(adjcent_pos[k])){
					result.push_back(adjcent_pos[k]);
				}
			}
			return result;
		};
		queue<state> blocks_queue;
		blocks_queue.push(make_pair(i,j));
		while(!blocks_queue.empty()){
			state temp=blocks_queue.front();
			blocks_queue.pop();
			auto newblocks=find_next_block(temp);
			if(!newblocks.empty()){
				for(int i=0;i!=newblocks.size();++i){
					blocks_queue.push(newblocks[i]);
				}
			}
		}
	}
};