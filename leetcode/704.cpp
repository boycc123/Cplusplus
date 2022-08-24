

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        while (min <= max)
        {
            if(target == nums[(max + min) / 2]) {
                return (max + min) / 2;
            }else if(target < nums[(max + min) / 2]) {
                max = (max + min) / 2 - 1;
            }else {
                min = (max + min) / 2 + 1;
            }
        }
        return -1;
    }
};



int main() {
    Solution s1 = Solution();
    vector<int> v1 = {1, 2, 3, 4, 6, 8};
    int res = s1.search(v1, 0);
    cout << res << endl;
    return 0;
}