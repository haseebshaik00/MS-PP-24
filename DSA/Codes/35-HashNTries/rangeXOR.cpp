#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

const int MAX_BITS = 30;  // Since 10^9 < 2^30

// Trie node structure
struct TrieNode {
    TrieNode* child[2];  // Pointers for 0 and 1
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    // Insert number into the Trie
    void insert(int num) {
        TrieNode* curr = root;
        for (int i = MAX_BITS; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->child[bit]) {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
        }
    }
    
    // Find maximum XOR for a number X
    int findMaxXOR(int num) {
        TrieNode* curr = root;
        int maxXOR = 0;
        for (int i = MAX_BITS; i >= 0; --i) {
            int bit = (num >> i) & 1;
            // We want to go the opposite direction to maximize XOR
            if (curr->child[1 - bit]) {
                maxXOR |= (1 << i);
                curr = curr->child[1 - bit];
            } else {
                curr = curr->child[bit];
            }
        }
        return maxXOR;
    }
};

int main() {
    int Q;
    cin >> Q;
    
    Trie trie;  // Create a Trie to store numbers
    vector<int> arr;  // To store elements inserted by Type 0 queries
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 0) {
            int X;
            cin >> X;
            arr.push_back(X);  // Add number to the array
            trie.insert(X);    // Insert number into the Trie
        } else if (type == 1) {
            int L, R, X;
            cin >> L >> R >> X;
            --L; --R;  // Make L and R zero-indexed
            
            // Initialize the max XOR and the best number
            int maxXOR = 0;
            int bestNumber = arr[L];
            
            // Traverse the array in the range [L, R]
            for (int i = L; i <= R; ++i) {
                int currentXOR = X ^ arr[i];
                if (currentXOR > maxXOR) {
                    maxXOR = currentXOR;
                    bestNumber = arr[i];
                }
            }
            
            cout << bestNumber << endl;
        }
    }
    
    return 0;
}