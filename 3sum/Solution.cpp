#include <vector>
#include <algorithm>
using namespace std;

/*
    2015.9.20
    https://leetcode.com/problems/3sum/
*/


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		int target = 0; // set the sum target

		sort(nums.begin(), nums.end());
		vector<vector<int>> result;

		if (nums.size() < 3) {
			return result;
		}

		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			int first = nums[i];
			int distance = target - first;
			vector<vector<int>> twoSumResult = twoSum(nums, i + 1, distance);
			if (twoSumResult.size() > 0) {
				for (int j = 0; j < twoSumResult.size(); j++) {
					vector<int> oneSolution;
					oneSolution.push_back(first);
					oneSolution.push_back(twoSumResult[j][0]);
					oneSolution.push_back(twoSumResult[j][1]);

					result.push_back(oneSolution);
				}
			}
		}

		return result;
	}

	vector<vector<int>> twoSum(vector<int>& nums, int left, int target) {
		vector<vector<int>> result;

		int secondPosition = left, thirdPosition = nums.size() - 1;
		do {
			int sum = nums[secondPosition] + nums[thirdPosition];

			if (sum == target) {
				vector<int> oneSolution;
				oneSolution.push_back(nums[secondPosition]);
				oneSolution.push_back(nums[thirdPosition]);
				result.push_back(oneSolution);
			}
			if (sum <= target) {
				do {
					secondPosition++;
				} while (nums[secondPosition] == nums[secondPosition - 1] && secondPosition < thirdPosition);
			}
			else if (sum > target) {
				do {
					thirdPosition--;
				} while (nums[thirdPosition] == nums[thirdPosition + 1] && secondPosition < thirdPosition);
			}

		} while (secondPosition != thirdPosition);

		return result;
	}
};

int main() {
	Solution s;
	vector<int> nums;
	vector<vector<int>> result = s.threeSum(nums);
	return 0;
}