class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mp;
        int n  = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            string temp = "1";
            for(int j=1;j<m;j++){
                if(matrix[i][j-1] == matrix[i][j]) temp+="1";
                else temp+="0";
            }

            mp[temp]+=1;
        }
        int maxi=-1;
        for(auto [key,value]:mp){
            maxi = max(maxi,value);
        }
        return maxi;
    }
};