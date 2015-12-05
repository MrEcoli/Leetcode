
class Solution {
public:
	string simplifyPath(string path) {
		string local("/.");
		string prev_dir("/..");
		string cur_dir;
		int pos = 0;
		int n = path.size();

		vector<string> absolute_path;
	
		while (pos < n){
			while (pos < n-1 && (path[pos] != '/' || path[pos+1] =='/'))
				pos++;
			if (pos == n-1 && path[pos] == '/'){
				break;
			}
			int nxt = pos + 1;
			while (nxt < n && path[nxt] != '/'){
				nxt++;
			}
			cur_dir = path.substr(pos, nxt - pos );

			cout << cur_dir << endl;
			if (cur_dir == local){
				pos = nxt;
				continue;
			}else if (cur_dir == prev_dir){
				if (!absolute_path.empty())
					absolute_path.pop_back();
				pos = nxt;
			}
			else
			{
				absolute_path.push_back(cur_dir);
				pos = nxt;
			}
		}

		if (absolute_path.empty()){
			return "/";
		}
		string res;
		for (int i = 0; i != absolute_path.size(); ++i){
			res += absolute_path[i];
		}
		return res;
	}
};
