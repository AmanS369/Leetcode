class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int,int>> pq;

int i = 0;

while(i < nums.size()) {
    int j = i;
    while(j < nums.size() && nums[j] == nums[i]) {
        j++;
    }

    pq.push({j - i, nums[i]});
    i = j;
}


        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
