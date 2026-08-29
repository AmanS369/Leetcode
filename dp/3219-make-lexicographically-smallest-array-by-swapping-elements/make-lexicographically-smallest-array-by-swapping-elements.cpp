class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<pair<int, int>> arr;
        vector<int> ans(n, 0);

        // Store {value, original index}
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        int prev = arr[0].first;

        vector<int> tempPos;
        vector<int> tempValue;

        // First element belongs to first group
        tempPos.push_back(arr[0].second);
        tempValue.push_back(arr[0].first);

        for (int i = 1; i < n; i++) {

            // New group starts
            if (arr[i].first - prev > limit) {

                // Sort original positions
                sort(tempPos.begin(), tempPos.end());

                // Smallest value -> smallest position
                for (int j = 0; j < tempPos.size(); j++) {
                    ans[tempPos[j]] = tempValue[j];
                }

                tempPos.clear();
                tempValue.clear();
            }

            prev = arr[i].first;

            tempPos.push_back(arr[i].second);
            tempValue.push_back(arr[i].first);
        }

        // Process the last group
        sort(tempPos.begin(), tempPos.end());

        for (int j = 0; j < tempPos.size(); j++) {
            ans[tempPos[j]] = tempValue[j];
        }

        return ans;
    }
};