class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int sz = words.size();
        vector<int>pos(sz);
        int matchingWords = 0;
        unordered_map<char,vector<int>>charToIndices;
        for(int i = 0; i < sz; i++)
            charToIndices[words[i][0]].push_back(i);
        
        for(int i = 0; i < s.size(); i++){
            char ch1 = s[i];
            vector<int>wordIndices = charToIndices[ch1];
            charToIndices[ch1].clear();
            
            for(int j = 0; j < wordIndices.size(); j++){
                int idx = wordIndices[j];
                string word = words[idx];
                pos[idx]++;
                
                if(pos[idx]==word.size())
                    matchingWords++;
                else{
                    char ch2 = word[pos[idx]];
                    charToIndices[ch2].push_back(idx);
                }
            }
        }
        return matchingWords;
    }
};
/*
SOLUTION
1)  We need to create a map of char to vector<int>.  
In this, words[i][0] gives a vector of indices where 
words[i][0] is the first letter.  To help us find the 
answer, we need a vector<int>pos (matching the number 
of words in words), and a result variable (matchingWords)
We want to calculate the number of 'matching words':
a)  We go through our words, and map the FIRST character 
of each word to the respective INDICES in the vector<string>words
b)  We need a vector<int>pos - this will record sizes of
matching letters/strings for each word in the words vector

2) We then iterate through our larger string!  This is 
the 'retrieval' step.  We basically use two lines to retrieve 
the indices mentioned in 1.  We want the vector<int>wordIndices.
This is the vector of indices associated with the character in 
the string.  After that, we clear the map - FOR THAT CHARACTER!
Basically, this is done to prevent something like "aaaaa" or "bb" 
being dealt with incorrectly  So, grab the word indices vector,
and don't forget to clear the map for that character!

3) Next is our UPDATE step.  It's relatively easy, with one trick!
We get the idx, and then grab the full word from that index.
Remember vector<int>pos in 1?  It's storing the sizes found so 
far at each index in words.  We INCREMENT vector<int>pos...
i.e. pos[idx]++;  We, of course, have already found our 
index (wordIndices[j]) and word (string word = words[idx])

4)  After that, we still need to update!  However, most 
importantly, we must increment our matchingWords variable
if a match was found!  if(pos[idx].size()==word.size()), increment!
We COMPARE the pos[idx] to the size of the WORD gleaned in step 3!

5)  If the word.size()!=pos[idx], then we update our map 
(we have more letters to process).  We grab the character of the
word (word[pos[idx]]) 
Then update the map!  charToIndices[ch2].push_back(idx);
*/
