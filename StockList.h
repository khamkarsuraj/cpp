#include <iostream>
#include <iomanip>
#include "StockNode.h"

class StockList {
    public:
        void insert(Stock *a);
        void display();
        bool contains(string ticker);
        StockNode *find(string ticker);
        void remove(Stock *a);
        void remove(string a);
    
    private:
        StockNode* head;
};