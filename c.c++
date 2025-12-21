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
    void cart(string sss) {
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

    string borrow(Node* head ,int nb){
        Node* temp=head;
        for(int i=0;i<nb && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL) return "";
        string x=temp->val;
        temp->val=temp->val+" --Borrowed--";
        return x;
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
    int z,iii=1;
    string bookname,zz;
    user.init("users.txt");
    books.init("books.txt");
    borrowdata.init("data.txt");
    hello();
    string uname=user.account();
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
                }
                else if(cho=='a'||cho=='A'){
                    cout << "name of the book: "<<endl;
                    cin >> zz;
                }
                else if(cho=='s'||cho=='S'){
                    books.print();
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
    else{
        while(1){
            borrowdata.cart(uname);
            cout << "note: each pearson can take at most 4 books.  (E=exit  ,  to borrow=press any key  ,  c=show yourcart) "<<endl;
            cin >> cho;
            if(cho=='C'||cho=='c'){borrowdata.printcart(); cout << endl ;continue;}
            if(cho=='e'||cho=='E') break;
            books.print();
            cout << "choose the book number: to search(s)  "<<endl;
            cin >> zz;
            bool isNumber=true;
            for(char c: zz){
                if(!isdigit(c)) {isNumber=false; break;}
            }
            if(!isNumber) continue;
            z=stoi(zz);
            while(1){
                cout << "are you sure?(Y/n) "<<endl;
                cin >> cho;
                if(cho=='Y'||cho=='y'){
                    
                    
                    break;
                }
                else if(cho=='N'||cho=='n') break;
                else{cout << "error"<<endl; break;}
            }
        }
    }
}
