class Solution {
public:
vector<int> nextSmaller(vector<int>& arr, int n) {
        vector<int> ans(arr.size(), 0);
        stack<int> stack;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!stack.empty() && arr[stack.top()] >= arr[i])
                stack.pop();
            ans[i] = stack.empty() ? -1 : stack.top();
            stack.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& arr, int n) {
        vector<int> ans(arr.size(), 0);
        stack<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && arr[stack.top()] >= arr[i])
                stack.pop();
            ans[i] = stack.empty() ? -1 : stack.top();
            stack.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmaller(heights, n);
        vector<int> prev = prevSmaller(heights, n);
        int area = 0;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            int r = next[i] == -1 ? n : next[i];
            int b = r - prev[i] - 1;
            area = max(area, l * b);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    
    }
};