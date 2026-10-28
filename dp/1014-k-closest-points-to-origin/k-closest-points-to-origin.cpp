class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
    

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;

            minHeap.push({dist, {x, y}});
        }

        vector<vector<int>> ans;

        while (k--) {
            auto top = minHeap.top();
            minHeap.pop();

            ans.push_back({top.second.first, top.second.second});
        }

        return ans;
    }
};