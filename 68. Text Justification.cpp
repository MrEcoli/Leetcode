class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string>res;
        int len = words.size(), i = 0;
        while(i < len)
        {
            int rowlen = 0, j = i;
            while(j < len && rowlen + words[j].size() <= L)
                rowlen += (words[j++].size() + 1);
            if(j - i == 1)
            {
                res.push_back(words[i]);
                addSpace(res.back(), L - words[i].size());
                i = j; continue;
            }
            int charaLen = rowlen - (j - i);
            int meanSpace = j < len ? (L - charaLen) / (j - i - 1) : 1;
            int leftSpace = j < len ? (L - charaLen) % (j - i - 1) : L - charaLen - (j - i -1);
            string tmp;
            for(int k = i; k < j - 1; k++)
            {
                tmp += words[k];
                addSpace(tmp, meanSpace);
                if(j < len && leftSpace > 0)
                {
                    tmp.push_back(' ');
                    leftSpace--;
                }
            }
            tmp += words[j - 1];
            if(leftSpace > 0)addSpace(tmp, leftSpace); 
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
     
    void addSpace(string &s, int count)
    {
        for(int i = 1; i <= count; i++)
            s.push_back(' ');
    }
};
 