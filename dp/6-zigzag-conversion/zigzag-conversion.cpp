class Solution {
public:
string convert(string s, int numRows) {
    if(numRows == 1) return s;

    string ans = "";
    int cycle = 2*(numRows - 1);

    for(int i = 0; i < numRows; i++) {

        for(int j = 0; j + i < s.size(); j += cycle) {

            ans += s[j + i];  // vertical char

            // middle rows get second char
            if(i != 0 && i != numRows - 1 && j + cycle - i < s.size()) {
                ans += s[j + cycle - i];
            }
        }
    }

    return ans;
}

};