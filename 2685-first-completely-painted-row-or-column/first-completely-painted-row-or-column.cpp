class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> ansRow(row, 0);
        vector<int> ansCol(col, 0);
        map<int, pair<int,int>> mp;
        
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        
 
        for(int i = 0; i < arr.size(); i++) {
            auto [x, y] = mp[arr[i]];
            ansRow[x]++;
            ansCol[y]++;
           
            if(ansRow[x] == col || ansCol[y] == row) {
                return i;
            }
        }
        
        return arr.size()-1;
    }
};