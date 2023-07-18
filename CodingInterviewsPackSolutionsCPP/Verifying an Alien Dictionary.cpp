class Solution {
    unordered_map<char,int>myMap;
public:
    bool isSmaller(const string&s1, const string&s2){
        int len1 = s1.length();
        int len2 = s2.length();
        
        int len = min(len1,len2);
        
        for(int i = 0; i < len; i++){
            if(s1[i]!=s2[i])
                return myMap[s1[i]]<myMap[s2[i]];
        }
        return len1<len2;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); i++)
            myMap[order[i]] = i;
        
        for(int i = 1; i < words.size(); i++){
            if(words[i-1]!=words[i] && !isSmaller(words[i-1],words[i]))
                return false;
        }
        return true;
    }
};
