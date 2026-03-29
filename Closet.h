#ifndef CLOSET_H
#define CLOSET_H

#include "Clothing.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Closet{
    public:
        void addItem();
        void removeItem(int idx);
        void showCloset();
        vector<Clothing> generateOutfit(int dressiness, int avgTemp);
        void saveOutfit();
        void showOutfits();

    private:
        vector<vector<Clothing>> savedOutfits;
        vector <Clothing> closetItems;

};

#endif