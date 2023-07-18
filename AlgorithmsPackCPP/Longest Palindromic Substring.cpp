const int MAX = 1000+1;
int memory[MAX][MAX];
string str;

class Solution {
public:
    bool isValid(int i, int j){
        if(i>=j)
            return true;
        
        auto&ret = memory[i][j];
        if(ret!=-1)
            return ret;
        
        if(str[i]==str[j])
            return ret = isValid(i+1,j-1);
        
        return false;
    }
    
    string longestPalindrome(string s) {
        str = s;
        memset(memory,-1,sizeof(memory));
        int length = 0;
        int startIndex = 0;
        
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                int len = j-i+1;
                if(isValid(i,j) && len > length){
                    length = len;
                    startIndex = i;
                }
            }
        }
        return s.substr(startIndex,length);
    }
};
