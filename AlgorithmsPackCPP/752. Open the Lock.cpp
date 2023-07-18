class Solution {
public:
    char prev(char ch){
        if(ch=='0')
            return '9';
        return ch-1;
    }

    char next(char ch){
        if(ch=='9')
            return '0';
        return ch+1;
    }

    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        if(start==target)
            return 0;

        queue<string>q;
        unordered_set<string>visited(deadends.begin(),deadends.end());
        if(visited.count(start))
            return -1;

        q.push(start);
        visited.insert(start);

        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                string cur = q.front();
                q.pop();

                for(int d = 0; d < 4; d++){
                    cur[d] = prev(cur[d]);
                    if(cur==target)
                        return level+1;
                    if(visited.insert(cur).second)
                        q.push(cur);

                    cur[d] = next(next(cur[d]));
                    if(cur==target)
                        return level+1;
                    if(visited.insert(cur).second)
                        q.push(cur);

                    cur[d] = prev(cur[d]);
                }
            }
        }
        return -1;
    }
};