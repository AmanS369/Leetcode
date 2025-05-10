class Solution {
public:

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        int z1=0;
        int z2=0;
        for(auto i:nums1){
            if(i==0) z1+=1;
            else sum1+=i;
        }

        for(auto i:nums2){
            if(i==0) z2+=1;
            else sum2+=i;
        }
         if ((z1==0 && sum1<sum2+z2)||(z2==0 && sum2<sum1+z1))
            return -1;
        return max(sum1+z1, sum2+z2);
    
    }
};