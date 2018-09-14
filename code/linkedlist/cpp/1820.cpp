#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "ctype.h"
#include "stack"
#include <netinet/in.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <memory>

#include "linkedlist.h"

using namespace std;

/* linked list.
  Convert Sorted List to Binary Search Tree
  
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
// Use pre order traversal, D&C. O(nlogn)
// buildTree2() uses in order traversal O(n)! But it still uses pre order
// to create the tree. 
TreeNode * buildTree(ListNode *head, int len) {
    if (len <1 || head==NULL)
        return NULL;
            
    int half = len/2;

    // need keep head.
    ListNode * currentList = head;
    for (int i=0; i<half; ++i)
        currentList = currentList->next;
        
    TreeNode *current = new TreeNode(currentList->val);
    current->left = buildTree(head, half);

    // Do not include the current node in the length = len-half-1.
    current->right = buildTree(currentList->next, len-half-1);

    // Don't forget to return;
    return current;
}

TreeNode *sortedListToBST(ListNode *head) {
    // write your code here

    int len = 0;

    // May create a separate function to get the length
    ListNode * current = head; // Need keep head. 
    while(current)
    {
        ++len;
        current = current->next;
    }
    return buildTree(head, len);
}

// Use in order traversal to convert list to BST. O(N)
// Note: This one is interesting. It uses pre order to create the nodes and
// in order traversal to set the values. 
// Note: need keep the length, but it does not need to be reference type.
// Note: You don't have to use pre order to create nodes! See buildTree3.
TreeNode * buildTree2(ListNode * &head, int len) {
    if (head == NULL || len == 0)
        return NULL;

    // use pre order to create the node.
    TreeNode * root = new TreeNode(0);
    --len;
    // half of the nodes for left sub tree.
    root->left = buildTree(head, len/2);

    // use in order to set the values. 
    root->val = head->val;
    head = head->next;
    
    // half of the nodes for right sub tree.
    root->right = buildTree(head, len-len/2);
    return root;
}
    
TreeNode *sortedListToBST2(ListNode *head) {
    int len = 0;
    ListNode * current=head;
    while (current) {
        ++len;
        current=current->next;
    }

    return buildTree(head, len);
}

// No need pre order to create nodes! Check this out! buildTree3.
// 
TreeNode * buildTree3(ListNode * &head, int len) {
    if (head == NULL || len ==0)
        return NULL;

    // Create left and right variables because the root node is not created.
    // Variables in this area are created pre-order. 
    // They will remain in the stack until return is called. 
    TreeNode * left, *right;
    --len;

    left = buildTree(head, len/2);
    
    // in order processing
    // create node in order. 
    TreeNode * root = new TreeNode(head->val);
    head = head->next;

    right = buildTree(head, len-len/2);

    // post order processing
    // assign left and right to the root node. 
    root->left = left;
    root->right = right;
    return root;
}
    
TreeNode *sortedListToBST3(ListNode *head) {
    int len = 0;
    ListNode * current=head;
    while (current) {
        ++len;
        current=current->next;
    }

    return buildTree(head, len);
}

/*
  Reverse a linked list.
  Example
  For linked list 1->2->3, the reversed linked list is 3->2->1
*/
ListNode *reverse(ListNode *head) {
    // write your code here
    ListNode * current = head;
    ListNode * prev = NULL;
    while (current) {
        // always use tmp to keep a variable. 
        ListNode * tmp = current->next;
        current->next = prev;
        prev = current;
        current = tmp;
    }
    return prev;
}

/* Remove duplicates from sorted list
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
ListNode *deleteDuplicates(ListNode *head) {
    // write your code here
    ListNode * current = head; // keep the head
    while (current && current->next) {
        if (current->val == current->next->val) {
            ListNode * tmp = current->next;
            current->next = tmp->next;
            delete tmp;
            // Do not advance the current node here.
            // current = current->next;
        }
        else
            current = current->next;
    }
    return head;
}

/* Remove duplicates from sorted list 2
  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
 */
ListNode * deleteDuplicates2(ListNode *head) {
    // No need to check this
    //if (!head || !head->next)
    //    return head;

    // Use dummy node. Memorize this trick!
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    
    while (head->next && head->next->next) {
        if (head->next->val == head->next->next->val) {
            // keep the val so that we can delete the nodes.
            // Memorize this trick!
            int val = head->next->val;

            // Whenever dereference a pointer or use array[] operator,
            // Check boundary!
            while(head->next && val == head->next->val) {
                ListNode * tmp = head->next;
                head->next = tmp->next;
                delete tmp;
            }
        } else {
            head = head->next;
        }
    }

    ListNode * result = dummy->next; // return dummy->next
    delete dummy;
    return result;
}

/*
  Reverse a linked list from position m to n.

Note
Given m, n satisfy the following condition: 1 <= m <= n <= length of list.

Example
Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.

Challenge
Reverse it in-place and in one-pass
*/

ListNode *reverseBetween(ListNode *head, int m, int n) {
    // When head is not determined, use a dummy
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;

    // move to one node ahead of node m
    for (int i=1; i < m; ++i)
    {
        if (head)
            head=head->next;
        else
            return NULL; // return NULL if shorter list
    }

    // Need draw a graph. Keep all the important nodes to be linked after
    // the reverse.
    // 
    // Need keep two nodes at both end of the reversed list. 
    // prevm->next will point to the beginning of the reversed list.
    // start->next will point to the rest of the list
    ListNode * prem = head; 
    ListNode * start = head->next;

    // Now reverse the list between m and n.
    head = head->next;
    ListNode * prev=NULL;
    for (int i = 0; i < n-m+1; ++i) {
        if (!head)
            return NULL;
        ListNode * tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }

    // always check NULL pointer before dereferencing. 
    if (prem)
        prem->next = prev;
    if (start)
        start->next = head;

    // don't forget to delete dummy
    ListNode * result = dummy->next;
    delete dummy;
    return result;
    
}

/*
  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2->null and x = 3,
return 1->2->2->4->3->5->null.
*/
// In place process. An alternative in partition2() is to move the nodes
// to two links and connect them after that. 
ListNode *partition(ListNode *head, int x) {
    // create a dummy
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
        
    ListNode * prehead = head;
    // For single list, we need keep the previous node and check its next
    // so that we can manipulate the links. 
    while (head->next) {
        ListNode * next = head->next;
        if (next->val < x) {
            if (head == prehead) {
                head = head->next;
                prehead = head;
                continue;
            }
            head->next = next->next;
            next->next = prehead->next;
            prehead->next = next;
            prehead = prehead->next;
        } else {
            head=head->next;
        }
    }

    // Don't forget to delete dummy. This is C++!
    ListNode * result = dummy->next;
    delete dummy;
    return result;
}

ListNode *partition2(ListNode *head, int x) {
    ListNode * leftDummy = new ListNode(0);
    ListNode * rightDummy = new ListNode(0);
        
    auto left = leftDummy;
    auto right = rightDummy;
    while (head) {
        if (head->val < x) {
            left->next = head;
            left = left->next; 
        } 
        else {
            right->next = head;
            right = right->next;
        }
        head = head->next;
    }
        
    left->next = rightDummy->next;
    right->next = NULL;
        
    ListNode * result = leftDummy->next;
    delete leftDummy;
    delete rightDummy;
    return result;
}

/*
  Find the two largest nodes in a linked list. Then swap their ref or pointers. Google.
 */
ListNode * swapLargestTwo(ListNode * root) {
    if (root == nullptr || root->next == nullptr)
        return root;

    ListNode * dummy = new ListNode(0);
    dummy->next = root;
    ListNode * ptr = dummy;
    ListNode * l1 = nullptr, *l2 = nullptr;

    // find the two largest. 
    while (ptr->next != nullptr) {
        // Note: First take care of regular case, then add l1==nullptr.
        // Do not forget to compare val, not next. 
        if (l1 == nullptr || ptr->next->val > l1->next->val) {
            l2 = l1;
            l1 = ptr;
        }
        else if (l2 == nullptr || ptr->next->val > l2->next->val) {
            l2 = ptr;
        }

        // Note: do not forget the following in a loop with linked list
        ptr = ptr->next;
    }

    // Note: Use two stage swap. First swap ->next, then swap ->next->next;
    // Notice the order of the items in the next 3 equations. 
    ListNode * tmp = l1->next;
    l1->next = l2->next;
    l2->next = tmp;

    // Notice the order of the items in the next 3 equations. 
    tmp = l1->next->next;
    l1->next->next = l2->next->next;
    l2->next->next = tmp;

    tmp = dummy->next;
    delete dummy;
    return tmp;
}

ListNode * createLinkedList(vector<int> & nums) {
    ListNode * dummy = new ListNode(0);
    ListNode * ptr = dummy;
    for (auto n : nums) {
        ptr->next = new ListNode(n);
        ptr = ptr->next;
    }

    ptr = dummy->next;
    delete dummy;
    return ptr;
}

void displayList(ListNode * root) {
    while (root != nullptr) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {3, 2, 1, 4, 6};
    ListNode * root = createLinkedList(nums);
    displayList(swapLargestTwo(root));
    
    return 0;
}
