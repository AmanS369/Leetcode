

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> available;  // max-heap for query ends
        priority_queue<int, vector<int>, greater<int>> used; // min-heap for query ends that are being used
        int cnt = 0;
        int pos = 0;
        int n = nums.size();

        sort(queries.begin(), queries.end());

        for (int i = 0; i < n; i++) {
            // push queries starting at i to available
            while (pos < queries.size() && queries[pos][0] == i) {
                available.push(queries[pos][1]);
                pos++;
            }

            nums[i] -= used.size();  // adjust based on already used queries

            // try to assign queries to remove current element
            while (nums[i] > 0 && !available.empty() && available.top() >= i) {
                used.push(available.top());
                available.pop();
                nums[i]--;
                cnt++;
            }

            if (nums[i] > 0) return -1;

            // remove queries that end at i from used
            while (!used.empty() && used.top() == i) {
                used.pop();
            }
        }

        return queries.size() - cnt;
    }
};
