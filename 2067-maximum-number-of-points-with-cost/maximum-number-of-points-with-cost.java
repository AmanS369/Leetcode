class Solution {
    public long maxPoints(int[][] points) {
        int n = points[0].length;
        long[] prev = new long[n];

        // Copy the first row to prev as initial values
        for (int j = 0; j < n; j++) {
            prev[j] = points[0][j];
        }

        // Traverse through each row starting from the second row
        for (int i = 1; i < points.length; i++) {
            long[] left = new long[n];
            long[] right = new long[n];

            // Calculate the left array
            left[0] = prev[0];
            for (int j = 1; j < n; j++) {
                left[j] = Math.max(left[j - 1] - 1, prev[j]);
            }

            // Calculate the right array
            right[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = Math.max(prev[j], right[j + 1] - 1);
            }

            // Calculate the current row maximum points
            long[] curr = new long[n];
            for (int k = 0; k < n; k++) {
                curr[k] = Math.max(left[k], right[k]) + points[i][k];
            }

            // Update prev to be the current row for the next iteration
            prev = curr;
        }

        // Find the maximum value in the last processed row
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, prev[i]);
        }
        return ans;
    }
}
