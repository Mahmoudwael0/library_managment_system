// adding part

void addbook(vector<book>&) {
  book b;
cout <<"enter book id: ";
cin>>b.id;
cin.ignore();

for (const auto& book : book) {
  if (book.id == b.id) {
     cout<< "this book ID is already there\n";
  return;
  }
}

cout <<"enter book title: ";
getline(cin, b.tittle);

cout <<"enter author name: ";
getline(cin, b.author);

b.isAvailabe=true;
books.push_back(b);

cout<<"book added successfully.\n";
}



// deleteing part

void deletebook(vector<book>&books) {
  int id;
 cout<<"enter book ID to delete: ";
cin >> id;

for (auto it =books .being();it !=books.end(); ++it) {
    if (it->id== id) {
books.erase(it);
cout<<"book is finally deleted.\n";
return;
    }
}
cout <<"book is not found.\n";
}
