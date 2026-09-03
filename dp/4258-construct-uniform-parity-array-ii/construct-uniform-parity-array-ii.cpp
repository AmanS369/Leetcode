class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int miniOdd = INT_MAX;
       int miniEven = INT_MAX;

       for(auto i:nums1){
        if(i%2==0) miniEven = min(miniEven,i);
        else miniOdd = min(miniOdd,i);
       }

       if(miniOdd == INT_MAX) return true;
       if(miniEven - miniOdd >=1 ) return true;

       return false;
    }
};