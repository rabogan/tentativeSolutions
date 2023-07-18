class Solution {
public:
    vector<int>canonical(const string&s){
        int sz = s.size();
        unordered_map<char,int>myMap;
        int canonicalIndex = 0;
        vector<int>result(sz);
        
        for(int i = 0; i < sz; i++){
            if(!myMap.count(s[i])){
                myMap[s[i]] = canonicalIndex;
                canonicalIndex++;
            }
            result[i] = myMap[s[i]];
        }
        return result;
    }
    
    bool isIsomorphic(string s, string t) {
        return canonical(s)==canonical(t);
    }
};