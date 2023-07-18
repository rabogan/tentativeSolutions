class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>charToIndex;
        int sz = s.size();
        int result = 0;
        for(int start = 0, end = 0; end < sz; end++){
            if(charToIndex.count(s[end]))
                start = max(start, charToIndex[s[end]]+1);
            charToIndex[s[end]] = end;
            result = max(result,end-start+1);
        }
        return result;
    }
};
