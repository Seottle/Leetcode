/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*/直接对链表进行递归操作，直接递归到最后一层，然后比较
 结合链表逆序输出的原理
 */
class Solution {
public:
    ListNode* firstNode;
public:
    bool reverse(ListNode* curNode) {
        if(curNode == NULL) return true;
        bool res;
        res = reverse(curNode -> next) && (curNode -> val == firstNode -> val);
        firstNode = firstNode -> next;
        return res;
    }
    bool isPalindrome(ListNode* head) {
        firstNode = head;
        return reverse(firstNode);
    }
};
//使用了0(n)的空间复杂度，存出来操作了
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> tmp;
        while(head != NULL) {
            tmp.push_back(head -> val);
            head = head -> next;
        }
        int i = 0;
        int j = tmp.size() - 1;
        while(i < j) {
            if(tmp[i] != tmp[j]) {
                break;
            }
            else {
                i++;
                j--;
            }
        }
        if(i >= j) {
            return true;
        }
        else return false;
    }
};
