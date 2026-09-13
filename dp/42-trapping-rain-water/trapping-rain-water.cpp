class Solution {
public:

    int trap(vector<int>& h) {
        int n = h.size();

        if (n <= 2) return 0;

        vector<int> left(n);
        vector<int> right(n);
        left[0] = h[0];

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], h[i]);
        }

        right[n - 1] = h[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], h[i]);
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            int waterLevel = min(left[i], right[i]);
            res += waterLevel - h[i];
        }

        return res;
    }
};