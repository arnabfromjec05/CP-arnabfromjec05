 /*
 This problem takes input a doubly linked list which needs to be flatten
 Approach in sol is to store it in array accordingly and create doubly list using the array
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
ans: [1,2,3,7,8,11,12,9,10,4,5,6]
*/

#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    vector<int> v;
    
    Node* getNode(int val) {
        Node* temp = new Node();
        temp->val = val;
        temp->child=temp->next=temp->prev=NULL;
        return temp;
    }
    
    void storeList(Node* head) {
        if(head==NULL)
            return;
        v.push_back(head->val);
        storeList(head->child);
        storeList(head->next);
    }
    
    Node* flatten(Node* head) {
        storeList(head);
        
        Node* tail;
        head=tail=NULL;
        for(int i=0;i<v.size();i++) {
            Node* temp=getNode(v[i]);
            if(head==NULL) {
                head=temp;
                tail=temp;
            }
            else {
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
            }
        }
        return head;
        
    }
};