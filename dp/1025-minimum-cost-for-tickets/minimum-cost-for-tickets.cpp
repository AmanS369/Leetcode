class Solution {
public:
    int dp[401];
    int solve(vector<int>& days, vector<int>& costs,int index , int maxDay){
        if(index >= days.size()) return 0;
        
        if(maxDay >= days[index]) return solve(days,costs,index+1,maxDay);
        if(dp[index]!=-1) return dp[index];
        //day1 pass
        int ans = costs[0] + solve(days,costs,index+1,days[index]);
        //day2 pass 
        ans = min(ans,costs[1] + solve(days,costs,index+1,days[index]+6 ));
        //day3 pass
        ans = min(ans,costs[2] + solve(days,costs,index+1,days[index]+29));
    
        return dp[index] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0,0);
    }
};