#include <iostream>
#include <fstream>
#include "StockList.h"

using namespace std;

class Market {
    private:
        StockList *head = new StockList();
        string name = "Default";
        int market_num;

    public:
        Market(){};
        Market(string name){name = name;};
        Market(string name, int market_num) {name=name; market_num = market_num;};
        void readStockFile() {
            //create an input file stream
            cout << "Stocks for Market: Default" << endl;
            ifstream infile("Default.0.txt", ios::in);

            //check that we're able to open
            if (!infile){
                cerr << "Could not open file day0.txt" << endl;
                exit(EXIT_FAILURE);
            }

            string ticker;
            string name;
            double price;
            int quantity;

            // temp variable to hold one line of text from the file
            string line;

            // temp variable to hold one character version of price & quantity
            string temp_word;

            // read one line at time from the file of stock info
            while (getline(infile, line)){
                if (line.size() > 1){

                    //treat the string containing line as a stream named words
                    istringstream words(line);

                    //read from words into ticker until we see a comma
                    getline(words, ticker, ',');

                    //continuing reading, now into name, until we see a comma
                    getline(words, name, ',');

                    //continuing reading, now into temp_word, until we see a comma
                    // and assign to price
                    getline(words, temp_word, ',');
                    price = stod(temp_word);

                    //continuing reading, now into temp_word, until we see a comma
                    // and assign to quantity
                    getline(words, temp_word, '\n');
                    quantity = stoi(temp_word);
            
                    Stock *s = new Stock(name, ticker, price, quantity);
                    cout << *s << endl;	

                    // ... add the stock the Market object's list of stocks
                    this->head->insert(s);
                }
            }
        }
        
        void showStocks() {
            this->head->display();
        }
};
