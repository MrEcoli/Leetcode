//LeetCode List ÌâÄ¿
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <map>
#include <list>


using namespace std;




struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> result;   
		vector<string> path;
		palindrome_DFS(result,path, s, 0, 0);
		return result;
    }
	void palindrome_DFS(vector<vector<string>> &result, vector<string> &path, string &str, int start, int end){
		if(end==str.size())
			return;
		if(end==(str.size()-1))
			if(is_palindrome(str,start,end)){
				path.push_back(str.substr(start,end-start+1));
				result.push_back(path);
				path.pop_back();
				return;
			}
		palindrome_DFS(result,path,str,start,end+1);
		if(is_palindrome(str,start,end)){
			path.push_back(str.substr(start,end-start+1));
			palindrome_DFS(result,path,str,end+1,end+1);
			path.pop_back();
		}
	}
	bool is_palindrome(string &s, int start, int end){
		while(s[start]==s[end]&&start<end){
			start++;
			end--;
		}
		return start>=end;
	}
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int hgt=obstacleGrid.size();
		int len=obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[hgt-1][len-1])
		    return 0;
		vector<int> dp_ary(len,0);
		dp_ary[0]=1;
		for(int i=0;i!=hgt;++i){
			for(int j=0;j!=len;++j)
				dp_ary[j]=obstacleGrid[i][j]?0:((j==0?0:dp_ary[j-1])+dp_ary[j]);
		}

		return dp_ary[len-1];
    }
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
	vector<vector<int> > combinationSum(vector<int> &nums, int target){
		vector<vector<int>> result;
		vector<int> path;
		sort(nums.begin(), nums.end());

		DFS_Combination(result, nums, path, 0, target, nums.size(), 0);
		return result;
	}
	void DFS_Combination(vector<vector<int>> &result, vector<int> &nums, vector<int> &path, int sum , int target, int len, int start){
		if(sum==target){
			result.push_back(path);
			return;
		}
		
		for(auto i=start;i!=len;++i){
			if((nums[i]+sum)<=target){
				path.push_back(nums[i]);
				DFS_Combination(result, nums, path, sum+nums[i], target, len, i+1);
				path.pop_back();
			}
			if((nums[i]+sum)>target)
				break;

		}
	}
	vector<string> generateParenthesis (int n){
		if(n==0) return vector<string>(1,"");
		if(n==1) return vector<string>(1,"()");
		vector<string> result;
		for(int i=0;i!=n;++i){
			auto inner=generateParenthesis(i);
			auto outer=generateParenthesis(n-1-i);{
				for(int m=0;m!=inner.size();++m){
					for(int n=0;n!=outer.size();++n){
						result.push_back(string("("+inner[m]+")"+outer[n]));
					}
				}
			}
		}
		return result;
	}
	vector<string> generateParenthesis2(int n){
		vector<string> result;
		string s;
		generate(result, s, n, 0, 0);
		return result;
	}
	void generate(vector<string> &result, string s, int n, int l, int r){
		if(l==n){
			s.append(n-r,')');
			result.push_back(s);
			return;
		}
		generate(result, s+"(", n, l+1, r);
		if(l>r)
			generate(result, s+")", n, l, r+1);
	}
	int minPathSum(vector<vector<int> > &grid){
		int hgt=grid.size();
		int len=grid[0].size();
		for(int i=0;i!=hgt;++i){
			for(int j=0;j!=len;++j){
				if(i==0&&j==0)
					continue;
				grid[i][j]=min(i==0?INT_MAX:grid[i-1][j],j==0?INT_MAX:grid[i][j-1])+grid[i][j];
			}
		}
		return grid[hgt-1][len-1];
	}
	int maxSubArray(int A[], int n){
		int maxSum=INT_MIN;
		int curSum=0;
		for(int i=0;i!=n;++i){
			curSum+=A[i];
			maxSum=max(curSum,maxSum);
			if(curSum<0){
				curSum=0;
			}
		}
		return maxSum;
	}
	int maximalRectangle(vector<vector<char> > &matrix){
		int hgt=matrix.size();
		int len=matrix[0].size();
		vector<int> height(len+1,0);
		int maxarea=0;
		for(int i=0;i!=hgt;++i){
			for(int j=0;j!=len;++j){
				if(matrix[i][j]=='1')
					height[j]=height[j]+1;
				else 
					height[j]=0;
			}
			maxarea=max(maxarea, largestRectangle(height));
		}
		return maxarea;
	}
	int largestRectangle(vector<int> height){
		stack<int> s;
		int length=height.size();
		int maxarea=0,area;
		for(int i=0;i!=length;){
			if(s.empty()||height[i]>height[s.top()]){
				s.push(i);
				i++;
			}
			else{
					int temp=s.top();
					s.pop();
					area=height[temp]*(s.empty()?i:(i-s.top()-1));
					maxarea=max(area,maxarea);
			}
		}
		return maxarea;
	}
};


int main(){

	phone_Bills();

	cin.get();
	return 0;

}