#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "Stock.h"
using namespace std;

Stock::Stock() {
}

Stock::Stock(string n, string t, double p, int q) {
    setTicker(t);
    setName(n);
    setPrice(p);
    setQuantity(q);
}

Stock::Stock(string n, string t, int q, double p) {
    setTicker(t);
    setName(n);
    setPrice(p);
    setQuantity(q);
}

Stock::Stock(Stock &other) {
    setTicker(other.getTicker());
    setName(other.getName());
    setPrice(other.getPrice());
    setQuantity(other.getQuantity());
}

void Stock::setTicker(string t){
    this->ticker = t;
}
void Stock::setPrice(double p){
    this->price = p;
}
void Stock::setQuantity(int q){
    this->quantity = q;
}

void Stock::setName(string n) {
    this->name = n;
}

string Stock::getName() const{
    return name;
}
string Stock::getKey() const{
    return ticker;
}

string Stock::getTicker() const{
    return ticker;
}

double Stock::getPrice() const{
    return price;
}

int Stock::getQuantity() const{
    return quantity;
}

bool Stock::operator<(const Stock &s1){
    if (this->getKey() < s1.getKey()) {
        return true;
    }
    return false;
}   

bool Stock::operator<=(const Stock &s1){
    if (this->getKey() < s1.getKey() || this->getKey() == s1.getKey()) {
        return true;
    }
    return false;
}

bool Stock::operator>(const Stock &s1){
    if (this->getKey() > s1.getKey()){
        return true;
    }
    return false;
}

bool Stock::operator>=(const Stock &s1){
    if (this->getKey() > s1.getKey() || this->getKey() == s1.getKey()) {
        return true;
    }
    return false;
}

bool Stock::operator==(const Stock &s1) {
    if (this->getKey() == s1.getKey()) {
        return true;
    }
    return false;
}

bool Stock::operator==(const string s1) {
    if (this->getKey() == s1) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream &output, const Stock &s) {
    output << left << setw(5) << s.ticker << ": "  << right << setw(4) << s.quantity << " @ $ " << right << setw(7) << s.price << " (" << s.name << ")";
    return output;
}