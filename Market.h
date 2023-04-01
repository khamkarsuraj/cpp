#include <iostream>
#include <fstream>
#include "StockList.h"

using namespace std;

class Market {
    private:
        //StockList *head = new StockList();
        StockList *head = nullptr;
        int day;
        string name;
        int market_num;

    public:
        Market();
        Market(string name);
        Market(string name, int market_num);
        void readStockFile();
        void readStockFile(int num_day);
        void showStocks();

        void step();

        void nextDay();

	    void writeStockFile(int curr_day);

        int getDay();

        void setDay(int inc);

        void addStock(Stock *s);

        void removeStock(string tick);

        StockNode *getStockPtr(string tick);
};