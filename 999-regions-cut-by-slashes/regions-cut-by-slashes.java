class Solution {
    public void numberofRegion(int i, int j, int[][] arr) {
        if (i < 0 || i >= arr.length || j < 0 || j >= arr[0].length || arr[i][j] == 1) return;
        arr[i][j] = 1;
        numberofRegion(i + 1, j, arr);
        numberofRegion(i - 1, j, arr);
        numberofRegion(i, j + 1, arr);
        numberofRegion(i, j - 1, arr);
    }

    public int regionsBySlashes(String[] grid) {
        int row = grid.length;
        int col = grid[0].length();
        int[][] arr = new int[row * 3][col * 3];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i].charAt(j) == '/') {
                    arr[i * 3][j * 3 + 2] = 1;
                    arr[i * 3 + 1][j * 3 + 1] = 1;
                    arr[i * 3 + 2][j * 3] = 1;
                } else if (grid[i].charAt(j) == '\\') {
                    arr[i * 3 + 2][j * 3 + 2] = 1;
                    arr[i * 3 + 1][j * 3 + 1] = 1;
                    arr[i * 3][j * 3] = 1;
                }
            }
        }

        int region = 0;
        for (int i = 0; i < row * 3; i++) {
            for (int j = 0; j < col * 3; j++) {
                if (arr[i][j] == 0) {
                    numberofRegion(i, j, arr);
                    region += 1;
                }
            }
        }

        return region;
    }
}
