class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);


        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (d[i] == 'R') {
                cnt = n;
            } else if (d[i] == 'L') {
                cnt = 0;
            } else if (cnt > 0) {
                cnt--;
            }

            right[i] = cnt;
        }

        // Influence from the right
        cnt = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (d[i] == 'L') {
                cnt = n;
            } else if (d[i] == 'R') {
                cnt = 0;
            } else if (cnt > 0) {
                cnt--;
            }

            left[i] = cnt;
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            if (right[i] > left[i]) {
                ans += 'R';
            } else if (left[i] > right[i]) {
                ans += 'L';
            } else {
                ans += '.';
            }
        }

        return ans;
    }
};