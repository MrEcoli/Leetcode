class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		   vector<string> result;
			vector<int> path;
			dfs_ip_address(result, path, s, 0,0);
			return result;
    }
	void dfs_ip_address(vector<string> &result,vector<int> &path, string &s, int start, int ip_num){
		if(ip_num==3)
			if(is_valid_ip(s.substr(start))){
				path.push_back(start);
				string temp=s;
				for(int i=3;i>=0;--i){
					if(path[i]!=0)
						temp.insert(path[i],".");
				}
				result.push_back(temp);
				path.pop_back();
				return;
			}
		int len = s.size();
		for(int i=1;i!=4;++i){
			if((len-start-i)>3*(3-ip_num)||(len-start-i)<(3-ip_num))
				continue;
			if(is_valid_ip(s.substr(start,i))){
				path.push_back(start);
				dfs_ip_address(result, path, s,start+i, ip_num+1);
				path.pop_back();
			}
		}
	}

	bool is_valid_ip(string str){
		int ip_address=stoi(str);
			if(str[0]=='0'){
				if(str.size()!=1)
					return false;
			}
		return ip_address<256;
	}
};