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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=slow;
        ListNode* rev=reverse(newHead);
        ListNode* left=head;
        ListNode* right=rev;
        while(right!=nullptr){
            if(left->val!=right->val) return false;
            left=left->next;
            right=right->next;
        }
        return true;
    }
     ListNode* reverse(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=nullptr;;
        while(temp!=nullptr){
            ListNode* second=temp->next;
            temp->next=prev;
            prev=temp;
            temp=second;
        }
        return prev;
    }
};