#include <iostream>
#include <iomanip>
#include "StockNode.h"

class StockList {
    public:
        void insert(Stock *a);
        void display();
        void display2();
        bool contains(string ticker);
        StockNode *find(string ticker);
        void remove(Stock *a);
        void remove(string a);
        StockNode* step_helper();
        void writeStockFile_helper(string file_name);
    
    private:
        StockNode* head;
};