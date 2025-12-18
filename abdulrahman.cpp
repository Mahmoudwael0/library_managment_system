#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class stored_books{
    public:
    string book_name;
    stored_books* next;
    bool is_borrowed;
    // static int count;
    stored_books(string b,stored_books* n=NULL,bool state=false){
        book_name=b;
        next=n;
        is_borrowed=state;
        // count++;
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
        // cout<<"count = "<<count<<endl;
    }
    void insert(stored_books* head, string new_book, bool state=false){
        stored_books* n=new stored_books(new_book);
        n->is_borrowed=state;
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
        for(stored_books* i=head;i!=NULL;i=i->next){
            for(stored_books* j=head;j->next!=NULL;j=j->next){
                if(j->book_name[0] > j->next->book_name[0]){
                    swap(j->book_name,j->next->book_name);
                    swap(j->is_borrowed,j->next->is_borrowed);
                }
            }
        }
    }  
};
// int stored_books::count = 0;
int main(){
    stored_books* head=new stored_books("A");
    head->insert(head,"F");                  
    head->insert(head,"B");                  
    head->insert(head,"D");
    head->insert(head,"E");
    head->insert(head,"C",true);
    head->print_books();
    head->bubblesort(head);
    cout<<"sort: "<<endl;
    head->print_books();
    return 0;
}
