#include <iostream>
#include <fstream>
#include <string>
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
    void saveToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            Node* temp = head;
            while (temp != NULL) {
                file << temp->val << endl; 
                temp = temp->next;
            }
            file.close();
        }
    }
    void bubblesort(linkedlist &list, string filename="books_with_stat.txt"){ 
        for(Node* i=list.head; i!=NULL; i=i->next){
            for(Node* j=list.head; j->next!=NULL; j=j->next){
                if(j->val > j->next->val){
                    swap(j->val, j->next->val);
                }
            }
        }
    }
    void cart(string sss) {
        Node* checker = head;
        while(checker != NULL) {
            if(checker->val == sss) {
                return; 
            }
            checker = checker->next;
        }
        Node* newn = new Node(sss);
        if (head == NULL) {
            head = newn;
        } 
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newn;
        }
        Node* current = newn;
        for (int i = 0; i < 4; i++) {
            Node* newnode = new Node("-");
            current->next = newnode;
            current = newnode;
        }
    }
void borrowItem(string username, string bookName) {
        Node* globalScan = head;
        while(globalScan != NULL) {
            if(globalScan->val == bookName) {
                cout << bookName << "' is currently borrowed by someone else." << endl;
                return;
            }
            globalScan = globalScan->next;
        }
        Node* temp = head;
        bool userFound = false;
        while(temp != NULL) {
            if(temp->val == username) {
                userFound = true;
                Node* slot = temp->next; 
                for(int i = 0; i < 4; i++) {
                    if(slot == NULL) break;
                    if(slot->val == "-") {
                        slot->val = bookName;
                        cout << "Success! You borrowed: " << bookName << endl;
                        saveToFile("data.txt");
                        return;
                    }
                    slot = slot->next;
                }
                cout << "Your cart is full! (Max 4 books)" << endl;
                return;
            }
            temp = temp->next;
        }
        if(!userFound) cout << "no cart" << endl;
    }
    void returnItem(string username, string bookName) {
        Node* temp = head;
        bool userFound = false;

        // 1. Find the user node
        while(temp != NULL) {
            if(temp->val == username) {
                userFound = true;
                Node* slot = temp->next; 
                for(int i = 0; i < 4; i++) {
                    if(slot == NULL) break;
                    if(slot->val == bookName) {
                        slot->val = "-"; 
                        cout << "Success! You returned: " << bookName << endl;
                        saveToFile("data.txt"); 
                        return;
                    }
                    slot = slot->next;
                }
                
                cout << "Error: You don't have this book in your cart." << endl;
                return;
            }
            temp = temp->next;
        }
        if(!userFound) cout << "Error: User cart not initialized." << endl;
    }
    void printcart(){
        Node* temp = head;
        int i=1;
        while(temp != NULL) {
            if(i%6==0){
                cout <<endl;
            }
            i++;
            cout << temp->val << " -> ";
            temp = temp->next;
        }
    }
    string account(){
        char check;
        int li=0,i=1;
        string usern,upass;
        ofstream file("users.txt",ios::app);
        cout << "Do you have an account? (Y/n)" << endl;
        cin >> check;
        check=tolower(check);
        if(check=='y'){
            cout << "User name:" << endl;
            cin >> usern;
            if(usern=="admin123"){
                cout << "passowrd: " << endl;
                cin >> upass;
                if(upass=="123456"){
                    return usern;
                }
                else{
                    return account();
                }
            }
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
                    file.close();
                    return usern;
                }
                li++;
                cout<<"incorrect password"<<endl;
            }
            return account();
        }
        else if(check=='n'){
            while(i){
                cout << "Create a username:" << endl;
                cin >> usern;
                Node* temp=head;
                bool found=false;
                while(temp != NULL){
                    if(temp->val == usern){
                        found=true;
                        break;
                    }
                    temp=temp->next;
                }
                if(found){
                    cout << "this user name unavailable."<< endl;
                    return account();
                }
                i=0;
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
        else{
            cout << "ERROR";
            return account();
        }
    }

    void print() {
        int y=0;
        Node* temp = head;
        while(temp != NULL) {
            y++;
            cout << y <<"- "<< temp->val << endl;
            temp = temp->next;
        }
    }

    Node* gethead(){return head;}

    string getbook(int n){
        Node* temp=head;
        for(int i=0;i<n && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp!=NULL) return temp->val;
        return "";
    }
};

class admin{
private:
    linkedlist* users;
    linkedlist* book;
    linkedlist* datas;
public:
    admin(linkedlist* u,linkedlist* b, linkedlist* d){
        users=u;
        book=b;
        datas=d;
    }

    void print(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << endl;
            temp = temp->next;
        }
    }

};

class userr{
private:
    linkedlist* borro;
    linkedlist* bd;
public:
    userr(linkedlist* u,linkedlist* b){
        bd=u;
        borro=b;
    }
    void print(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            cout << temp->val << endl;
            temp=temp->next;
        }
    }
};

void hello(){
    cout <<"  ||    ||   =======    ||         ||          //===\\\\         " << endl;
    cout <<"  ||    ||   ||         ||         ||         //     \\\\    " << endl;
    cout <<"  ||====||   ||=====    ||         ||        ||       ||     " << endl;
    cout <<"  ||    ||   ||         ||         ||         \\\\     //    " << endl;
    cout <<"  ||    ||   =======    =======    =======     \\\\===//       " << endl;
}

int main() {
    linkedlist books , user , borrowdata;
    admin ad(&user,&books,&borrowdata);
    userr us(&books,&borrowdata);
    char cho, datacho;
    int z,iii=1,p=1;
    string bookname,zz;
    user.init("users.txt");
    books.init("books.txt");
    borrowdata.init("data.txt");
    hello();
    while(p){
    cout << "Exit";
    cin >> cho;
    if (cho=='l'||cho=='l'){
        break;
    } 
    string uname=user.account();
    while(p){
    cout << "Exit";
    cin >> cho;
    if (cho=='l'||cho=='l'){
        break;
    } 
    if(uname=="admin123"){
        while(1){
            cout << "choose data: (A=books   B=user  C=userdata)"<<endl;
            cin>>datacho;
            datacho=tolower(datacho);
            if(datacho=='a'||datacho=='b'||datacho=='c') break;
            cout <<"ERROR"<<endl;
        }
        if (datacho=='a'){
            while (1){
                cout << "D=delete  A=add  S=sort  E=exit"<< endl;
                cin >> cho;
                books.print();
                if(cho=='D'||cho=='d'){
                    cout << "select item number to delete:"<<endl;
                    cin >> z;
                    //------------------------
                }
                else if(cho=='a'||cho=='A'){
                    cout << "name of the book: "<<endl;
                    cin >> zz;
                    //----------------------
                }
                else if(cho=='s'||cho=='S'){
                    books.print();
                    //---------------------
                }
                else if(cho=='e'||cho=='E'){
                    break;
                }
                else cout <<"ERROR"<<endl;
            }
        }
        else if(datacho=='b'){
            user.print();
        }
        else if(datacho=='c'){
            borrowdata.printcart();
        }
    }
    else {
        borrowdata.cart(uname); 
        while(1) {
            cout << "note: each person can take at most 4 books. (E=exit , to borrow=press any key , c=show yourcart, r=return cart) " << endl;
            cin >> cho;
            if(cho == 'C' || cho == 'c') {
                borrowdata.printcart(); 
                cout << endl; 
                continue;
            }
            if(cho == 'E' || cho == 'e') {
                break;
            }
            if(cho == 'R' || cho == 'r') {
                cout << "Enter the name of the book you want to return:" << endl;
                cin.ignore();
                getline(cin, bookname);
                borrowdata.returnItem(uname, bookname);
                continue;
            }
            books.print();
            cout << "choose the book number: (or s to search) " << endl;
            cin >> zz;
            bool isNumber = true;
            for(char c : zz) {
                if(!isdigit(c)) { isNumber = false; break; }
            }
            if(!isNumber) {
                cout << "Invalid selection. Please enter a number." << endl;
                continue; 
            }
            z = stoi(zz);
            while(1) {
                cout << "Are you sure you want to borrow book #" << z << "? (Y/n) " << endl;
                cin >> cho;
                
                if(cho == 'Y' || cho == 'y') {
                    string selectedBook = books.getbook(z - 1);
                    
                    if(selectedBook != "") {
                        borrowdata.borrowItem(uname, selectedBook);
                    } else {
                        cout << "Error: Book not found!" << endl;
                    }
                    break; 
                }
                else if(cho == 'N' || cho == 'n') {
                    break; 
                }
                else {
                    cout << "Please enter Y or n" << endl;
                }
            }
        }
    }}
}}
