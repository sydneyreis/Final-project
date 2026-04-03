#ifndef CLOSET_H
#define CLOSET_H

#include <iostream>
#include <vector>
#include <string>
#include "Clothing.h"

using namespace std;

template <typename T>
class Closet {
public:
    vector<Clothing*> closetItems;
    vector<vector<Clothing*>> savedOutfits;

    // Constructor
    Closet();

    // Core features
    void addClothing();
    void removeItem(string name);
    void showCloset();
    void saveOutfit(vector<Clothing*> newOutfit);
    void showOutfits();
    vector<Clothing*> generateOutfit(int dressiness, int avgTemp);
};


// ================= IMPLEMENTATION =================

// Constructor
template <typename T>
Closet<T>::Closet() {}


// -------------------- SHOW CLOSET --------------------
template <typename T>
void Closet<T>::showCloset() {
    cout << "----- CLOSET -----" << endl;

    if (closetItems.empty()) {
        cout << "(empty)" << endl;
    } else {
        for (int i = 0; i < closetItems.size(); i++) {
            cout << "+ " << closetItems[i]->getName()
                 << ": " << closetItems[i]->itemDescription() << endl;
        }
    }

    cout << "---------------------\n" << endl;
}


// -------------------- SAVE OUTFIT --------------------
template <typename T>
void Closet<T>::saveOutfit(vector<Clothing*> newOutfit) {
    savedOutfits.push_back(newOutfit);
}


// -------------------- SHOW OUTFITS --------------------
template <typename T>
void Closet<T>::showOutfits() {
    cout << "----- SAVED OUTFITS -----" << endl;

    if (savedOutfits.empty()) {
        cout << "(No saved outfits)" << endl;
    } else {
        for (int i = 0; i < savedOutfits.size(); i++) {
            cout << "Outfit " << i << endl;

            for (int j = 0; j < savedOutfits[i].size(); j++) {
                cout << "+ " << savedOutfits[i][j]->getName()
                     << ": " << savedOutfits[i][j]->itemDescription() << endl;
            }
        }
    }

    cout << "---------------------\n" << endl;
}


// -------------------- ADD CLOTHING --------------------
template <typename T>
void Closet<T>::addClothing() {

    cout << "Enter a name for your item" << endl;
    string name;
    getline(cin, name);

    cout << "Enter the type of your item" << endl;
    string type;
    getline(cin, type);

    cout << "Enter the color of your item" << endl;
    string color;
    getline(cin, color);

    cout << "Enter yes if patterned, otherwise no" << endl;
    string patt;
    getline(cin, patt);
    bool patty = (patt == "yes");

    cout << "Warmth level (0–5): " << endl;
    int warmth;
    cin >> warmth;
    cin.ignore();

    cout << "Wear in rain? (yes/no)" << endl;
    string rain;
    getline(cin, rain);
    bool rainy = (rain == "yes");

    cout << "Is it a basic? (yes/no)" << endl;
    string basic;
    getline(cin, basic);
    bool bassic = (basic == "yes");

    cout << "Dressiness (1–5): " << endl;
    int dressy;
    cin >> dressy;
    cin.ignore();


    // -------- TYPE HANDLING --------
    if (type == "Top") {
        cout << "Sleeve length (long/short/sleeveless): " << endl;
        string length;
        getline(cin, length);

        closetItems.push_back(
            new Top(name, type, color, patty, warmth, rainy, bassic, dressy, length)
        );
    }

    else if (type == "Bottom") {
        string isShort, isSkirt;
        cout << "Shorts? (yes/no): ";
        getline(cin, isShort);
        cout << "Skirt? (yes/no): ";
        getline(cin, isSkirt);

        closetItems.push_back(
            new Bottom(name, type, color, patty, warmth, rainy, bassic, dressy,
                       isShort == "yes", isSkirt == "yes")
        );
    }

    else if (type == "Dress") {
        string length;
        cout << "Dress length: ";
        getline(cin, length);

        closetItems.push_back(
            new Dress(name, type, color, patty, warmth, rainy, bassic, dressy, length)
        );
    }

    else if (type == "Coat") {
        string length, wp;
        cout << "Coat length: ";
        getline(cin, length);
        cout << "Waterproof? (yes/no): ";
        getline(cin, wp);

        closetItems.push_back(
            new Coat(name, type, color, patty, warmth, rainy, bassic, dressy,
                     length, wp == "yes")
        );
    }

    else if (type == "Shoes") {
        string open, heel, sneak;

        cout << "Open toe? (yes/no): ";
        getline(cin, open);
        cout << "Heels? (yes/no): ";
        getline(cin, heel);
        cout << "Sneakers? (yes/no): ";
        getline(cin, sneak);

        closetItems.push_back(
            new Shoes(name, type, color, patty, warmth, rainy, bassic, dressy,
                      open == "yes", heel == "yes", sneak == "yes")
        );
    }

    else if (type == "Accessories") {
        string typpe;
        cout << "Accessory type: ";
        getline(cin, typpe);

        closetItems.push_back(
            new Accessories(name, type, color, patty, warmth, rainy, bassic, dressy, typpe)
        );
    }
}


// -------------------- REMOVE ITEM --------------------
template <typename T>
void Closet<T>::removeItem(string name) {
    for (int i = 0; i < closetItems.size(); i++) {
        if (closetItems[i]->getName() == name) {
            closetItems.erase(closetItems.begin() + i);
            return;
        }
    }

    cout << "Item not found." << endl;
}


// -------------------- GENERATE OUTFIT --------------------
template <typename T>
vector<Clothing*> Closet<T>::generateOutfit(int dressiness, int avgTemp) {

    vector<Clothing*> outfit;
    vector<Clothing*> tops, bottoms, shoes;

    for (int i = 0; i < closetItems.size(); i++) {
        if (closetItems[i]->getType() == "Top") tops.push_back(closetItems[i]);
        if (closetItems[i]->getType() == "Bottom") bottoms.push_back(closetItems[i]);
        if (closetItems[i]->getType() == "Shoes") shoes.push_back(closetItems[i]);
    }

    // (simplified for now)
    if (!tops.empty()) outfit.push_back(tops[0]);
    if (!bottoms.empty()) outfit.push_back(bottoms[0]);
    if (!shoes.empty()) outfit.push_back(shoes[0]);

    return outfit;
}

#endif