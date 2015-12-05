

//递归版本，会超时

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*s == '\0' && *p == '\0'){
			return true;
		}

		if (*p == '?'){
			if (*s == '\0'){
				return false;
			}
			return isMatch(s + 1, p + 1);
		}else if (*p == '*'){
			while (*p == '*')
			{
				p++;
			}

			int n = strlen(s);
			for (int i = 0; i <= n; ++i){
				if (isMatch(s+i, p)){
					return true;
				}
			}
			return false;
		}else if (*s == *p){
			return isMatch(s + 1, p + 1);
		}
		else{
			return false;
		}
	}
};


//迭代版本，贪心算法。

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
	
		int n = strlen(s), m = strlen(p);
		bool star = false;
		const char *sptr = s, *pptr = p;

		while(*sptr != '\0'){
			if (*pptr == '?'){
				sptr++;
				pptr++;
			}else if (*pptr == '*'){
				star = true;
				while (*pptr == '*')
				{
					pptr++;
				}
				if (*pptr == '\0'){
					return true;
				}
				s = sptr;
				p = pptr;
			}else if (*sptr != *pptr){
				if (!star){
					return false;
				}
				s++;
				sptr = s;
				pptr = p;
			}
			else{
				sptr++;
				pptr++;
			}
		}

		while (*pptr == '*')
		{
			pptr++;
		}

		return *pptr == '\0';
	}
};
