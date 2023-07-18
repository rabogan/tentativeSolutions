/*
A basic DP implementation :)

*/

const int MAX = 500+1;
int memory[MAX][MAX];
string str1;
string str2;

class Solution {
public:
    int levenshtein(int i, int j){
        if(i==-1 || j==-1)
            return max(i,j)+1;
        auto&ret = memory[i][j];
        if(ret!=-1)
            return ret;
        if(str1[i]==str2[j])
            return ret = levenshtein(i-1,j-1);
        int change = 1+levenshtein(i-1,j-1);
        int delete_ = 1+levenshtein(i-1,j);
        int insert = 1+levenshtein(i,j-1);
        return ret = min(min(change,delete_),insert);
    }

    int minDistance(string word1, string word2) {
        str1 = word1;
        str2 = word2;
        memset(memory,-1,sizeof(memory));
        return levenshtein(str1.size()-1,str2.size()-1);
    }
};
