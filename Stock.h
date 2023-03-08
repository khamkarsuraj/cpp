#include <string>
#include <iostream>
#include <sstream>

#ifndef STOCK_H
#define STOCK_H

using namespace::std;

class Stock{
    private:
        string ticker;
        string name;
        double price;
        int quantity;
    
    public :
        Stock();
        Stock(string n, string t, double p, int q);
        Stock(string n, string t, int q, double p);
        Stock(Stock &other);

        string getKey() const;
        string getName() const;
        string getTicker() const;
        double getPrice() const;
        int getQuantity() const;

        void setTicker(string ) ;
        void setName(string ) ;
        void setPrice(double ) ;
        void setQuantity(int ) ;

        bool operator<(const Stock &s1);
        bool operator<=(const Stock &s1);
        bool operator>(const Stock &s1);
        bool operator>=(const Stock &s1);
        bool operator==(const Stock &s1);
        bool operator==(const string s1);

        friend ostream& operator<<(ostream &output, const Stock &s);
};

#endif