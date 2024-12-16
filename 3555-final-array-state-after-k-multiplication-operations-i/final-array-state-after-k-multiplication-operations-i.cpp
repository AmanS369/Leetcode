class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> minHeap;
        int n = nums.size();
        for(int i=0;i<n;i++){
            minHeap.push({nums[i],i});
        }

        for(int i=0;i<k;i++){
            pair<int,int> topElement = minHeap.top();
            minHeap.pop();
            minHeap.push({topElement.first*multiplier,topElement.second});


        }

        vector<int>ans(n,0);

        while(minHeap.size()>0){
            pair<int,int> topElement = minHeap.top();
            minHeap.pop();
            ans[topElement.second] = topElement.first;
        }

        return ans;

    }
};