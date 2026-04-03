<<<<<<< HEAD
#include "AuthSystem.h"
#include <iostream>
using namespace std;

int main() {
    AuthSystem auth;
    UserProfile currentUser;
    bool loggedIn = false;

    // Keep showing login menu until user logs in or exits
    while (!loggedIn) {
        loggedIn = auth.showLoginMenu(currentUser);
        if (!loggedIn) {
            cout << "Try again? (y/n): ";
            char c; cin >> c; cin.ignore();
            if (c != 'y') return 0;
        }
    }

    // Main app loop — user is now authenticated
    int choice;
    do {
        cout << "\n===== Main Menu =====\n";
        cout << "1. View Closet\n";
        cout << "2. Add Clothing\n";
        cout << "3. View Saved Outfits\n";
        cout << "4. Update Profile\n";
        cout << "5. Logout\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) currentUser.getCloset().showCloset();
        else if (choice == 2) { /* your add clothing flow */ }
        else if (choice == 3) currentUser.getCloset().showOutfits();
        else if (choice == 4) currentUser.updateProfile();

    } while (choice != 5);

    currentUser.logout();
    return 0;
=======
#include <iostream>
#include <vector>
#include <string>
#include "Clothing.h"
#include "Closet.h"

using namespace std;

int main_menu();

bool check_valid(string item, vector<Clothing*> closetItems) {
    bool exists;
    for (int i=0; i < closetItems.size(); i++){
        if (item == closetItems[i]->getName()) {
            return true;
        }
    } return false;
}

Clothing* get_Item(string item_name, vector<Clothing*> closetItems) {
    for (int i=0; i < closetItems.size(); i++){
        if (item_name == closetItems[i]->getName()) {
            return closetItems[i];
        }
    } return nullptr;
}

int main(){
    // -------------------- USERNAME AND PASSWORD --------------------
    string user_name; string password;
    cout << "Welcome to the Forecast Fits!" << endl;
    cout << "Please enter/create your username: " << endl; getline(cin, user_name);
    cout << "Please enter/create your password: " << endl; getline(cin, password);
    Closet<Clothing> user_closet; 


    // -------------------- MAIN LOOP --------------------
    while (true) {
        int choice = main_menu();
        if (choice == 0){
            cout << "Goodbye!" << endl;
            break;
        } else if (choice == 1) { // ADD CLOTHING ITEM 
            user_closet.addClothing();
        } else if (choice == 2) { // REMOVE CLOTHING ITEM
            string itemToRemove;
            cout << "What item do you want to remove?: " << endl; getline(cin, itemToRemove);
            user_closet.removeItem(itemToRemove);
        } else if (choice == 3) { // GENERATE OUTFIT
            string dressinessLevel;
            int temp;
            cout << "Please enter dressiness: " << endl; getline(cin, dressinessLevel);
            cout << "Please average temperature: " << endl; 
            cin >> temp;
            cin.ignore();
            // user_closet.generateOutfit();
        } else if (choice == 4) { // SAVE AN OUTFIT
            vector<Clothing*> outfitItems;
            string user_input;
            while (true) {
                cout << "What item do you want to add to this outfit?: " << endl; getline(cin, user_input);
                if (user_input == "Done") { 
                    break;
                } else if (check_valid(user_input, user_closet.closetItems)) {
                    outfitItems.push_back(get_Item(user_input, user_closet.closetItems));
                    cout << user_input << " was added to this outfit." << endl;
                } else if (!check_valid(user_input, user_closet.closetItems)) {
                    cout << "That item does not exist in the closet. Please enter a valid item: " << endl;
                }
            }
            cout << "Please enter/create your username: " << endl; getline(cin, user_name);
            user_closet.saveOutfit(outfitItems);
        } else if (choice == 5) { // SHOW SAVED OUTFITS
            user_closet.showOutfits();
        } else if (choice == 6) { // SHOW ITEMS IN CLOSET
            user_closet.showCloset();
        } else if (choice > 6) { 
            cout << "Invalid Input. Please enter one of the indices listed below." << endl;
        } 
    } return 0;
}

// -------------------- MENU AND SUBMENU OPTIONS --------------------
int main_menu() { // Main Menu Options
    cout << "\n\n==============================" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Generate Outfit" << endl;
    cout << "4. Save An Outfit" << endl;
    cout << "5. Show Saved Outfits" << endl;
    cout << "6. Show Items in Closet" << endl;
    cout << "0. Exit" << endl;
    cout << "==============================" << endl;
    cout << "Please choose an option: \n> ";
    int choice;
    cin >> choice;
    return choice;
>>>>>>> a90f188b4d1db64355649dce2ef7387c336fa8d9
}