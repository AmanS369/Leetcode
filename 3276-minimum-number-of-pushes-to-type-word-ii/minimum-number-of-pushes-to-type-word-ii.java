class Solution {
    public int minimumPushes(String word) {

       Map<Character, Integer> frequencyMap = new HashMap<>();
              Map<Character,Integer>mp = new HashMap<>();
        for (char ch : word.toCharArray()) {
            frequencyMap.put(ch, frequencyMap.getOrDefault(ch, 0) + 1);
        }
        PriorityQueue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<>(
            (a, b) -> b.getValue().compareTo(a.getValue())
        );
        maxHeap.addAll(frequencyMap.entrySet());
         int cnt=8;
       int pushes=1;
         while (!maxHeap.isEmpty()) {
            Map.Entry<Character, Integer> entry = maxHeap.poll();
            char ch = entry.getKey();
             if(cnt == 0) {pushes+=1;cnt=8;}
         if(mp.containsKey(ch)) continue;
         else{
            mp.put(ch,pushes);
            cnt-=1;
         }
          
        }


      
    //    for(int i=0;i<word.length();i++){
    //      char ch = word.charAt(i);
        
    //    } 
     for (Map.Entry<Character, Integer> entry : mp.entrySet()) {
    System.out.println(entry.getKey() + " " + entry.getValue());
}

       int totalPushes=0;
        for(int i=0;i<word.length();i++){
         
         totalPushes+=(mp.get(word.charAt(i)));

       } 

       return totalPushes;

    }
}