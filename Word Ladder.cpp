/*


Word Ladder Total Accepted: 21828 Total Submissions: 118709 My Submissions Question Solution 
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/


class Solution {
public:
	int ladderLength(const string& start, const string &end, const unordered_set<string> &dict){
		unsigned n = start.size();
		unordered_set<string> dict2 = dict;
		dict2.insert(end);
		unsigned step = 1;
		unordered_map<string, bool> visited;
		for(auto it = dict2.begin(); it != dict2.end(); ++it){
			visited[*it] = false;
		}
		queue<string> cur_que, next_que;
		
		cur_que.push(start);
		visited[start] = true;
		while(!cur_que.empty() || !next_que.empty()){
			++step;
			while(!cur_que.empty()){
				string s = cur_que.front();
				cur_que.pop();
				for(int i = 0; i != n; ++i){
					char ori = s[i];
					string ss= s;
					for(char c = 'a'; c != 'z'+1; c += 1){
						if(c == ori)
							continue;
						else{
							ss[i] = c;
							if(dict2.find(ss) != dict2.end() && !visited[ss]){
								visited[ss] = true;
								next_que.push(ss);
							}
						}
					}
				}
			}

			if(visited[end])
				break;
			cur_que.swap(next_que);
		}

		if(visited[end])
			return step;
		else
			return 0;
	}

};
