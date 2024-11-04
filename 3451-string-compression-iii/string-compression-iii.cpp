#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        int cnt = 1;
        stringstream comp;
        char prev = word[0];
        
        for(int i = 1; i < word.size(); i++) {
            if (prev == word[i]) {
                cnt++;
                // Reset counter at 9 to avoid MLE with long repeats
                if (cnt == 9) {
                    comp << '9' << prev;
                    cnt = 0;
                }
            } else {
                if (cnt > 0) comp << cnt << prev;
                prev = word[i];
                cnt = 1;
            }
        }
        // Finalize remaining characters
        if (cnt > 0) comp << cnt << prev;
        
        return comp.str();
    }
};
