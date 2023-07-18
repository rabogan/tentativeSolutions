/*
1) It's clear that conversion of the strings to canonical form will make them easy to group!

2)  A hash table can be used to handle the grouping:
unordered_map<string,vector<string>>myMap;

3)  It's necessary to try and find the minimum string.  The min string begins "a".
However, to see how much our letters shift, we'll use the FIRST LETTER to find the difference/shift
int diff = s[0] - 'a';
This will allow us to see how many steps happened, e.g:
If s[0] = 'd', then diff = 3    Because s[0]-'a' == 'd'-'a' == 3!
If s[0]= 'z', then diff = 25    Because s[0]-'a' == 'z'-'a' == 25!

4)  So 'd'-->'a'!  In the word daze...
d-->a
a-->x
z-->w
e-->b
daze ---> axwb
Why?  Well, we use that first letter, and then apply this shift to all letters in one pass.
To do so, the key is CIRCULATION or CYCLING, and we use the % operator!  M5 Problem#6 in the course:
https://www.udemy.com/course/skills-coding-interviews/

5)  In detail, the % works like so:
a)  We convert the s[i] to a digit between 0-25:
s[i]-'a'
b)  We then SHIFT or APPLY THE DIFF:
s[i]-'a'-diff
c)  The +26)%26 part handles any -ve values, allowing 'a' to return to 'x', for example
(s[i]-'a'-diff-26)%26
d)  Finally, to convert this calculation to a character, we use 'a'+
'a'+(s[i]-'a'-'diff'+26)%26;
e)  This is ALL use to add a character to our result string!
result+='a'+(s[i]-'a'-diff-26)%26;

6)  Anyway, let's retreat back to STEP 2!  
We know that we want to canonicalize the strings, and group them according to canonical form.
To do so, we can use
myMap[canonical(strings[i])].push_back(strings[i]);

7)  When we group the results together in our return, we need to extract the 2nd part of map, one vector at a time
Iteration is a little tricky, but:
for(auto&p:myMap)
  result.push_back(p.second);
  
8)  ALL DONE!
 */

class Solution {
public:
    string canonical(const string&s){
        string t;
        int diff = s[0]-'a';
        for(int i = 0; i < s.size(); i++){
            t+='a'+(s[i]-'a'-diff+26)%26;
        }
        return t;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>>myMap;
        int sz = strings.size();
        for(int i = 0; i < sz; i++){
            myMap[canonical(strings[i])].push_back(strings[i]);
        }
        vector<vector<string>>result;
        for(auto&p:myMap)
            result.push_back(p.second);
        
        return result;
    }
};
