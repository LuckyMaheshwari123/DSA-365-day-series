#include <bits/stdc++.h>
using namespace std;

// =======================
// Singly Linked List Node
// =======================
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

// Reverse Singly Linked List
ListNode* reverseList(ListNode* head) {
    ListNode* previous = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* next = current->next;   // save next node
        current->next = previous;         // reverse the link
        previous = current;               // move previous forward
        current = next;                   // move current forward
    }

    return previous;
}


ListNode*MiddleNode(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head;

    while(fast!=nullptr && fast->next!=nullptr){
           slow=slow->next;
           fast=fast->next->next;
    }
    return slow;
}

// =======================
// Doubly Linked List Node
// =======================
struct Node {
    int data;
    Node* next;
    Node* previous;

    Node(int val) {
        data = val;
        next = nullptr;
        previous = nullptr;
    }
};

// Reverse Doubly Linked List by swapping values
Node* reverseDoublyLL(Node* head) {
    Node* start = head;
    Node* end = head;

    while (end->next != nullptr) {
        end = end->next;
    }

    while (start != end && start->previous != end) {
        int temp = start->data;
        start->data = end->data;
        end->data = temp;

        start = start->next;
        end = end->previous;
    }

    return head;
}
//reach at middle postion
ListNode* middleNode(ListNode* head) {
    ListNode* temp = head;
    int length = 0;

    while (temp) {
        length++;
        temp = temp->next;
    }

    int half = length / 2;

    ListNode* middle = head;

    for (int i = 0; i < half; i++) {
        middle = middle->next;
    }

    return middle;
}

// detect a cycle optimal one
bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    // detect cycle brute using hashing
      bool detectLoop(Node* head) {
        // Initialize a pointer at head
        Node* temp = head;

        // Create a map to keep track of visited nodes
        unordered_map<Node*, int> nodeMap;

        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }

        // If traversal completes, no loop detected
        return false;
    }


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
    ListNode *detectCycle(ListNode *head) {
         // Initialize a pointer at head
        ListNode* temp = head;

        // Create a map to keep track of visited nodes
        unordered_map<ListNode*, int> nodeMap;

        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return temp;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }

        // If traversal completes, no loop detected
        return nullptr;
    }
};

    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
              slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }



    // delete middle not 
    // we will use fast slow pointer 
    // first keep track of previous start from nullptr
    // in loop we do previous=slow and slow->next 
    // at last we have middle node and it previous
    // now previous->next =middle->next
    //delete middle
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

    ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*previous=nullptr;
    
    while(fast!=nullptr && fast->next!=nullptr){
           previous=slow;
           slow=slow->next;

           fast=fast->next->next;
    }
       previous->next=slow->next;
       slow->next=nullptr;
    
       return head;
    }
// remove nth node from last
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = len(head);

    if (head == nullptr) return nullptr;
    if (n > length) return head;

    // Remove head
    if (n == length) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* temp = head;

    int run = length - n;

    for (int i = 1; i < run; i++) {
        temp = temp->next;
    }

    ListNode* nthnode = temp->next;
    temp->next = nthnode->next;

    delete nthnode;

    return head;
}

// Reverse Doubly Linked List by reversing links
Node* reverseLL(Node* head) {
    Node* temp = head;

    // Go to last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    Node* newHead = temp;

    while (temp != nullptr) {
        Node* next = temp->next;          // store current next
        Node* previous = temp->previous;  // store current previous

        temp->previous = next;            // reverse previous
        temp->next = previous;            // reverse next

        temp = next;                      // move using old next
    }

    return newHead;
}

// =======================
// Print Singly LL
// =======================
void printSingly(ListNode* head) {
    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// =======================
// Print Doubly LL
// =======================
void printDoubly(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// =======================
// Main
// =======================
int main() {

    // -----------------------
    // Singly Linked List
    // -----------------------
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << "Singly Linked List: ";
    printSingly(head1);

    head1 = reverseList(head1);

    cout << "Reversed Singly LL: ";
    printSingly(head1);


    // -----------------------
    // Doubly Linked List
    // -----------------------
    Node* head2 = new Node(1);

    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head2->next = second;
    second->previous = head2;

    second->next = third;
    third->previous = second;

    third->next = fourth;
    fourth->previous = third;

    cout << "\nDoubly Linked List: ";
    printDoubly(head2);

    // Reverse by changing actual links
    head2 = reverseLL(head2);

    cout << "Reversed Doubly LL: ";
    printDoubly(head2);

    return 0;
}