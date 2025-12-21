#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    bool is_borrowed;
    Node(string v,bool b=false) {
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
void bubblesort(linkedlist &list,string filename="books_with_stat.txt"){ {
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
            string tempstat = (temp->is_borrowed)?" -borrowed":" -available";
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
        else{
            cout << "ERROR";
        return account();}
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
    //edit
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
    void userdata(){

    }
    //edit
    void print(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << endl;
            temp = temp->next;
        }

    }
    void cart(Node*head ,string k){
        Node* temp=head;
        

        
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
    //edit abdo
    string borrow(Node* head ,int nb){
        string x;
        Node*temp=head;
        for (int i=0;i<nb;i++){
            temp=temp->next;        
        }
        x=temp->val;

        temp->val=temp->val+" --Borrowed--";
        return x;
    }
    //edit
    void print(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val << endl;
            temp = temp->next;
        }}
    void checkcart(Node* head, string k){
        Node* temp=head;
        while(temp->next!=NULL){
        if (temp->val!=k){
           for(int i=0;i<5;i++){
            temp=temp->next;
           }}

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
    int z;
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
        if(datacho=='a'||datacho=='b'||datacho=='c'){
            break;
        }
        cout <<"ERROR"<<endl;
    }
    if (datacho=='A'||datacho=='a'){
        while (1){
        cout << "D=delete  A=add(books)  S=sort  E=exit"<< endl;
        cin >> cho;
        books.print();
        if(cho=='D'||cho=='d'){
            cout << "select item number to delete:"<<endl;
           cin >> z;
           //mostafa
        }
        else if (cho=='a'||cho=='A'){
            cout << "name of the book: "<<endl;
            cin >> zz;
            //mostafa
            }
        else if (cho=='s',cho=='S'){
            //mostafa
            books.print();
        }
        else if(cho=='e'||cho=='E'){
            break;
        }
        else{
            cout <<"ERROR"<<endl;
        }
        }
    }
    
}
    else{
        while(1){
    cout << "note: each pearson can take at most 4 books.  (E=exit  ,  to borrow=press any key  ,  r=return book) "<<endl;
    cin >> cho;
    if(cho=='r'||cho=='R'){

    }
    if(cho=='e'||cho=='E'){
        break;
    }
    //sort before print
    books.bubblesort(books)
    books.print();
    cout << "choose the book number: to search(s)  "<<endl;
    cin >> zz;
    if(zz>="a"&&zz<="z"){
        continue;
    }
    else{
        z=stoi(zz);
    while(1){
        cout << "are you sure?(Y/n) "<<endl;
        cin >> cho;
        //abdo
        if(cho=='Y'||cho=='y'){
            borrowdata.push(us.borrow(books.gethead(),z));
            break;
        }
        else if(cho=='N'||cho=='n'){
            break;
        }
        else{cout << "error"<<endl;
            break;
        }}
    }}}}

