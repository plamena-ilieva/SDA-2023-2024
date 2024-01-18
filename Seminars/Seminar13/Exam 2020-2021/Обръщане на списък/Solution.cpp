#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }


    void reverse(int from, int to) {
        Node *start = nullptr;
        Node *curr = head;
        for (int i = 0; i < from - 1; ++i) {
            if (!curr) {
                return;
            }
            start = curr;
            curr = curr->next;
        }

        Node *prev = nullptr;
        Node *next = curr;

        for (int i = 0; i <= to - from && curr; ++i) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        if (!start) {
            head = prev;
        } else {
            start->next = prev;
        }
        if (curr) {
            next->next = curr;
        } else {
            tail = next;
        }

    }

    void print() {
        Node* temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~List() {
        Node* curr = head;

        while(curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }

        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        string op;
        cin >> op;

        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }

        if (op == "print") {
            testList.print();
        }

        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }

    return 0;
}