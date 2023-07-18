const int MAX = 1000+1;
int memory[MAX][MAX];
string word1;
string word2;

class Solution {
public:
    int LCS(int i, int j){
        if(i>=word1.size() || j>=word2.size())
            return 0;
        auto&ret = memory[i][j];
        if(ret!=-1)
            return ret;
        if(word1[i]==word2[j])
            return 1+LCS(i+1,j+1);

        int insertLeft = LCS(i+1,j);
        int insertRight = LCS(i,j+1);

        return ret = max(insertLeft,insertRight);
    }

    int longestCommonSubsequence(string text1, string text2) {
        word1 = text1;
        word2 = text2;
        memset(memory,-1,sizeof(memory));
        return LCS(0,0);
    }
};
