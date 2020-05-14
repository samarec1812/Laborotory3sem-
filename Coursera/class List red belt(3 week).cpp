#include <vector>

using namespace std;

template<typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node *next = nullptr;

        bool operator==(const Node &node) {
            return this->value == node.value && this->next == node.next;
        }
    };

    ~LinkedList() {
        while(head) {
            PopFront();
        }
    }

    void PushFront(const T &value) {
        Node *add = new Node;
        add->value = value;
        add->next = head;
        head = add;
    }

    void InsertAfter(Node *node, const T &value) {
        if (!node) {
            PushFront(value);
            return;
        }

        Node *add = new Node;
        add->value = value;
        add->next = node->next;
        node->next = add;
    }

    void RemoveAfter(Node *node) {
        if (!node) {
            PopFront();
            return;
        }
        if (node->next) { 
	        Node *rem = node->next;
	        node->next = rem->next;
	        delete rem;
        }
    }

    void PopFront() {
        if (head) {
	        Node *rem = head;
	        head = rem->next;
	        delete rem;
        }
    }

    Node *GetHead() { return head; }

    const Node *GetHead() const { return head; }

private:
    Node *head = nullptr;
};

template<typename T>
vector<T> ToVector(const LinkedList<T> &list) {
    vector<T> result;
    for (auto node = list.GetHead(); node; node = node->next) {
        result.push_back(node->value);
    }
    return result;
}