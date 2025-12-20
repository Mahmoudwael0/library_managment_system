#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    bool is_borrowed;
    Node(string v, bool b=false) {
        val = v;
        next = NULL;
        is_borrowed=b;
    }
};

class linkedlist {
    private:
    Node* head;
    public:
    linkedlist() {
        head = NULL;
    }
//
    void init(string value) {
        ifstream file(value);
        string line;
        string stat;
        if(file.is_open()) {
            while(getline(file, line,'-')) {
                getline(file,stat);
                bool b=true;
                if(stat.find("available")!=string::npos){
                    b=false;
                }
                Node* newNode = new Node(line,b);
                if(head == NULL) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            file.close();
        }
    }
void bubblesort(linkedlist &list,string filename="booksCopy.txt"){ {
        if(list.head==NULL) return;
        for(Node* i=list.head;i!=NULL;i=i->next){
            for(Node* j=list.head;j->next!=NULL;j=j->next){
                if(j->val > j->next->val){
                    swap(j->val,j->next->val);
                    swap(j->is_borrowed,j->next->is_borrowed);
                }
            }
        }
        ofstream copy(filename);
        if(!copy.is_open()){
            cout<<"ERROR";
            return;
        }
        for(Node* temp=list.head;temp!=NULL;temp=temp->next){
            string tempstat = (temp->is_borrowed)?"-borrowed":"-available";
            copy<<temp->val<<tempstat<<endl;
        }
    } }

    void push(string v){
        Node* newNode = new Node(v);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    string account(){
        char check;
        int li=0,i=1;
        string usern,upass;
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
        return account();
    }
    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << endl;
            temp = temp->next;
        }
    }
    Node* gethead(){return head;}
    string getbook(int n){
        Node* temp=head;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        return temp->val;
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
        string x;
        Node*temp=head;
        for (int i=0;i<nb;i++){
            temp=temp->next;        
        }
        x=temp->val;
        temp->val=temp->val+"Borrowed";
        return x;
    }
// void borrowBook(linkedlist &list,string filename="books_with_stat.txt",int num){
//      {
//     string bookName;
//     string line;
//     cout<<"Enter the name of the book you want to borrow:"<<endl;
//     cin.ignore();
//     getline(cin,bookName);
//     Node* temp=list.head;
// for(int i=0;i<num;i++){
//     while(temp!=NULL){
//         if(temp->val==bookName){
//             if(temp->val==bookName && temp->is_borrowed){
//                 cout<<"it's borrowed";
//                 cout<<"do you serch for another book? (y/n)"<<endl;
//                 char ch;
//                 cin>>ch;
//                 if(tolower(ch)=='y'){
//                     borrowBook(list);
//                     return;
//                 }
//                 else
//                     return;}}
//             else if(temp->val==bookName && !temp->is_borrowed){
//                 cout<<"You have borrowed "<<bookName<<endl;
//                 temp->is_borrowed=true;
//                 ofstream file(filename);
//                 Node* temp2=list.head;
//                 while(temp2!=NULL){
//                     file<<temp2->val<<"-";
//                     if(temp2->is_borrowed){
//                         file<<"borrowed"<<endl;
//                     }
//                     else{
//                         file<<"available"<<endl;
//                     }
//                     temp2=temp2->next;
//                 }
//                 return;
//         }
//         temp=temp->next;
//     }
//     //
// }}};

    void print(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << endl;
            temp = temp->next;
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
    linkedlist books , user , data, borrowdata;
    admin ad(&user,&books,&borrowdata);
    userr us(&books,&borrowdata);
    char cho;
    int z;
    user.init("users.txt");
    books.init("books_with_stat.txt");
    hello();
    string uname=user.account();
    if(user.account()=="admin123"){
        cout << "D=delete  A=add  pu=print users  pd=print data"
    }
    else{
    cout << "note: each pearson can take at most 4 books. "<<endl;
    books.print();
    cout << "choose the book number:"<<endl;
    cin >> z;
    while(1){
        cout << "are you sure?(Y/n) "<<endl;
        cin >> cho;
        if(cho=='Y'||cho=='y'){
            borrowdata.push(us.borrow(books.gethead(),z));
            break;
        }
        else if(cho=='N'||cho=='n'){
            break;
        }
        else{cout << "error";}
    }}
    borrowdata.print();
}
