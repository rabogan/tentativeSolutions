const int MAX = 45+1;
int memory[MAX];
int n;
class Solution {
public:
    int climbStairs(int n_) {
        n = n_;
        memory[0] = 1;
        memory[1] = 1;
        for(int i = 2; i<=n; i++){
            memory[i] = memory[i-1]+memory[i-2];
        }
        return memory[n];
    }
};
