const int MAX = 100+1;
int memory[MAX];
string str;

class Solution {
public:
    bool can2Digit(int index){
        if(index+1 >=str.size())
            return false;
        if(str[index]=='1')
            return true;
        return str[index]=='2' && str[index+1]<='6';
    }
    
    int countWays(int index){
        if(index==str.size())
            return 1;
        if(str[index]=='0')
            return 0;
        auto&ret = memory[index];
        if(ret!=-1)
            return ret;
        ret = countWays(index+1);
        if(can2Digit(index))
            ret+=countWays(index+2);
        return ret;
    }
    
    int numDecodings(string s) {
        str = s;
        memset(memory,-1,sizeof(memory));
        return countWays(0);
    }
};