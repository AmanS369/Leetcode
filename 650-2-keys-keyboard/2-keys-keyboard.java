class Solution {
     public static boolean isPrime(int n) {
        if (n <= 1) {
            return false; // Numbers less than or equal to 1 are not prime
        }
        if (n <= 3) {
            return true; // 2 and 3 are prime numbers
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false; // Exclude multiples of 2 and 3
        }

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
    public int help(int n,Set<Integer>arr){
        if(arr.contains(n)) return n;
        for(int i : arr){
            if(n%i ==0){
                return i + help(n/i,arr);
            }
        }
        return 0;
    }

    public int minSteps(int n) {
        Set<Integer>arr = new HashSet<>();
        for(int i=2;i<=1000;i++){
          if(isPrime(i))arr.add(i);
        }

        return help(n,arr);
       
    }
}