class Solution {
public:

    int countNumbersWithUniqueDigits(int n) {
      if(n ==0) return 1;
      if(n ==1 ) return 10;
      int result = 10;
      int current = 9;
      //1 + (9) + (9*9) + (9.9.8) + (9.9.8.7)
      for(int i=2;i<=n;i++){
        current *=(10-(i-1));
        result +=current;
      }
      return result;
    }
};