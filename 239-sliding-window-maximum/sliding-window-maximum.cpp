class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<pair<int,int>>dq;
        //value-index
        if(k>=nums.size()){

            return {*max_element(nums.begin(),nums.end())};
        }
        int i=0;
        int j=0;
        while(j<nums.size() ){
             while(!dq.empty() && dq.back().first < nums[j]) dq.pop_back();
             dq.push_back({nums[j],j});
             if(j-i+1 == k){
                pair<int,int> ele = dq.front();
                ans.push_back(ele.first);
                i++;
                if(ele.second < i) dq.pop_front();
             }
             j++;
        }
        return ans;
    }
};