class Solution {
public:

    void insertbetween(Node* head) {

        Node* temp = head;

        while(temp != nullptr) {

            Node* next = temp->next;

            Node* copy = new Node(temp->data);

            copy->next = next;
            temp->next = copy;

            temp = next;
        }
    }

    void randompointer(Node* head) {

        Node* temp = head;

        while(temp != nullptr) {

            Node* copy = temp->next;

            if(temp->random)
                copy->random = temp->random->next;
            else
                copy->random = nullptr;

            temp = copy->next;
        }
    }

    Node* nextpointerrconnect(Node* head) {
        
    Node* temp=head;
    Node* dummy=new Node(-1);
    Node* res=dummy;
    while(temp!=nullptr){
       res->next=temp->next;
       res=res->next;
       temp->next=temp->next->next;
       temp=temp->next;
    }
    return dummy->next;
        
        
        
        
        
    }

    Node* cloneLinkedList(Node* head) {

        if(head == nullptr)
            return nullptr;

        insertbetween(head);

        randompointer(head);

        return nextpointerrconnect(head);
    }
};