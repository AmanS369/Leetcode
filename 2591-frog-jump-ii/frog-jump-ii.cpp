class Solution {
public:
    int maxJump(vector<int>& stones) {
        if(stones.size()==2) return stones[1] - stones[0];
        int max_cost = 0;
        //since it is striclty increasing
        // the cost would be minium if we take the element whoch are very loser to each other
        // pick the alernate one as it would have higher distance 
        for(int i=2;i<stones.size();i++){
             max_cost = max(max_cost, stones[i] - stones[i-2]);
        } 
        return max_cost;
    }
};