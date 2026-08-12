class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       ListNode* prev=nullptr;
       if(head==nullptr){
        return nullptr;
       }
       while (head && head->val == val) {
        head = head->next;
       }
       ListNode* temp=head;
       while(temp!=nullptr){
        if(temp->val==val){
            ListNode* sec=temp;
            prev->next=temp->next;
            temp = temp->next;
            delete sec;
        }
        else{
        prev=temp;
        temp=temp->next;
        }
       } 
       return head;
    }
};