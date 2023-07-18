const int MAX = 5000+1;
int memory[MAX][2][3];
vector<int>prices;

enum{
    NOTHING = 0, SELL = 1, BUY = 2
};

class Solution {
public:
    int profit(int index, int hasStock, int lastTrans){
        if(index>=prices.size())
            return 0;
        auto&ret = memory[index][hasStock][lastTrans];
        if(ret!=-1)
            return ret;
        int doNothing = profit(index+1,hasStock,NOTHING);
        int buy = 0;
        int sell = 0;
        if(hasStock)
            sell = prices[index]+profit(index+1,0,SELL);
        else if(lastTrans!=SELL)
            buy = -prices[index]+profit(index+1,1,BUY);

        return ret = max(doNothing,max(buy,sell));
    }

    int maxProfit(vector<int>& prices_) {
        prices = prices_;
        memset(memory,-1,sizeof(memory));
        return profit(0,0,NOTHING);
    }
};