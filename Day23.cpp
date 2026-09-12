#include<bits/stdc++.h>
using namespace std;
// introduction to double linked list part A
class Node{
    public:
    int data;
    Node*next;
    Node*previous;
    Node(int data,Node*next,Node*previous){
        this->data=data;
        this->next=next;
        this->previous=previous;
    }

    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->previous=nullptr;
    }

};
Node*convertarrytoDLL(vector<int>&nums){
    int n=nums.size();
    Node*head=new Node(nums[0]);
    Node*prev=head;
    for(int i=1;i<n;i++){
        Node*temp= new Node(nums[i]); //create a Node of current element
        temp->previous=prev; //backward
        prev->next=temp;// forward connection
        prev=temp; // move the previous

    }
    return head;
}

void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node*deleteAtHead(Node*head){
    if(head==nullptr) return head; //no element in list
    if(head->next==nullptr) return nullptr;// one element in list
    Node*temp=head;
    head=head->next;//move head to next
    head->previous=nullptr; // set head previous =null
    temp->next=nullptr; // set delete element next =null
    delete(temp);
    return head;
}

Node*deleteAtTail(Node*head){
    if(head==nullptr) return head; //no element in list
    if(head->next==nullptr) return nullptr;// one elemnt

    Node*temp=head;
    while(temp->next!=nullptr){
       temp=temp->next;
    }
    Node*previous=temp->previous; // 2nd last element
    previous->next=nullptr;// 2nd last element next pointer to null to become last
    // next->previous=nullptr;// break the previous link of last element
    temp->previous=nullptr; //last element does not point to any previouos we make it null
    delete(temp); //delete last element;
    return head;

}

Node*deleteKthElement(Node*head,int k){
       if(head==nullptr) return head;
       // if doubly linked list have single element it neither have back not next
       // if k=1 it have next but not previous
       // if k=n it have previous but not  next
       Node*temp=head;
       int count=0;
       while(temp!=nullptr){
        count++;
        if(count==k)break;
        temp=temp->next; // keep moving this
       }
       // keep track of previous and next
       Node*back=temp->previous;
       Node*front=temp->next;
       // if doubly linked list have single element it neither have back not next
       if(back==nullptr && front==nullptr){
        delete(temp);
         return nullptr;
       }
      // if k=1 it have next but not previous
      else if(back==nullptr){
          return deleteAtHead(head);
      }
       // if k=n it have previous but not  next
       else if(front==nullptr){
        return deleteAtTail(head);
       }
       else{
        back->next=front;
        front->previous=back;
        temp->next=nullptr;
        temp->previous=nullptr;
        delete(temp);
      
       }


  return head;

}

void deleteNode(Node*temp){
    //assumption node should not be head;
    Node*back=temp->previous;
    Node*front=temp->next;
    if(front==nullptr){
        back->next=nullptr;
        temp->previous=nullptr;
        delete(temp);
    }


    back->next=front;
    front->previous=back;
    temp->next=nullptr;
    temp->previous=nullptr;
    delete(temp);
    
}

Node*insertbeforeHead(Node*head,int data){
    Node*newNode=new Node(data);
    newNode->next=head;
        if (head != nullptr) {
        head->previous = newNode;
    }
    head=newNode;
    return head;
}

Node*insertbeforeTail(Node*head,int data){
     if (head->next == nullptr) {
        return insertbeforeHead(head, data);
    }

    Node*newNode=new Node(data);
    Node*temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node*last=temp->next; // last element of ll
    temp->next=newNode; //2nd last element next equl new node
    newNode->previous=temp;
    newNode->next=last; //new node ->next point to last
    
    last->previous=newNode;


}


Node* insertAtKthPosition(Node* head, int k, int data) {

    // Empty list
    if (head == nullptr) {
        if (k == 1) {
            return new Node(data);
        }
        return head;
    }

    // Insert at head
    if (k == 1) {
        return insertbeforeHead(head, data);
    }

    Node* temp = head;
    int count = 1;

    // Reach the node at position k-1
    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }

    // Invalid position
    if (temp == nullptr) {
        return head;
    }

    Node* newNode = new Node(data);
    Node* front = temp->next;

    // Connect previous node to new node
    temp->next = newNode;
    newNode->previous = temp;

    // Connect new node to next node
    newNode->next = front;

    if (front != nullptr) {
        front->previous = newNode;
    }

    return head;
}
void insertbeforeNode(Node*node,int val){
     Node*prev=node->previous;
     Node*newNode=new Node(val,node,prev);
        prev->next=newNode;
        node->previous=newNode;
}

int main(){
    vector<int>number={1,2,3,4,5};
    Node*result= convertarrytoDLL(number);
    Node* r2=deleteAtTail(result);
    print(r2);

}