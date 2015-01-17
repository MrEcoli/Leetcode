class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int n = strlen(s);

		string str(s, s + n);
		int pos = str.find_last_not_of(' ');

		if (pos == string::npos){
			return 0;
		}

		int bg = pos;

		while (bg >= 0 && str[bg] != ' ')
		{
			bg--;
		}

		return pos - bg;
	}
};


 //Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
