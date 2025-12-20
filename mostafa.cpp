// /books.delete func
cout << "Select book number to delete: ";
cin >> z;

// Ensure the number is valid
if (z <= 0) {
    cout << "Invalid number!" << endl;
} else {
    books.deleteNode(z - 1, "books.txt"); // -1 because list is 0-indexed
}





// add func
cout << "Enter book name: ";
cin.ignore(); // Clear input buffer
getline(cin, bookname); // Allow multi-word book names

books.addNode(bookname, "books.txt");

