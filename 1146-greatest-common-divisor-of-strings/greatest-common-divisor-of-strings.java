class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // If str1 + str2 is not equal to str2 + str1, there is no common divisor string
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        
        // Compute the GCD of the lengths of str1 and str2
        int gcdLength = gcd(str1.length(), str2.length());
        
        // Return the prefix of str1 up to the gcd length
        return str1.substring(0, gcdLength);
    }
    
    // Helper function to calculate the GCD of two numbers
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
