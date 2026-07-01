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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kThNode=getKthNode(temp,k);
            if(kThNode==NULL){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* nextNode=kThNode->next;
            kThNode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=kThNode;
            }
            else{
                prev->next=kThNode;
            }
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
    ListNode* getKthNode(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* rev=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return rev;
    }
};