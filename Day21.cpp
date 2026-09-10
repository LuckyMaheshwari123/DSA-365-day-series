#include<bits/stdc++.h>
using namespace std;
// basics of linked list 
class Node{
    public:
    int data;
    Node*next;
    public:
    Node(int data){
        this->data=data;
        next=nullptr;
    }
    Node(int data, Node*next){
        this->data=data;
        this->next=next;
    }
};
Node* convertVectorToLL(vector<int>& nums) {
    int n = nums.size();

    if (n == 0)
        return nullptr;

    Node* head = new Node(nums[0]);
    Node* mover = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node(nums[i]);

        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

// travesal
void traverseLL(Node *head){
     Node*temp=head; //Create another pointer pointing to the same first node.

     while(temp !=nullptr){ // iterate till lat element that is null ptr;
        cout<<temp->data<<" ";// print the data
        temp=temp->next;//shift the pointer to next node
     }

}

// find the length of ll 
int findLength(Node *head){
    Node*temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}
int checkPresent(Node*head,int element){
    Node*temp=head;
    while (temp!=nullptr)
    {
        if(temp->data==element) return 1;//found 
        temp=temp->next;
    }
    return 0; // not found
}

Node*insertAtHead(Node*head,int data){
    //create a new node and in next of node store head link will setup and return new head
    Node*Add= new Node(data);
    Add->next=head; 
    head= Add;
    return head;
}

// insert at last 
Node*insertAtTail(Node*head,int data){
     Node*element=new Node(data);
     if (head == nullptr) {
        return element;
    }
    Node*temp= head;
    while(temp->next!= nullptr){
        temp=temp->next;// go to end;
    }
   
    temp->next=element;

   return head;
}

// Node*insertAtPosition(Node*head,int data,int position){
//     int count=0;
//     Node*temp=head;
//     for(int i=0;i<position;i++){
//         temp->temp->next;
//     }
// }
Node* deleteAtHead(Node* head) {
    if (head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp; //free that element

    return head;
}

Node* deleteAtTail(Node* head){
    if(head==nullptr){
        return nullptr;
    }
     // Only one node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node*temp=head;
    while(temp->next->next!=nullptr){ //2nd last
        temp=temp->next;
    }
    Node* del=temp->next; //last element;
    temp->next=nullptr; //mark 2nd last as last
    delete del;
    return head;


}

Node* deleteAtk(Node* head,int k){
    if(head==nullptr) return head;
    if(k==1){
    return deleteAtHead(head);
    }
int len= findLength(head);
   // if k is greater than len of ll nothing to delte
    if(k>len){
        return head;
    }
    // if and len and k are same means delete last element
    if(k==len){
        return deleteAtTail(head);
    }

    Node*temp= head;
    for(int i=1;i<k-1;i++){
        temp=temp->next;
    }
    Node*store=temp->next;
    temp->next=temp->next->next;
    delete(store);
    return head;

}

Node* deleteValue(Node*head,int element){
    if(head==nullptr)return nullptr;
    if(head->data==element){
      Node*temp=head;
      head=head->next;
      delete temp;
      return head;
    }
    Node*previous=nullptr;
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==element){
            previous->next=previous->next->next;
            delete(temp);
            return head;
        }
         previous=temp;
         temp=temp->next;
    }
    return head;
}
// valid only k<=len;
Node*insertAtk(Node*head,int k,int data){
    Node*temp=head;
    if (k == 1)
    return insertAtHead(head, data);
   for(int i=1;i<k-1;i++){
     temp=temp->next;
   }
   Node*store= temp->next;
   Node* newdata=new Node(data);
   temp->next=newdata;
   newdata->next=store;
   return head;
}



Node* insertBeforeValue(Node* head, int element, int value) {
    if (head == nullptr)
        return head;

    if (head->data == element)
        return insertAtHead(head, value);

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->next->data == element) {
            Node* store = temp->next;
            Node* newdata = new Node(value);

            temp->next = newdata;
            newdata->next = store;

            return head;
        }

        temp = temp->next;
    }

    return head;
}
int main(){
    vector<int> Number ={1,2,3,4,5};
    Node * result= convertVectorToLL(Number);
    // traverseLL(result);
    // cout<<endl;
    // int count= findLength(result);
    // cout<<count<<endl;
    // int check=checkPresent(result,15);
    // cout<<check<<endl;
    // Node* addition= insertAtTail(result,6);
    // traverseLL(addition);
    // cout<<endl;
    // Node* updated=deleteAtTail(addition);
    // traverseLL(updated);
    Node* add =insertAtk(result,3,6);
    traverseLL(add);


}