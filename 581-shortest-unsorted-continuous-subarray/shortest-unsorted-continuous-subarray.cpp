class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left =-1;
        int right = -1;
        int mn = INT_MAX;
        int mx= INT_MIN;
        for(int i=0;i< n;i++){


            if(mx > nums[i]){ // age aise elemnt mila jo mx se chota hai tho uspe ek pointer
                right = i;
            }else mx = nums[i]; //if vo mx se bada tho whai mx huaa na

            if(mn < nums[n-i-1])left = n-i-1;  // piche aise elemnt mila jo min se bada hai tho uspe ek pointer
            else mn = nums[n-i-1];//if vo min se chota tho whai min huaa na
        }

        if(right==-1) return 0;
        return right - left + 1;
        
    }
};