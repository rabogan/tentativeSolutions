class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq1,freq2;
        for(int i = 0; i < s.size(); i++)
            freq1[s[i]]++;
        for(int i = 0; i < t.size(); i++)
            freq2[t[i]]++;
        if(freq1.size()!=freq2.size())
            return false;
        
        for(const pair<char,int>&p:freq1){
            char ch = p.first;
            int freq = p.second;
            
            if(freq!=freq2[ch])
                return false;
        }
        return true;
    }
};
