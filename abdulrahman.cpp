#include<iostream>
#include<string>
using namespace std;
class stored_books{
    public:
    string book_name;
    stored_books* next;
    bool is_borrowed;
    static int count;
    stored_books(string b,stored_books* n=NULL,bool state=false){
        book_name=b;
        next=n;
        is_borrowed=state;
        count++;
    }
    void print_books(){
        stored_books* temp=this;
        if(this == NULL) return;
        while(temp!=NULL){
            cout<<temp->book_name;
            if(temp->is_borrowed){
                cout<<" (borrowed) ";
            }
            else{
                cout<<" (available) ";
            }
            cout<<endl;
            temp=temp->next;
        }
        cout<<"count = "<<count<<endl;
    }
    void insert(stored_books* head, string new_book){
        stored_books* n=new stored_books(new_book);
        if(head==NULL){
            head=n;
            return;
        }
        else{
            stored_books* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=n;
        }
    }
    void bubblesort(stored_books* head){
        if(head==NULL) return;

    }  
};
int stored_books::count = 0;
int main(){
    stored_books* head=new stored_books("A");
    head->insert(head,"B");
    head->insert(head,"C");
    head->insert(head,"D");
    head->insert(head,"E");
    head->print_books();
    return 0;
}
