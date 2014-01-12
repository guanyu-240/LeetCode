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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        ListNode *prev = head;
        int k = lists.size();
        while (true){
            ListNode *min = NULL;
            int minIndex = -1;
            for (int n = 0; n < k; n ++){
                ListNode *tmp = lists[n];
                if (tmp == NULL){
                    continue;
                }
                else{
                    if (min == NULL||tmp->val < min->val){
                        min = tmp;
                        minIndex = n;
                    }
                }
            }
            if (min == NULL) {break;}
            if (head == NULL){
                head = min;
            }
            else{
                prev->next = min;
            }
            prev = min;
            lists[minIndex] = min->next;
        }
        return head;
    }
};
