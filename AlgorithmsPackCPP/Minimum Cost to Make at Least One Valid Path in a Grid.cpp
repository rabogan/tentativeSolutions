/*
In essence, we can treat each jump to a neighboring cell as having a cost of either ONE or ZERO
The deque is used to keep track of cells to be explored, 
with cells that incur no additional cost being explored first to prioritize finding a valid path.

The 2D dist vector is used to keep track of the minimum cost to reach each cell from the starting cell (0, 0). 
Since the problem allows modifying only one sign, the initial value of dist[0][0] is set to 0

The d-dir loop is responsible for exploring the neighboring cells of the current cell and updating their distances if a shorter path is found


1) Initialize a 2D vector DIST with OO for every cell in the grid.  Set dist[0][0] = 0 (the problem allows modding of one cell)
2) Using a deque deq, we store all cells that needs to be visited, starting with {0,0}
3) The algorithm removes the first element of the deque
4) The loop iteratores over where the current cell CAN point to using the DR and DC arrays, to get nr and nc
5) The edgeWeight variable is set to 1 IF the direction being pointed to by the cell is NOT the same as the direction being considered:
i.e. int edgeWeight = d!=(matrix[r][c]-1)
A cost is attached if there's a change in direction, i.e. if d!=(matrix[r][c]-1).  This is 1...or 0!
6) nDist (new distance) is set to the distance to the starting cell through the current cell(r,c), plus the edgeWeight int nDist = dist[r][c]+edgeWeight
7) The if-statement checks whether to consider a neighbor cell. The cell must be valid, and nDist must be smaller than dist[nr][nc]
8) If nDist < dist[nr][nc], then dist[nr][nc] is updated
9) If the edgeWeight is 0, changing direction of neighboring cells has no cost!  In which case, push_front({nr,nc})
10)  Otherwise, we push_back({nr,nc})
11) Return dist[rows-1][cols-1]
*/

class Solution {
    int dr[4]{0,0,1,-1};
    int dc[4]{1,-1,0,0};

    bool isValid(int r, int c, vector<vector<int>>&grid){
        if(r<0||r>=grid.size())
            return false;
        if(c<0||c>=grid[0].size())
            return false;
        return true;
    }
    const int OO = 1e9;
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>>dist(rows,vector<int>(cols,OO));
        dist[0][0] = 0;

        deque<vector<int>>deq;
        deq.push_back({0,0});

        while(!deq.empty()){
            int r = deq.front()[0];
            int c = deq.front()[1];
            deq.pop_front();
            for(int d = 0; d < 4; d++){
                int nr = dr[d]+r;
                int nc = dc[d]+c;
                int edgeWeight = d!=(grid[r][c]-1);
                int nDist = dist[r][c]+edgeWeight;

                if(!isValid(nr,nc,grid)||nDist>=dist[nr][nc])
                    continue;
                
                dist[nr][nc] = nDist;
                
                if(edgeWeight==0)
                    deq.push_front({nr,nc});
                else
                    deq.push_back({nr,nc});
            }
        }
        return dist[rows-1][cols-1];
    }
};
