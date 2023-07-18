const int MAX = 100000+1;
int memory[MAX][2];
vector<int>A,B;
const int OO = 1e9;
class Solution {
public:
    
    int minSwap(vector<int>&A, vector<int>&B) {
        memory[0][0] = 0;
        memory[0][1] = 1;
        
        for(int idx = 1; idx < A.size(); idx++){
            memory[idx][0] = OO;
            memory[idx][1] = OO;
            
            for(int LPS = 0; LPS<2; LPS++){
                int lastA = A[idx-1];
                int lastB = B[idx-1];
                if(LPS)
                    swap(lastA,lastB);
                
                if(lastA<A[idx] && lastB<B[idx])
                    memory[idx][0] = min(memory[idx][0],memory[idx-1][LPS]);
                
                if(lastA<B[idx] && lastB<A[idx])
                    memory[idx][1] = min(memory[idx][1],1+memory[idx-1][LPS]);
            }
        }
        return min(memory[A.size()-1][0],memory[A.size()-1][1]);
    }
};
