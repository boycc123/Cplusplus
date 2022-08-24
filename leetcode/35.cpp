#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        int res = max + 1;
        while (min <= max)
        {
            if(target == nums[(min + (max - min) / 2)]) {
                return (min + (max - min) / 2);
            }else if(target < nums[(min + (max - min) / 2)]) {
                max = (min + (max - min) / 2) - 1;
                res = (min + (max - min) / 2);
            }else {
                min = (min + (max - min) / 2) + 1;
            }
        }
        return res;
        
    }
};


int main(){
    Solution s1 = Solution();
    vector v1 = {1, 2};
    int res = s1.searchInsert(v1, 3);
    cout << res << endl;
    return 0;
}