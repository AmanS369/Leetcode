class Solution {
public:
    int solve(int index, vector<int>& days, vector<int>& costs,vector<int>&dp) {
        if (index >= days.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int i = index;
        int cost1 = costs[0] + solve(i+1,days,costs,dp);
        while(i<days.size() && days[i] < days[index]+7) i++;
        int cost2 = costs[1] + solve(i,days,costs,dp);

        i = index;
        while (i < days.size() && days[i] < days[index] + 30) i++;
        int cost3 = costs[2] + solve(i, days, costs, dp);



       return dp[index] = min({cost3,cost2,cost1});
       
    }



    int mincostTickets(vector<int>& days, vector<int>& costs) {
            int n = days.size();
    vector<int> dp(n, -1);
        return solve(0, days, costs,dp);
    }



    int mincostTickets1(vector<int>& days, vector<int>& costs) {
    unordered_set<int> travel(days.begin(), days.end());
    int lastDay = days.back();
    int dp[366] = {0};

    for (int d = 1; d <= lastDay; d++) {
        if (travel.count(d) == 0) {
            dp[d] = dp[d - 1]; // no travel today
        } else {
            dp[d] = min({
                dp[max(0, d - 1)] + costs[0],
                dp[max(0, d - 7)] + costs[1],
                dp[max(0, d - 30)] + costs[2]
            });
        }
    }

    return dp[lastDay];
}
};
