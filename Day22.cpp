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


int main(){
    vector<int>number={1,2,3,4,5};
    Node*result= convertarrytoDLL(number);
    Node* r2=deleteAtTail(result);
    print(r2);

}