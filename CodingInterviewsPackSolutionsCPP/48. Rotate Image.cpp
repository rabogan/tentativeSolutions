class Solution {
public:
    void transpose(vector<vector<int>>&matrix){
        int n = matrix.size();

        for(int r = 0; r < n; r++){
            for(int c = r+1; c < n; c++){
                swap(matrix[r][c],matrix[c][r]);
            }
        }
    }

    void reflect(vector<vector<int>>&matrix){
        int n = matrix.size();
        for(int r = 0; r < n/2; r++){
            for(int c = 0; c < n; c++){
                swap(matrix[c][r],matrix[c][n-r-1]);
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }
};