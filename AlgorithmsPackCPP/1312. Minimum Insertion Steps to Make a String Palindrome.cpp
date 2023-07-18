const int MAX = 500+1;
int memory[MAX][MAX];
string str;

class Solution {
public:
    int insertion(int start, int end){
        if(start>=end)
            return 0;
        
        auto&ret = memory[start][end];
        if(ret!=-1)
            return ret;
        
        if(str[start]==str[end])
            return ret = insertion(start+1,end-1);
        
        int insertLeft = 1+insertion(start+1,end);
        int insertRight = 1+insertion(start,end-1);
        
        return ret = min(insertRight,insertLeft);
    }
    
    int minInsertions(string s) {
        memset(memory,-1,sizeof(memory));
        str = s;
        return insertion(0,str.size()-1);        
    }
};