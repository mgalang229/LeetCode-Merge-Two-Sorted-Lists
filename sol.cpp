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
    void combine(ListNode* head, ListNode* head2) {
        if(head==NULL||head2==NULL)
            return;
        ListNode* link;
        link=head;
        //traverse the first linked list
        while(link->next!=NULL)
            link=link->next;
        //connect the last element in the first linked list
        //to the first element in the second list
        link->next=head2;
    }
    void sort(ListNode* head) {
        bool ok;
        ListNode* cur;
        ListNode* end=NULL;
        if(head==NULL)
            return;
        //sort the combined list using bubble-sort
        do {
            ok=0;
            cur=head;
            //run the loop until 'ok' is false
            //swap the current node to the next node if it's larger
            //then, traverse the list again starting from the 'head'
	    //until every current node is less than the next node
            while(cur->next!=end) {
                if(cur->val>cur->next->val) {
                    int tmp=cur->val;
                    cur->val=cur->next->val;
                    cur->next->val=tmp;
                    ok=1;
                }
                cur=cur->next;
            }
            end=cur;
        } while(ok);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {  
		//first combine the two lists
        combine(l1, l2);
        //then sort them using bubble sort
        sort(l1);
        //assume each list is sorted
        //if the first list is null then return the second list
        //if the second list is null then return the first list
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        //if it passes all conditions then return the head node which is 'l1'
        return l1;
    }
};
