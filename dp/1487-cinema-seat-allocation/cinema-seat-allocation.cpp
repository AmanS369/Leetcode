class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
     
        unordered_map<int, unordered_set<int>> mp;

        for (auto &r : reservedSeats) {
            mp[r[0]].insert(r[1]);
        }
        int ans = (n - mp.size()) * 2;

        for (auto &[row, seats] : mp) {

           bool left = true, middle = true, right = true;
           for (int s : {2,3,4,5}) 
                if (seats.count(s)) left = false;

            for (int s : {4,5,6,7}) 
                if (seats.count(s)) middle = false;

            for (int s : {6,7,8,9}) 
                if (seats.count(s)) right = false;

            if (left && right) ans += 2;
            else if (left || middle || right) ans += 1;
        
        }
        return ans;
    }
};