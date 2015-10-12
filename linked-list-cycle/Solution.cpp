#include <stddef.h>
using namespace std;

// url: https://leetcode.com/problems/linked-list-cycle/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		bool result = false;

		if (head == nullptr) return result;
		
		ListNode *slower = head->next;
		if (slower == nullptr) return result;
		ListNode *faster = slower->next;
		if (faster == nullptr) return result;

		while (true)
		{
			if (slower == faster)
			{
				result = true;
				break;
			}

			ListNode *next = faster->next;
			faster = nullptr;
			if (next != nullptr) faster = next->next;
			if (faster == nullptr) break;
			slower = slower->next;
		}

		return result;
	}
};