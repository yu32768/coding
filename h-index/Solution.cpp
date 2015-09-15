#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

/* url: https://leetcode.com/problems/h-index/ */

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int ret = 0, now = 1;
		sort(citations.begin(), citations.end(), greater<int>());
		for (now; now <= citations.size(); now++)
		{
			if (citations.at(now - 1) >= now && (now == citations.size() || citations.at(now) <= now))
			{
				ret = now;
			}
		}

		return ret;
	}

	////// first try
	//int hIndex(vector<int>& citations) {
	//	int ret = 0;
	//	int now = 1;
	//	for (now; now <= citations.size(); now++)
	//	{
	//		int greater = 0;
	//		int equal = 0;
	//		for (int i = 0; i < citations.size(); i++) {
	//			if (citations.at(i) > now) {
	//				greater++;
	//			}
	//			else if (citations.at(i) == now) {
	//				equal++;
	//			}
	//		}
	//		if (greater + equal < now) break;
	//		else if (greater + equal == now) ret = now;
	//		else if (greater + equal > now && greater <= now) ret = now;
	//	}

	//	return ret;
	//}



	///// second try
	//int hIndex(vector<int>& citations) {
	//	int ret = 0;
	//	int now = 1;
	//	for (now; now <= citations.size(); now++)
	//	{
	//		int greater = 0;
	//		int equal = 0;
	//		vector<int>::iterator pos;
	//		for (pos = citations.begin(); pos != citations.end();) {
	//			if (*pos > now) {
	//				greater++;
	//				++pos;
	//			}
	//			else if (*pos == now) {
	//				equal++;
	//				++pos;
	//			}
	//			else {
	//				pos = citations.erase(pos);
	//			}
	//		}
	//		if (greater + equal < now) break;
	//		else if (greater + equal == now) ret = now;
	//		else if (greater + equal > now && greater <= now) ret = now;
	//	}

	//	return ret;
	//}
};
