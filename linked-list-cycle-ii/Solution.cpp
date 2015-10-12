#include <stddef.h>
using namespace std;

// url: https://leetcode.com/problems/linked-list-cycle-ii/

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
	ListNode *detectCycle(ListNode *head) {
		ListNode *result = NULL;

		if (head == nullptr) return result;

		ListNode *slower = head->next;
		if (slower == nullptr) return result;
		ListNode *faster = slower->next;
		if (faster == nullptr) return result;

		bool cycle = false;
		while (true)
		{
			if (slower == faster)
			{
				cycle = true;
				break;
			}

			ListNode *next = faster->next;
			faster = nullptr;
			if (next != nullptr) faster = next->next;
			if (faster == nullptr) break;
			slower = slower->next;
		}

		if (cycle) {
			if (slower == head) {
				result = head;
			}
			else
			{
				ListNode *slower2 = head->next;
				slower = slower->next;

				while (slower != slower2)
				{
					slower2 = slower2->next;
					slower = slower->next;
				}
				result = slower;
			}
		}

		return result;
	}
};