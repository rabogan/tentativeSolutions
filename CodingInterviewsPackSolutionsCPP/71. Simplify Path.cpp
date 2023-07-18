class Solution {
public:
    vector<string>split(const string&path, char separator = '/'){
        vector<string>result;
        string cur;
        
        for(int idx = 0; idx < path.size(); idx++){
            if(path[idx]==separator){
                result.push_back(cur);
                cur = "";
            }else
                cur+=path[idx];
        }
        
        if(cur.size())
            result.push_back(cur);
        
        return result;
    }
    
    string simplifyPath(string path) {
        vector<string>tokens = split(path);
        vector<string>stk;
        
        for(int idx = 0; idx < tokens.size(); idx++){
            if(tokens[idx]==""||tokens[idx]==".")
                continue;
            
            if(tokens[idx]==".."){
                if(!stk.empty())
                    stk.pop_back();
            }else
                stk.push_back(tokens[idx]);
        }
        if(stk.empty())
            return "/";
        
        string result;
        for(int idx = 0; idx < stk.size(); idx++)
            result+="/"+stk[idx];
        return result;
    }
};