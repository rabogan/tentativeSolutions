const int MAX_T = 5000+1;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int memory[MAX_T];
        memset(memory,0,sizeof(memory));
        memory[0] = 1;
        int sz = coins.size();
        for(int idx = 0; idx < sz; idx++){
            for(int target = 0; target<=amount; target++){
                if(target-coins[idx]>=0)
                    memory[target]+=memory[target-coins[idx]];
            }
        }
        return memory[amount];
    }
};