class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        int n = s.size();
        priority_queue<pair<int, char>> pq;
        for (auto &p : freq) {
            if (p.second > (n + 1) / 2) return "";
            pq.push({p.second, p.first});
           
        }

        string result = "";
        while(pq.size() > 1){
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            
            result += c1;
            result += c2;

            
            if (--f1 > 0) pq.push({f1, c1});
            if (--f2 > 0) pq.push({f2, c2});

        }

        if (!pq.empty()) {
            result += pq.top().second;
        }
        
        return result;
    }
};