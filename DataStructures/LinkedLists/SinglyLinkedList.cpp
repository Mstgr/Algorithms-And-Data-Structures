#include <iostream>

// Singly Linked List

// Node class
struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertBeginning(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};



// This function merges two sorted linked lists (`head1` and `head2`) into a single sorted linked list. 
// It uses a dummy node to simplify the merging process and returns the head of the merged list.
Node* mergeLists(Node* head1, Node* head2) {
    // Create a dummy node to simplify the merging process
    Node* dummy = new Node(0);
    // Pointer to the current position in the merged list
    Node* current = dummy;

    // Traverse both lists and merge them
    // While both lists have elements, compare the current elements
    while (head1 != nullptr && head2 != nullptr){
        // If the current element in head1 is smaller, add it to the merged list
        if (head1->data < head2->data){
            // Add the current element from head1 to the merged list
            current->next = head1;
            // Move to the next element in head1
            head1 = head1->next;
        }else{
            // If the current element in head2 is smaller, add it to the merged list
            current->next = head2;
            // Move to the next element in head2
            head2 = head2->next;
        }
        // Move to the next position in the merged list
        current = current->next;
    }

    // If there are remaining elements in head1, add them to the merged list
    if (head1 != nullptr){
        current->next = head1;
    }else{
        // If there are remaining elements in head2, add them to the merged list
        current->next = head2;
    }

    // The merged list starts from the next of the dummy node
    Node* result = dummy->next;
    // Clean up the dummy node
    delete dummy;
    // Return the head of the merged list
    return result;
}

// This function reverses a linked list. 
//It uses three pointers (`prev`, `current`, and `next`) to reverse the list iteratively.
Node* reverseList(Node* head){
    
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main()
{
    Node *head = nullptr;
    // Create a linked list instance
    LinkedList list;
    list.insertBeginning(head, 9);
    list.insertBeginning(head, 8);
    list.insertBeginning(head, 5);
    list.insertBeginning(head, 4);
    list.insertBeginning(head, 1);
    list.printList(head);

    Node *head2 = nullptr;

    LinkedList list2;
    list2.insertBeginning(head2, 10);
    list2.insertBeginning(head2, 7);
    list2.insertBeginning(head2, 6);
    list2.insertBeginning(head2, 3);
    list2.insertBeginning(head2, 2);
    list2.printList(head2);

    Node* mergedHead = mergeLists(head, head2);
    list.printList(mergedHead);

    Node* reversedHead = reverseList(mergedHead);
    list.printList(reversedHead);
    return 0;
}