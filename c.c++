#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string val;
    Node* next;

    Node(string v) {
        val = v;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void add(string value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() {
        int ll=0;
        Node* temp = head;
        while(temp != NULL) {
            ll++;
            cout << ll << "- " << temp->val << endl ;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList booksList;
    ifstream file("books.txt");
    string line;

    if(file.is_open()) {
        while(getline(file, line)) {
            booksList.add(line);
        }
        file.close();
    } else {
        cout << "ERROR" << endl;
    }

    booksList.print();
    return 0;
}
