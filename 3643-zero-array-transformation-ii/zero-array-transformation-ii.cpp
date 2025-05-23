class Solution {
public:
 bool isZero(vector<int>& nums, vector<vector<int>>& queries,int mid){
    int n = nums.size();
    vector<int> temp(nums);
    vector<int> pre(n + 1, 0);
    for(int i=0;i<mid;i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int v = queries[i][2];
        pre[l] -=v;
        if(r + 1 < n ) pre[r+1] += v;
    }
    int currDec=0;
    for(int i=0;i<n;i++){
        currDec+=pre[i];
        temp[i]+=currDec;
        if(temp[i]>0) return false;
    }
    return true;
 }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
      int s =0;
      int e = queries.size();
      int ans = -1;
      while(s<=e){
       int mid = s + (e - s) / 2;
       if(isZero(nums,queries,mid)){
        ans = mid;
        e = mid-1;

       }else{
        s = mid +1;
       }
      }
      return ans;
    }
};