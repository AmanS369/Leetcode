class Solution {
public:
void rotateMatrix90Clockwise(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Create a new matrix with swapped dimensions
    vector<vector<char>> result(m, vector<char>(n));
    
    // Fill new matrix - for -90 degree rotation
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result[j][n-1-i] = matrix[i][j];
        }
    }
    
    // Copy result back to original matrix
    matrix = result;
}

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
      

        vector<vector<char>> res(n, vector<char>(m));
       


        for (int i = 0; i < n; i++) {
            int cnt = 0;
            vector<int>temp(m,-1);

            for (int j = 0; j < m; j++) {
                if (box[i][j] == '#') {
                    cnt += 1;
                } else if (box[i][j] == '*') {
                    
                    temp[j] = cnt; 
                    cnt = 0;         
                }
            }

            for(int j=m-1;j>=0;j--){

                if (cnt > 0) {
                    res[i][j] = '#';
                    cnt--;
                } else if (cnt == 0 && temp[j] >= 0) {
                    res[i][j] = '*';
                    cnt  = temp[j];

                } else {
                    res[i][j] = '.'; 
                }

            }
        }



rotateMatrix90Clockwise(res);
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++ ){
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
}
      
      

        return res;
    }
};
