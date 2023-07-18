const int MAX = 500+1;
int memory[MAX];
vector<int>arr;
int k;

class Solution {
public:
    int partition(int start){
        if(start==arr.size())
            return 0;
        
        auto&ret = memory[start];
        if(ret!=-1)
            return ret;
        
        ret = INT_MIN;
        int mxValue = INT_MIN;
        for(int split = start; split<start+k; split++){
            if(split>=arr.size())
                break;
            mxValue = max(mxValue,arr[split]);
            int len = split-start+1;
            ret = max(ret, len*mxValue+partition(split+1));
        }
        return ret;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr_, int k_) {
        arr = arr_;
        k = k_;
        memset(memory,-1,sizeof(memory));
        return partition(0);
    }
};