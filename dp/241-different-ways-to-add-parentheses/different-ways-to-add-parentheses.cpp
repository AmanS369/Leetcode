class Solution {
public:
    vector<int> solve(int i, int j, string &ex) {
        vector<int> ans;

//multi digit number
        bool isNumber = true;
        for (int k = i; k <= j; k++) {
            if (!isdigit(ex[k])) {
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            ans.push_back(stoi(ex.substr(i, j - i + 1)));
            return ans;
        }

        for (int k = i; k <= j; k++) {
            if (ex[k] == '+' || ex[k] == '-' || ex[k] == '*') {

                vector<int> left = solve(i, k - 1, ex);
                vector<int> right = solve(k + 1, j, ex);

                for (int l : left) {
                    for (int r : right) {

                        if (ex[k] == '+')
                            ans.push_back(l + r);

                        else if (ex[k] == '-')
                            ans.push_back(l - r);

                        else
                            ans.push_back(l * r);
                    }
                }
            }
        }

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(0, expression.size() - 1, expression);
    }
};