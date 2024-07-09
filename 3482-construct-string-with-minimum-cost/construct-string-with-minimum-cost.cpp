#include <vector>
#include <string>
#include <climits>
using namespace std;

struct Node {
    Node *links[26];
    int flag;
    Node() {
        flag = -1;
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word, int index, int costs) {
        Node *node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        if (node->flag == -1) {
            node->flag = costs;
        } else {
            node->flag = min(node->flag, costs);
        }
    }
    Node* getRoot() {
        return root;
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string> &words, vector<int> &cost) {
        Trie trie;
        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i], i, cost[i]);
        }
        
        int n = target.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX) continue;
            Node *node = trie.getRoot();
            for (int j = i; j < n; ++j) {
                if (!node->containsKey(target[j])) break;
                node = node->get(target[j]);
                if (node->flag != -1) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + node->flag);
                }
            }
        }
        
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
