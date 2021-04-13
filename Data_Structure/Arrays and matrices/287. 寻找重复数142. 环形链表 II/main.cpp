#include <stdio.h>
#include <iostream>
using namespace std;

/**
@author: ZhengXiaoTao
@description: 
*/
//287
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) {
                fast = 0;
                while(nums[fast] != nums[slow]) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return nums[slow];
            }
        }
    }
};

//142
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL) {
            slow = slow -> next;
            if(fast -> next == NULL) {
                return NULL;
            }
            fast = fast -> next -> next;
            if(slow == fast) {
                ListNode* ptr = head;
                while(ptr != slow){
                    slow = slow -> next;
                    ptr = ptr -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};