class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int sz = dist.size();
        vector<int>arrivalTime(sz);
        for(int i = 0; i < sz; i++){
            if(dist[i]%speed[i]==0)
                arrivalTime[i] = dist[i]/speed[i];
            else
                arrivalTime[i] = dist[i]/speed[i]+1;
        }
        sort(arrivalTime.begin(),arrivalTime.end());
        
        int monster = 0;
        for(int i = 0; i < arrivalTime.size() && i < arrivalTime[monster]; i++)
            monster++;
        
        return monster;
    }
};
