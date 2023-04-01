#include <iostream>
#include <fstream>
#include "Market.h"

using namespace std;

Market::Market(){day = 0; name="Default"; head = new StockList();};
Market::Market(string name){day = 0; this->name = name; head = new StockList();};
Market::Market(string name, int market_num) {day = market_num; name=name; market_num = market_num; head = new StockList();};

void Market::readStockFile() {
    //create an input file stream
    ifstream infile(name + ".0.txt", ios::in);

    //check that we're able to open
    if (!infile){
        cerr << "Could not open file " + name << endl;
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
            //cout << *s << endl;	

            // ... add the stock the Market object's list of stocks
            this->head->insert(s);
        }
    }
}
        
void Market::readStockFile(int num_day) {
    //create an input file stream
    ifstream infile(name + "." + to_string(num_day) + ".txt", ios::in);

    //check that we're able to open
    if (!infile){
        cerr << "Could not open file " + name << endl;
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
            //cout << *s << endl;	

            // ... add the stock the Market object's list of stocks
            this->head->insert(s);
        }
    }
}
        
void Market::showStocks() {
    this->head->display2();
}

void Market::step() {
    StockNode* ptr = this->head->step_helper();
}

void Market::nextDay(){
    this->setDay(1);
};

void Market::writeStockFile(int curr_day){
    // create file for next day
    std::ofstream outfile (this->name + "." + to_string(curr_day) + ".txt");
    outfile.close();
    this->head->writeStockFile_helper(this->name + "." + to_string(curr_day) + ".txt");
};

int Market::getDay(){
    return this->day;
};

void Market::setDay(int inc) {
    this->day = this->day + inc;
}

void Market::addStock(Stock *s) {
    this->head->insert(s);
}

void Market::removeStock(string tick) {
    this->head->remove(tick);
}

StockNode * Market::getStockPtr(string tick) {
    return this->head->find(tick);
}