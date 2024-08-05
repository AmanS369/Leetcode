class Solution {
    public String kthDistinct(String[] arr, int k) {
         Map<String, Integer> frequencyMap = new HashMap<>();
        
        // Count frequency of each string
        for (String s : arr) {
            frequencyMap.put(s, frequencyMap.getOrDefault(s, 0) + 1);
        }
        
        // List to store distinct strings in order
        List<String> distinctStrings = new ArrayList<>();
        for (String s : arr) {
            if (frequencyMap.get(s) == 1) {
                distinctStrings.add(s);
            }
        }
        
        // Return the kth distinct string if it exists
        return k <= distinctStrings.size() ? distinctStrings.get(k - 1) : "";
    }
}