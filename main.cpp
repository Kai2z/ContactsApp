#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct contact {
    string name;
    string phoneNo ;
    string email;
};
vector<contact> contacts;

void addContact() {
contact newContact;
    cout<<"what is the contact name? "<<endl;
    getline(cin, newContact.name);
    cout<<"what is the number? "<<endl;
    getline(cin,newContact.phoneNo);
    cout<<"what is the email? "<<endl;
    getline(cin, newContact.email);

contacts.push_back(newContact);
}

void displayContacts() {
    if (contacts.empty()){
        cout<<"no contacts to display"<<endl;
        return;
    }
    else{
        cout<<"displaying all contacts.."<<endl;
        for(const auto& element: contacts){
            cout<<"------------------------------"<<endl;
            cout<<"name: "<<element.name<<endl;
            cout<<"phoneNO "<<element.phoneNo<<endl;
            cout<<"email "<<element.email<<endl;
            cout<<"------------------------------"<<endl;
        }
}
}

void updateContact() {
    if (contacts.empty()) {
        cout << "There are no contacts to update." << endl;
        return;
    }
    string name;
    bool found=false;
    cout<<"enter contact name to be updated: "<<endl;

    getline(cin, name);
for ( auto & element: contacts){
    if(name == element.name){
        found=true;
        cout<<"enter a new name: "<<endl;
        getline(cin, element.name);
        cout<<"enter a new phone number: "<<endl;
        getline(cin, element.phoneNo);
        cout<<"enter a new email: "<<endl;
        getline(cin, element.email);

        cout<<"contact have been updated successfully"<<endl;
        break;
    }
}
if (!found){
    cout<<"contact not found."<<endl;
}
}

void deleteContact() {
    string nameToBeDeleted;
    bool found=false;
    cout<<"enter contact name to be deleted: "<<endl;

    getline(cin, nameToBeDeleted);
    for ( size_t i=0; i<contacts.size();i++) {
        if (contacts[i].name == nameToBeDeleted) {
            contacts.erase(contacts.begin() +i);
            found = true;
            cout<<"contact was deleted successfully"<<endl;
            break;
        }
    }
    if (!found){
    cout<<"contact not found."<<endl;
    }
}

void searchContact() {

    if (contacts.empty()) {
        cout << "There are no contacts to search." << endl;
        return;
    }
    string name;
    bool found=false;
    cout<<"enter contact name to be searched: "<<endl;
    getline(cin, name);
    for ( auto & element: contacts){
        if(name == element.name){
            found=true;
                cout<<"------------------------------"<<endl;
                cout<<"name: "<<element.name<<endl;
                cout<<"phoneNO "<<element.phoneNo<<endl;
                cout<<"email "<<element.email<<endl;
                cout<<"------------------------------"<<endl;
            break;
        }
        }

      if (!found)
        cout<<"contact not found."<<endl;

}

int main() {
  int choice;
    do {
        cout << "Welcome To Our Contacts App!! " << endl;
        cout << "------------------------------" << endl;
        cout << "what would you like to do? " << endl;
        cout << "1. add a new contact" << endl;
        cout << "2. display all contacts" << endl;
        cout << "3. update a contact" << endl;
        cout << "4. search for a contact" << endl;
        cout << "5. delete a contact" << endl;
        cout << "6. exit the app" << endl;

        if(cin >> choice) {
            if (choice == 6) {
                cout << "Goodbye!" << endl;
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (choice) {
                case 1:
                    addContact();
                    break;
                case 2:
                    displayContacts();
                    break;
                case 3:
                    updateContact();
                    break;
                case 4:
                    searchContact();
                    break;
                case 5:
                    deleteContact();
                    break;
                default:
                    cout << "invalid choice, Please choose a number between 1 and 6." << endl;
            }
        }
        else{
            cout << "invalid choice, Please try again!" << endl;
        cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
       } while (choice!=6);
    return 0;
}