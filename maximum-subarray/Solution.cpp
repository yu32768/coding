#include <vector>
using namespace std;

//url: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		}

		if (n == 1) {
			return nums[0];
		}

		int max = nums[0], minSum = 0, sum = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			int d = sum - minSum;
			if (d > max) max = d;
			if (sum < minSum) minSum = sum;
		}

		return max;
	}
};