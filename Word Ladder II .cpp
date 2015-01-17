/*

Word Ladder II Total Accepted: 13222 Total Submissions: 114690 My Submissions Question Solution 
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.


*/


class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		unsigned n = start.size();
		dict.insert(end);
		unordered_map<string, vector<string>> prevWord;
		unordered_map<string, bool> visited;
		vector<vector<string>> res;
		for(auto it = dict.begin(); it != dict.end(); ++it){
			visited[*it] = false;
		}

		visited[start] = true;
		queue<string> cur_que;
		queue<string> next_que;
		cur_que.push(start);
		while((!cur_que.empty() || !next_que.empty()) && !visited[end]){
			if(cur_que.empty()){
				cur_que.swap(next_que);
			}

			set<string> wait_visited;
			while(!cur_que.empty()){
				string s = cur_que.front();
				cur_que.pop();
				for(int i = 0; i != n; ++i){
					string ss = s;
					char ori = s[i];
					for(char a ='a'; a != 'z'+1; a += 1){
						if(a == ori)
							continue;
						ss[i] = a;
						if(dict.find(ss) != dict.end() && visited[ss] == false){
							wait_visited.insert(ss);
							prevWord[ss].push_back(s);
						}
					}
				}
			}

			for(auto it = wait_visited.begin(); it != wait_visited.end(); ++it){
				visited[*it] = true;
				cur_que.push(*it);
			}
		}

		vector<string> path;
		path.push_back(end);
		dfs(res, start, end, path, prevWord);
		for(auto i = 0; i != res.size(); ++i){
			reverse(res[i].begin(), res[i].end());
		}

		return res;
	}

	void dfs(vector<vector<string>> &res, string start, string cur, vector<string> &path, unordered_map<string, vector<string>> &prevWord){
		if(start == cur){
			res.push_back(path);
			return;			
		}

		for(auto it = prevWord[cur].begin(); it != prevWord[cur].end(); ++it){
			path.push_back(*it);
			dfs(res, start, *it, path, prevWord);
			path.pop_back();
		}
		
	}

};