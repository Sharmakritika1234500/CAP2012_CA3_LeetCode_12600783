
#include <utility>
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {

        int n = nums.size();

        // Place each positive number at its correct index
        for (int i = 0; i < n; i++) {

            while (nums[i] >= 1 && nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {

                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first missing positive number
        for (int i = 0; i < n; i++) {

            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
