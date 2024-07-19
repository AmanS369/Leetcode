class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
      
        map<int,int>row;
        map<int,int>col;
        for(int i=0;i<matrix.size();i++){
              int chk = INT_MAX;
            for(int j=0;j<matrix[0].size();j++){
                chk = min(chk,matrix[i][j]);
            }
           row[i] = chk;
        }
 
        for(int i=0;i<matrix[0].size();i++){
            int chk = INT_MIN;
            for(int j=0;j<matrix.size();j++){
                chk = max(chk,matrix[j][i]);
            }
           col[i] = chk;
        }


        vector<int>ans;


        for(int i=0;i<matrix.size();i++){
             
            for(int j=0;j<matrix[0].size();j++){

                if(matrix[i][j]==row[i] && matrix[i][j]==col[j]){
                    ans.push_back(matrix[i][j]);
                }
               
            }
        
        }
 

        return ans;
       
    }
};