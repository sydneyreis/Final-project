#include "Closet.h"

#include <iostream>
#include <string>

using namespace std;

// ----------------------- Constructor -----------------------
template <typename T>
Closet<T>::Closet(){}

// ----------------------- Methods -----------------------
template <typename T>
void Closet<T>::showCloset() {
/* Shows the item name and description for each item in the user's closet */
    cout << "----- CLOSET -----" << endl;
    if (closetItems.empty()) {
        cout << "(empty)" << endl;
    } else {
        for (int item = 0; item < closetItems.size(); item++) {
            cout << "+ " << closetItems[item]->getName() << ": " << closetItems[item]->itemDescription() << endl;
        }
    } cout << "---------------------" << endl;
    cout << endl;
}

template <typename T>
void Closet<T>::saveOutfit(vector<Clothing*> newOutfit) {
/* Stores a group of clothing items that pair well together 
        - savedOutfits: The vector containg all of the current saved outfits
    */
    savedOutfits.push_back(newOutfit);
}

template <typename T>
void Closet<T>::showOutfits() {
/* Outputs all of the outfits that the user has saved */
    cout << "----- SAVED OUTFITS -----" << endl;
    if (savedOutfits.empty()) {
        cout << "(No saved outfits)" << endl;
    } else {
        for (int outfit = 0; outfit < savedOutfits.size(); outfit++) {
            cout << "Outfit " << outfit << endl;
            for (int item = 0; item < savedOutfits[outfit].size(); item++) {
                cout << "+ " << savedOutfits[outfit][item]->getName() << ": " << savedOutfits[outfit][item]->itemDescription() << endl;
            }       
        }
    } cout << "---------------------" << endl;
    cout << endl;
}

// ----------------------- Methods for adding clothing items to closets -----------------------
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

    cout << "Enter yes if your item is patterned if not enter no" << endl;
    string patt;
    getline(cin, patt);
    bool patty = false;
    if (patt == "yes"){
        patty = true;
    }

    cout << "On a scale 0-5 how warm is your item" << endl;
    cout << "With 5 being not warm at all and 0 being very warm" << endl;
    int warmth;
    cin >> warmth;
    cin.ignore();


    cout << "Enter yes if you would wear this item in the rain" << endl;
    string rain;
    getline(cin, rain);
    bool rainy = false;
    if (rain == "yes"){
        rainy = true;
    }

    cout << "Enter yes if you would consider this item to be a basic" << endl;
    string basic;
    getline(cin, basic);
    bool bassic = false;
    if (basic == "yes"){
        bassic = true;
    }

    cout << "On a scale 1-5 how dressy is your item: " << endl;
    int dressy;
    cin >> dressy;
    cin.ignore();


    if (type == "Top" ) { 
        cout << "Is your top 1 long sleeve, 2 short sleeve, or 3 sleevless. Enter a number: " << endl;
        int length;
        cin >> length;
        cin.ignore();
        closetItems.push_back(new Top(name, type, color, patty, warmth, rainy, bassic, dressy, to_string(length)));
    }
    
     else if (type == "Bottom"){
        cout << "Enter yes if this item is shorts" << endl;
        string isShort;
        getline(cin, isShort);
        bool shorty = false;
        if (isShort == "yes"){
            shorty = true;
        }
        cout << "Enter yes if this item is a skirt" << endl;
        string skirt;
        getline(cin, skirt);
        bool skirty = false;
        if (skirt == "yes"){
            skirty = true;
        }
        closetItems.push_back(new Bottom(name, type, color, patty, warmth, rainy, bassic, dressy, shorty, skirty));
    }
    

    else if (type == "Dress") {
        cout << "How long is your dress" << endl;
        string length;
        getline(cin, length);
        closetItems.push_back(new Dress(name, type, color, patty, warmth, rainy, bassic, dressy, length));
    }
    

     else if (type == "Accessories") { 
        cout << "What type of accesory is this " << endl;
        string typpe;
        getline(cin, typpe);
        closetItems.push_back(new Accessories(name, type, color, patty, warmth, rainy, bassic, dressy, typpe));
    } 
    
    
    else if (type == "Coat") { 
        string length;
        cout << "Enter coat length: ";
        getline(cin, length);

        bool waterproof;
        cout << "Waterproof? (yes/no): ";
        string wp;
        getline(cin, wp);
        waterproof = (wp == "yes");
        closetItems.push_back(new Coat(name, type, color, patty, warmth, rainy, bassic, dressy, length, waterproof));
    }  
    
    
    else if (type == "Shoes") { 
        cout << "Enter yes if these shoes are open toe" << endl;
        string open;
        getline(cin, open);
        bool openToe = false;
        if (open == "yes"){
            openToe = true;
        }

        cout << "Enter yes if these shoes are heels" << endl;
        string heel;
        getline(cin, heel);
        bool heely = false;
        if (heel == "yes"){
            heely = true;
        }

        cout << "Enter yes if these shoes ar athletic sneakers" << endl;
        string sneak;
        getline(cin, sneak);
        bool sneaky = false;
        if (sneak == "yes"){
            sneaky = true;
        }
        closetItems.push_back(new Shoes(name, type, color, patty, warmth, rainy, bassic, dressy, openToe, heely, sneaky));
    }


}

template <typename T>
void Closet<T>::removeItem(string name) {
    bool exists = false;
    int index = -1;
    for(int i = 0; i < closetItems.size(); i++ ){
        if(closetItems[i]->getName() == name){
            exists = true;
            index = i;
            break;
        }
    }
    if(exists){
        closetItems.erase(closetItems.begin() + index);
    }
    else{
        cout << "An item with that name was not found in your closet";
    }

}

template <typename T>
vector<Clothing*> Closet<T>::generateOutfit(int dressiness, int avgTemp) {

    vector<Clothing*> outfit;
    vector<Clothing*> tops;
    vector<Clothing*> bottoms;
    vector<Clothing*> shoes;

    for(int i =0; i < closetItems.size(); i ++){
        if(closetItems[i]->getType() == "Top"){
            tops.push_back(closetItems[i]);
        }
        if(closetItems[i]->getType() == "Bottom"){
            bottoms.push_back(closetItems[i]);
        }
        if(closetItems[i]->getType() == "Shoes"){
            shoes.push_back(closetItems[i]);
        }
    }

    int minDress = dressiness - 1;
    int maxDress = dressiness + 1;

    //removing items that are not the appropriate level of dressy
    for(int i = tops.size() - 1; i >= 0; i--){
        if (!(tops[i]->getDressiness() >= minDress && tops[i]->getDressiness() <= maxDress)) {
            tops.erase(tops.begin() + i);
        }
    }

    for(int i = bottoms.size() - 1; i >= 0; i--){
        if(!(bottoms[i]->getDressiness() >= minDress && bottoms[i]->getDressiness() <= maxDress)){
            bottoms.erase(bottoms.begin() + i);
        }
    }

    for(int i = shoes.size() - 1; i >= 0; i--){
        if(!(shoes[i]->getDressiness() >= minDress && shoes[i]->getDressiness() <= maxDress)){
            shoes.erase(shoes.begin() + i);
        }
    }

    //removing inappropriate weather items 

    for(int i = tops.size() - 1; i >= 0; i--){
        int warmth = tops[i]->getWarmth() * 15;
        if(!(warmth >= avgTemp - 10 && warmth <= avgTemp + 10)){
            tops.erase(tops.begin() + i);
        }
    }

    for(int i = bottoms.size() - 1; i >= 0; i--){
        int warmth = bottoms[i]->getWarmth() * 15;
        if(!(warmth >= avgTemp - 10 && warmth <= avgTemp + 10)){
            bottoms.erase(bottoms.begin() + i);
        }
    }

    for(int i = shoes.size() - 1; i >= 0; i--){
        int warmth = shoes[i]->getWarmth() * 15;
        if(!(warmth >= avgTemp - 10 && warmth <= avgTemp + 10)){
            shoes.erase(shoes.begin() + i);
        }
    }

    int top = tops.size();
    int bottom = bottoms.size();
    int shoe = shoes.size();

    return outfit;
}
