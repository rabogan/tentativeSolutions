const int MAX = 1000+1;
int memory[MAX];
vector<vector<int>>books;
int shelfWidth;

class Solution {
public:
    int arrange(int index){
        if(index>=books.size())
            return 0;
        
        auto&ret = memory[index];
        if(ret!=-1)
            return ret;
        
        ret = INT_MAX;
        int width = 0;
        int mxHeight = 0;
        
        for(int split = index; split < books.size(); split++){
            width+=books[split][0];
            mxHeight = max(mxHeight,books[split][1]);
            if(width>shelfWidth)
                break;
            ret = min(ret,mxHeight+arrange(split+1));
        }
        return ret;
    }
    
    int minHeightShelves(vector<vector<int>>& books_, int shelfWidth_) {
        books = books_;
        shelfWidth = shelfWidth_;
        memset(memory,-1,sizeof(memory));
        return arrange(0);
    }
};