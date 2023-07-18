class Solution {
    typedef vector<vector<int>>GRAPH;
    
    void add_edge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
    }
public:
    /*Briefly about the top 3 functions:
    1) The graph is almost boringly rudimentary
    2) We want to return an 'ordering' vector; it will ???
    3) The topSort function is as simple as usual.  There are two tricks
    4) One is to push the 'i' (or front()) value of the queue into the result vector
    5) The second is to use clear() on the ordering vector if the size is doesn't match the graph size
    6) Otherwise, return the ordering vector
    */
    vector<int>topSort(GRAPH&graph){
        int sz = graph.size();
        vector<int>incomingEdges(sz);
        for(int i = 0; i < sz; i++){
            for(int j:graph[i])
                incomingEdges[j]++;
        }
        queue<int>q;
        for(int i = 0; i < sz;i++){
            if(incomingEdges[i]==0)
                q.push(i);
        }
        vector<int>ordering;
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            ordering.push_back(i);
            
            for(int j:graph[i]){
                if(--incomingEdges[j]==0)
                    q.push(j);
            }
        }
        
        if(ordering.size()!=sz)
            ordering.clear();
        return ordering;
    }
    
    /*
    And now, for a diatribe about this function ;)
    1)  Immediately, we have a need for a row number, a column number, and a maxColor (see the dimensions laid out by the problem)
    2)  We get 4 vectors for the row and col range for EACH colour of the rectangle!  See how we initialize the max with -1, and min with rows/cols
    3)  The first big loop: gets the color of the grid (after some 'easy loops', then iterates through the whole grid, and maximises/minimise the four boundaries for the colour of the rectangle being looked at!
    4)  We then FINALLY create our graph, using...simply, the maxColor!
    5)  Now, the second big loop!  Wow!   It culminates in ADDING an edge!  We do this using the graph, color, and eventual targetGrid[r][c]
    5b)   The 3 loop iteration isn't that tricky, but you will need to be careful with your <= operators!
    6) The 'clear()' trick in the topSort function becomes apparent!   return topSort(graph).size()>0!!!
    */
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int rows = targetGrid.size();
        int cols = targetGrid[0].size();
        int maxColor = 61;
        
        vector<int>rmax(maxColor,-1);
        vector<int>rmin(maxColor,rows);
        vector<int>cmax(maxColor,-1);
        vector<int>cmin(maxColor,cols);
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int color = targetGrid[r][c];
                rmax[color] = max(rmax[color],r);   //So, this maximises -1 vs the row (r)
                rmin[color] = min(rmin[color],r);   //This minimises rows vs the row(r)
                cmax[color] = max(cmax[color],c);
                cmin[color] = min(cmin[color],c);
            }
        }
        
        GRAPH graph(maxColor);
        
        for(int color = 0; color < maxColor; color++){
            for(int r = rmin[color]; r<=rmax[color];r++){
                for(int c = cmin[color];c<=cmax[color];c++){
                    if(targetGrid[r][c]!=color)
                        add_edge(graph,color,targetGrid[r][c]);
                }
            }
        }
        return topSort(graph).size()>0;   
    }
};
