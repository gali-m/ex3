
namespace mtm {

    template <class Node>
    struct LinkedList
    {
        Node* node;
        
        LinkedList() : node(NULL) {}

        LinkedList(Node* node) : node(node) {}

        ~LinkedList()
        {
            Node* current = this->node;
            Node* next;

            while (current != NULL) {
                next = current->next;
                delete current;
                current = next;
            }
        }
    };
}