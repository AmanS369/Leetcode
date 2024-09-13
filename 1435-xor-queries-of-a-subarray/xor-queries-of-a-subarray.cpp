class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int n = arr.size();
        vector<int>prefix(n,0);
        prefix[0] = arr[0];
        for(int i=1;i<n;i++){
          prefix[i] = arr[i] ^ prefix[i-1];
        }
    

        vector<int>ans;
        for(auto range : queries){
            int st = range[0];
            int ed = range[1];
            int xor_val = (st == 0 ? prefix[ed] : prefix[ed] ^ prefix[st - 1]);
            ans.push_back(xor_val);
        }
        return ans;
    }
};