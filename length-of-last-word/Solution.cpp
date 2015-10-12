#include <vector>
using namespace std;

class Solution {
public:
	//int lengthOfLastWord(string s) {
	//	int ret = 0;

	//	if (s.length() > 0) {
	//		int i = s.length();
	//		while (i > 0 && s[--i] == ' ');
	//		while (i >= 0 && s[i--] != ' ') ret++;
	//	}

	//	return ret;
	//}

	int lengthOfLastWord(string s) {
		int ret = 0;

		if (s.length() > 0) {
			string::size_type pos;
			pos = s.find_last_of(" ");

			if (pos == string::npos) {
				ret = s.length();
			}
			else {
				if (pos < s.length() - 1) {
					ret = s.length() - 1 - pos;
				}
				else {
					int spaceLength = 0;
					do {
						spaceLength++;
						pos = s.find_last_of(" ", s.length() - 1 - spaceLength);
					} while (pos == s.length() - 1 - spaceLength && pos != string::npos && spaceLength != s.length());

					if (spaceLength == s.length()) ret = 0;
					else {
						if (pos == string::npos) {
							if (spaceLength < s.length()) {
								ret = s.length() - spaceLength;
							}
							else {
								ret = 0;
							}
						}
						else {
							ret = s.length() - 1 - pos - spaceLength;
						}
					}
				}
			}
		}

		return ret;
	}
};

int main() {
	string s = "a ";
	Solution sol;
	printf("%d\n", sol.lengthOfLastWord(s));
	getchar();
	return 0;
}