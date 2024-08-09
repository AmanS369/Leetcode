class Solution {
    public boolean isMagic(int[][] grid, int i, int j) {
        Set<Integer>st = new HashSet<>();

        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                if(grid[i+m][j+n] >9 || st.contains(grid[i+m][j+n]) || grid[i+m][j+n] <1 )  return false;
                st.add(grid[i+m][j+n]);
            }
        }
        int r1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        int r2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        int r3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        int c1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        int c2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        int c3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
        int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int d2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

        if (r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == d1 && d1 == d2 && d2 == r1) {
            return true;
        }
        return false;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int totalSubGrid = 0;
        int row = grid.length;
        int col = grid[0].length;
        for (int i = 0; i < row - 2; i++) {
            for (int j = 0; j < col - 2; j++) {
                if (i + 2 < row && j + 2 < col) {
                   
                    if (isMagic(grid, i, j)) {
                        totalSubGrid += 1;
                    }
                }
            }
        }
        return totalSubGrid;
    }
}
