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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(head == nullptr || head -> next == nullptr || left == right) return head;
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* prev = dummy;
      int i = 1;
      while(i < left){
        prev = prev->next;
        i++;
      }
      ListNode* temp = prev->next;
      int j = 0;
      while(j < right-left){
        ListNode* second = temp->next;
        temp->next = second->next;
        second->next = prev->next;
        prev->next = second;
        j++;
      }
      ListNode* newHead = dummy->next;
      delete dummy;
      return newHead;
    }
};