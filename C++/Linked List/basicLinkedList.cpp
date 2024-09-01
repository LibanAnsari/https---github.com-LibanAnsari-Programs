#include <bits/stdc++.h>
using namespace std;

/*
    LINKED LIST IN A NUTSHELL
*/

class node
{
public:

    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }

};

void insertAtTail(node *&head , int val){
    
    node *n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node *temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = n;

}

void insertAtHead(node *&head , int val){
    
    node *n = new node(val);
    n -> next = head;
    head = n; 

}

void insertAtPos(node *&head , int val , int pos){

    if(pos == 1){
        insertAtHead(head,val);
        return;
    }
    
    node *n = new node(val);
    int count = 1;
    node *temp = head;
    while(count <= pos - 2 and temp != NULL){
        temp = temp -> next;
        count++;
    }
    if(temp == NULL){
        cout << "NULL" << endl;
        return;
    }
    n->next = temp->next;
    temp->next = n;

}

void sortInsert(node *&head , int val){

    if(head == NULL or head->data >= val){
        insertAtHead(head,val);
        return;
    }

    node *n = new node(val);

    node *temp = head;
    while(temp->next != NULL and temp->next->data < val){
        temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;

}

void display(node *head){
    // by iteration
    node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;

    // by recursion
    // if(head == NULL){
    //     cout << "NULL" << endl;
    //     return;
    // }
    // cout << head->data << " -> ";
    // display(head->next);

}

int search(node *head , int val){
    // by iteration
    if(head == NULL){
        return -1;
    }

    node *temp = head;
    int count = 1;
    while(temp != NULL){
        if(temp->data == val){
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;

    // by recursion
    // if(head == NULL){
    //     return -1;
    // }
    // if(head->data == val){
    //     return 1;
    // }else{
    //     int res = search(head->next , val);
    //     if(res == -1){
    //         return -1;
    //     }else{
    //         return 1 + res;
    //     }
    // }

}

int searchMiddle(node *head){

    if(head == NULL){
        return -1;
    }

    node *slow=head,*fast=head;
    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;

}

int searchNthNodeFromEnd(node *head , int n){
    //Method 1
    // int count = 0;
    
    // node *temp = head;
    // while(temp != NULL){
    //     temp = temp->next;
    //     count++;
    // }

    // if(count < n){
    //     return -1;
    // }

    // temp = head;
    // for(int i = 0 ; i < (count - n + 1) ; i++){
    //     temp = temp->next;
    // }
    // return temp->data;


    // Method 2
    if(head == NULL){
        return -1;
    }

    node *first = head;
    for(int i = 0 ; i < n ; i++){
        if(first == NULL){
            return -1;
        }
        first = first->next;
    }
    node *second = head;
    while(first != NULL){
        first = first->next;
        second = second->next;
    }
    return second->data;

}

void deletion(node *&head , int val){

    if(head->data == val){
        
        node *todelete = head;
        head = head->next;

        delete todelete;
        return;

    }

    node *temp = head;
    
    while(temp->next->data != val){
        
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void removeDuplicates(node *&head){

    if(head == NULL){
        return;
    }

    node *temp = head;

    while(temp != NULL and temp->next != NULL){
        if(temp->data == temp->next->data){
            node *todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
        }else{
            temp = temp->next;
        }
    }

}

node *reverse(node *&head){
    // Iterative
    // node *prevptr = NULL;
    // node *currptr = head;
    // node *nextptr = NULL;
    
    // while(currptr != NULL){
    //     nextptr = currptr->next;
    //     currptr->next = prevptr;

    //     prevptr = currptr;
    //     currptr = nextptr;
    // }

    // return prevptr;

    // Recursive
    if(head == NULL or head->next == NULL){
        return head;
    }

    node *newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;

}

node *reversek(node *&head , int k){

    if(head == NULL or k <= 1){
        return head;
    }

    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr = NULL;

    int count = 0;
    while(currptr != NULL and count < k){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr != NULL){
        head->next = reversek(nextptr,k);
    }

    return prevptr;

}

int main(int argc, char const *argv[])
{
    node *head = NULL;

    for (int i = 20; i <= 50; i += 10){
        insertAtTail(head, i);
    }
    display(head);
    // 20 -> 30 -> 40 -> 50 -> NULL

    insertAtHead(head, 10);
    display(head);
    // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    deletion(head, 30);
    display(head);
    // 10 -> 20 -> 40 -> 50 -> NULL

    cout << search(head, 50) << endl;
    // 4

    insertAtPos(head, 30, 3);
    display(head);
    // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    sortInsert(head, 60);
    display(head);
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    cout << searchMiddle(head) << endl;
    // 40

    cout << searchNthNodeFromEnd(head, 2) << endl;
    // 50

    node *newhead = reverse(head);
    display(newhead);
    // 60 -> 50 -> 40 -> 30 -> 20 -> 10 -> NULL
    
    // node *newhead = reversek(head, 3);
    // display(newhead);
    // 30 -> 20 -> 10 -> 60 -> 50 -> 40 -> NULL

    // removeDuplicates(head);
    // display(head);
    // 10 -> 20 -> NULL

    return 0;
}
