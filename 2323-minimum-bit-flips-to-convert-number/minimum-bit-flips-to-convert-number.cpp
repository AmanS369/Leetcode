class Solution {
public:
    int minBitFlips(int start, int goal) {
         int xorValue = start ^ goal; 
    int count = 0;
    
  
    while (xorValue > 0) {
        
        if (xorValue & 1) {
            count++;
        }
        xorValue >>= 1; 
    }
    
    return count;
    }
};