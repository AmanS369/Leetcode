#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second > b.second; // Sort by value in decreasing order if frequencies are the same
        return a.first < b.first; // Sort by frequency in increasing order
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        vector<pair<int, int>> freqVec;
        vector<int> result;

        for (int num : nums) {
            freqMap[num]++;
        }

        for (const auto& item : freqMap) {
            freqVec.push_back({item.second, item.first});
        }

        sort(freqVec.begin(), freqVec.end(), cmp);

        for (const auto& item : freqVec) {
            result.insert(result.end(), item.first, item.second);
        }

        return result;
    }
};
