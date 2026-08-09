#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> generateGrayCodes(int n) {
        vector<int> ans;
        int total = 1 << n;

        for (int i = 0; i < total; i++) {
            ans.push_back(i ^ (i >> 1));
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 2;
    vector<int> result = sol.generateGrayCodes(n);

    cout << "Gray Code sequence for n = " << n << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 0 1 3 2

    return 0;
}
