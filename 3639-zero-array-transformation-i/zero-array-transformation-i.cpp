class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,int>st,ed;
        int n = nums.size();
        for(auto i :queries){
            st[i[0]]+=1;
            ed[i[1]]+=1;
        }

        int invtCnt=0;
        vector<int>aux(n,0);
        for(int i=0;i<n;i++){
            if(st.find(i)!=st.end())invtCnt +=st[i];
            aux[i]+=invtCnt;
            if(ed.find(i)!=ed.end())invtCnt -=ed[i];
        }

        for(int i=0;i<n;i++){
            if(nums[i] - aux[i] > 0) return false;
        }

        return true;
    }
};