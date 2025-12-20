    void saveToFile(string filename) {//mostafa
    ofstream file(filename);
    Node* temp = head;
    while (temp != NULL) {
        file << temp->val << endl;
        temp = temp->next;
    }
    file.close();
}
    
    //////mostafa
void removeAt(int index) {
    if (head == NULL) return;

    if (index == 1) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp->next != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

///mostafa
void sortList() {
    if (head == NULL || head->next == NULL) return;

    for (Node* i = head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->val > j->val) {
                swap(i->val, j->val);
            }
        }
    }
}
void renameBook(int index, string newName) { //////mostafa
    if (head == NULL) return;

    Node* temp = head;
    for (int i = 1; temp != NULL && i < index; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    temp->val = newName;
}
