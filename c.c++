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

class linkedlist {
private:
    Node* head;
public:
    linkedlist() {
        head = NULL;
    }
    void init(string value) {
        ifstream file(value);
        string line;
        if(file.is_open()) {
            while(getline(file, line)) {
                Node* newNode = new Node(line);
                if(head == NULL) {
                    head = newNode;
                } 
                else {
                    Node* temp = head;
                    while(temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            file.close();
        }
    }

    string account(){
        char check;
        int li=0,i=0;
        string usern,upass;
        cout << "Do you have an account? (Y/n)" << endl;
        cin >> check;
        check=tolower(check);
        if(check=='y'){
            cout << "User name:" << endl;
            cin >> usern;
            Node* temp = head;
            while(temp != NULL){
                if(temp->val == usern){
                    break;
                }
                temp = temp->next;
            }
            if(temp == NULL){
                cout << "that username does not exist." << endl;
                return account();
            }
            while(li < 3){
                cout << "password(8): (B to go back)" << endl;
                cin >> upass;
                if(upass=="B" || upass=="b"){
                    return account();
                }
                if(upass.size()!=8){
                    li++;
                    cout<<"incorrect password"<<endl;
                    continue;
                }
                for(int i=0;i<upass.size();i++){
                    upass[i]=tolower(upass[i]);
                }
                if(temp->next != NULL && temp->next->val == upass){
                    return usern;
                }
                li++;
                cout<<"incorrect password"<<endl;
            }
            return account();
        }
        else if(check=='n'){
            ofstream file("users.txt",ios::app);
            while(i){
            cout << "Create a username:" << endl;
            cin >> usern;
            Node* temp=head;
             while(temp != NULL){
                if(temp->val == usern){
                    cout << "this user name unavailable."<< endl;
                    return account();
                }
                temp=temp->next;
            }
        }
            cout << "Create a password (8):" << endl;
            cin >> upass;
            while(upass.size()!=8){
                cout << "Create a password (8):" << endl;
                cin >> upass;
            }
            file << usern << endl;
            file << upass << endl;
            file.close();
            return usern;
        }
        return account();
    }
    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << endl;
            temp = temp->next;
        }
    }
};
class admin{
private:
public:
};
class user : public admin{
private:
public:

};


void hello(){
    cout <<"  ||    ||   =======    ||         ||            ===         " << endl;
    cout <<"  ||    ||   ||         ||         ||         //     \\\\    " << endl;
    cout <<"  ||====||   ||=====    ||         ||        ||       ||     " << endl;
    cout <<"  ||    ||   ||         ||         ||        \\\\      //    " << endl;
    cout <<"  ||    ||   =======    =======    =======       ===         " << endl;
}

int main() {
    linkedlist books , user;
    user.init("users.txt");
    string u = user.account();
    cout << "Welcome " << u << endl;
    hello();
    books.init("books.txt");
    books.print();
    return 0;
}
