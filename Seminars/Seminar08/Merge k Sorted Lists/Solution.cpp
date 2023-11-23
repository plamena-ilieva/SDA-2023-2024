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
    ListNode* mergeKLists(vector<ListNode*>&lists) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]) {
                minheap.push({lists[i]->val,i});
            }
        }
        if(minheap.empty()) {
            return nullptr;
        }
        ListNode* node=new ListNode();
        ListNode* head=node;
        while(1) {
            pair<int,int>x=minheap.top();
            minheap.pop();
            node->val=x.first;
            if(lists[x.second]->next!=NULL) {
                lists[x.second]=lists[x.second]->next;
                minheap.push({lists[x.second]->val,x.second});
            }
            if(!minheap.empty()) {
                node->next=new ListNode();
                node=node->next;
            }
            else {
                break;
            }
        }
        return head;
    }
};