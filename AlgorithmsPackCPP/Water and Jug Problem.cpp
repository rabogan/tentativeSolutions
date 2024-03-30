class Solution {
    typedef unordered_map<int,unordered_set<int>>HASHSET;
    bool found{};
    void process(queue<vector<int>>&q,HASHSET&visited, int jug1, int jug2, int target){
        if(jug1+jug2==target){
            found = true;
            return;
        }
        if(jug1>jug2)
            swap(jug1,jug2);
        if(visited[jug1].insert(jug2).second){
            q.push({jug1,jug2});
        }
    }
public:
    bool canMeasureWater(int CAP1, int CAP2, int target) {
        if(CAP1+CAP2<target)
            return false;

        HASHSET visited;
        queue<vector<int>>q;
        process(q,visited,0,0,target);

        while(!q.empty() && !found){
                int jug1 = q.front()[0];
                int jug2 = q.front()[1];
                q.pop();
                int p1 = min(jug1,CAP2-jug2);
                int p2 = min(CAP1-jug1,jug2);

                process(q,visited,jug1,0,target);
                process(q,visited,0,jug2,target);
                process(q,visited,CAP1,jug2,target);
                process(q,visited,jug1,CAP2,target);
                process(q,visited,jug1-p1,jug2+p1,target);
                process(q,visited,jug1+p2,jug2-p2,target);
        }
        return found;
    }
};
/*You are given two jugs with capacities jug1Capacity and 
jug2Capacity liters. There is an infinite amount of water 
supply available. Determine whether it is possible to 
measure exactly targetCapacity liters using these two jugs.

If targetCapacity liters of water are measurable, you must have 
targetCapacity liters of water contained within one or
both buckets by the end.

Operations allowed:
Fill any of the jugs with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug 
is completely full, or the first jug itself is empty.
*/
