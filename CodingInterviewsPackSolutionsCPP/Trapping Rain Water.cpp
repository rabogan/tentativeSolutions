class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int mxIndex = 0;
        for(int i = 1; i < sz; i++){
            if(height[i]>height[mxIndex])
                mxIndex = i;
        }
        int maxLeft = 0;
        int maxRight = 0;
        int answer = 0;
        
        for(int i = 0; i < mxIndex; i++){
            maxLeft = max(maxLeft,height[i]);
            answer+=maxLeft-height[i];
        }
        for(int i = sz-1; i>mxIndex; i--){
            maxRight = max(maxRight,height[i]);
            answer+=maxRight-height[i];
        }
        return answer;
    }
};
