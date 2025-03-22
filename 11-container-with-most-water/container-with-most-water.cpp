class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n = height.size();
        int j = n-1;
        int max_area=-1;
        while(i<j){
            int area= min(height[i],height[j]) * (j-i);
            max_area = max(max_area,area);
            if(height[i] > height[j]) j--;
            else i++;
        }
        return max_area;
    }
};