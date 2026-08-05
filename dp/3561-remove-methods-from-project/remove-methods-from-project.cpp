class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int, vector<int>> mp;

        for (auto &i : invocations) {
            mp[i[0]].push_back(i[1]);
        }

        // Find all suspicious methods
        set<int> st;
        queue<int> q;

        q.push(k);
        st.insert(k);

        while (!q.empty()) {
            int ele = q.front();
            q.pop();

            for (auto neigh : mp[ele]) {
                if (st.find(neigh) == st.end()) {
                    st.insert(neigh);
                    q.push(neigh);
                }
            }
        }

        // If any non-suspicious method calls a suspicious method,
        // we cannot remove them.
        for (int i = 0; i < n; i++) {
            if (st.find(i) != st.end()) continue;

            for (auto child : mp[i]) {
                if (st.find(child) != st.end()) {
                    vector<int> ans;
                    for (int j = 0; j < n; j++)
                        ans.push_back(j);
                    return ans;
                }
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (st.find(i) == st.end())
                ans.push_back(i);
        }

        return ans;
    }
};