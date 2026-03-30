#include "Closet.h"

#include <iostream>
#include <string>

using namespace std;

// ----------------------- Constructor -----------------------
Closet::Closet(){}

// ----------------------- Methods -----------------------
void Closet::showCloset() {
/* Shows the item name and description for each item in the user's closet */
    cout << "----- CLOSET -----" << endl;
    if (closetItems.empty()) {
        cout << "(empty)" << endl;
    } else {
        for (int item = 0; item < closetItems.size(); item++) {
            cout << "+ " << closetItems[item].getName() << ": " << closetItems[item].itemDescription() << endl;
        }
    } cout << "---------------------" << endl;
    cout << endl;
}

void Closet::saveOutfit(vector<Clothing> newOutfit) {
/* Stores a group of clothing items that pair well together 
        - savedOutfits: The vector containg all of the current saved outfits
    */
    savedOutfits.push_back(newOutfit);
}

void Closet::showOutfits() {
/* Outputs all of the outfits that the user has saved */
    cout << "----- SAVED OUTFITS -----" << endl;
    if (savedOutfits.empty()) {
        cout << "(No saved outfits)" << endl;
    } else {
        for (int outfit = 0; outfit < savedOutfits.size(); outfit++) {
            cout << "Outfit " << outfit << endl;
            for (int item = 0; item < savedOutfits[outfit].size(); item++) {
                cout << "+ " << savedOutfits[outfit][item].getName() << ": " << savedOutfits[outfit][item].itemDescription() << endl;
            }       
        }
    } cout << "---------------------" << endl;
    cout << endl;
}

// ----------------------- Methods for adding clothing items to closets -----------------------
void Closet::addClothing(string itemType, vector<T> itemAttributes) {
    bool openToe;
        bool heel;
        bool sneaker;
    
    // finding the attribute sizes
    for (int attribute = 0; attribute < itemAttributes.size(); attribute++) {
        if (attribute = 0) { }
    }


    if (itemType == "Top" ) { // One Additional Accessory ...
        Top item();
    } else if (itemType == "Dress") {

    } else if (itemType == "Accessories") { 

    } else if (itemType == "Coat") { // Two Additional Accessories  ..

    } else if (itemType == "Bottom") {

    } else if (itemType == "Shoes") { // Three Additional Accessories
        Shoe()
    } else {

    }
    closetItems.push_back(item.getName());
}

void Closet::removeItem(int idx) {
/* FUNCTION DESCRIPTION
        - PARAMETER: PARAMETER DESCRIPTION
    */
}

vector<Clothing> Closet::generateOutfit(int dressiness, int avgTemp) {
/* FUNCTION DESCRIPTION
        - PARAMETER: PARAMETER DESCRIPTION
    */
}


