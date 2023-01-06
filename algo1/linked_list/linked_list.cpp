#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};







// Sort the linked list
void sortLinkedList(Node** head_ref) {
  Node *current = *head_ref, *index = NULL;
  int temp;

  if (current == NULL) {
    return;
  } else {
    while (current != NULL) {
      // index points to the node next to current
      index = current->next;

  	while (index != NULL) {
        if (current->data > index->data) {
          temp = current->data;
          current->data = index->data;
          index->data = temp;
    	  }
    	  index = index->next;
  	}
  	current = current->next;
    }
  }
}


Node* mergeTwoSortedLLRecursively(Node * head1, Node * head2){
    if(head1==NULL && head2==NULL) {
        return 0;
    }else if(head1==NULL || head2!=NULL) {
        return head2;
    }else if(head1!=NULL || head2==NULL){
        return head1;
    }
    Node * newHead = NULL;
    if(head1->data<head2->data){
        newHead = head1;
        newHead->next = mergeTwoSortedLLRecursively(head1->next,head2);
    }else{
        newHead = head2;
        newHead->next = mergeTwoSortedLLRecursively(head1,head2->next);

    }
    return newHead;

}
Node *takeInpute()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }

        cin >> data;
    }
    return head;
}

void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    //     while(head!=NULL){
    //         cout<<head->data<<"->";
    //         head = head->next;
    //     }
    //     cout<<"NULL"<<endl;
}

//  int length(Node *head){
//      Node *temp =head;
//      int length = 0;
//      while(temp!=NULL){                                   //length by iteratively
//          temp = temp->next;
//          length++;
//      }
//      return length;
//  }
Node *reverselist(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}

// reversing by using recursion
Node* reverseList(Node* head) {
    if(!head || !(head->next))  return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}
// Node* merge(Node *head1,Node* head2){
//     if(head1==NULL){return head1;}
//     if(head2==NULL){return head2;}
//     Node *finalhead=NULL;                               // for haed to return
//     if((head1->data) < (head2->data)){
//         finalhead=head1;
//         head1=head1->next;
//     }else{
//         finalhead=head2;                                                                             //    merge by iterations
//         head2=head2->next;
//     }
//     Node *p=finalhead;                                // to form a new LL
//     while(head1 && head2){
//          if(head1->data < head2->data){
//         p->next=head1;
//         head1=head1->next;

//     }else{
//         p->next=head2;
//         head2=head2->next;
//     }
//     p=p->next;
//     }
//     if(head1){
//             p->next = head1;
//         }else{
//             p->next = head2;
//         }
//     return finalhead;
// }

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *newHead = NULL;
    if (a->data < b->data)
    {
        newHead = a;
        newHead->next = merge(a->next, b);
    }
    else
    { // merge sorted linked list by recursion
        newHead = b;
        newHead->next = merge(a, b->next);
    }
    return newHead;
}

int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    } // by recursion length of linked list
    int smallans = length(head->next);
    return 1 + smallans;
}
void insertNode(Node *&head, int n, int data)
{
    int i = 0;
    Node *temp = head;
    if (n < 0 || n > length(head))
    {
        cout << "Node doesn't exist!" << endl;
        return;
    }
    while (head != NULL)
    {
        if (i + 1 == n)
        {
            Node *nd = new Node(data);
            Node *temp2 = head->next;
            head->next = nd;
            head = nd;
            head->next = temp2;
            break;
        }
        head = head->next;
        i++;
    }
    head = temp;
}
Node *deleteNode(Node *&head, int n)
{
    if (n < 0)
    {
        return head;
    }
    if (n == 1 && head)
    {
        Node *newhead = head->next;
        head->next = NULL;
        delete head;
        head = newhead;
        return head;
    }
    if (n > 1 && n < length(head))
    {
        int i = 0;
        Node *temp = head;
        while (head != NULL)
        {
            Node *temp;
            if (i + 2 == n && head->next && head)
            {
                Node *temp = head->next;
                head->next = head->next->next;
                temp->next = NULL;
                delete temp;
                return head;
            }
            head = head->next;
            i++;
        }
        head = temp;
    }
    return head;
}
void printithnode(Node *head, int n)
{
    int i = 0;
    Node *temp = head;
    if (n < 0 || n > length(temp))
    {
        cout << "Node doesn't exist!" << endl;
        return;
    }
    while (temp != NULL)
    {
        if (i + 1 == n)
        {
            cout << temp->data << endl;
            break;
        }
        temp = temp->next;
        i++;
    }
}

int main()
{
    /// Statically
    //    Node n1(1);
    //    Node *head = &n1;

    //    Node n2(2);
    //    Node n3(3);
    //    Node n4(4);
    //    Node n5(5);

    //    n1.next = &n2;
    //    n2.next = &n3;
    //    n3.next = &n4;                    //manually taking input
    //    n4.next = &n5;

    Node *head1 = takeInpute();
    print(head1);
    // Node *head2 = takeInpute();
    // cout<<length(head1)<<"\n";
    // printithnode(head1,1);
    // insertNode(head1,3,70);
    // printithnode(head1,3);
    // cout<<length(head1)<<"\n";
    // printithnode(head1,4);
    // // print(head1);
    // deleteNode(head1,1);
    // cout<<length(head1)<<"\n";

    // print(head1);
    // head1=reverselist(head1);
    // print(head1);
    Node *head2 = takeInpute();
    print(head2);
    Node *head3;
    head3 = merge(head1, head2);
    print(head3);
    sortLinkedList(&head3);
    print(head3);

    //    print(head);
    //    print(head);

    /*n1.next = &n2;
    cout<<n1.data<<" "<<n2.data<<endl;

    Node *head = &n1;

    cout<<head->data<<endl;

    /// Dynamically
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n3->next = n4;
    */

    return 0;
}
