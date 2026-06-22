class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
for(int i = 0; i < 32; i++) {
        ans <<= 1;        // make space
        ans |= (n & 1);   // take last bit
        n >>= 1;          // remove last bit
    }
    
    return ans;
    }
};