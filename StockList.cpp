#include <iostream>
#include <fstream>
#include "StockList.h"

using namespace std;

void StockList::insert(Stock *a) {
    StockNode *new_node = new StockNode();
    StockNode *curr = this->head;
    
    new_node->setStock(a);
    new_node->setNext(nullptr);

    // If list is empty new node would be first one
    if (this->head == nullptr) {
        this->head = new_node;
        return;
    }

    // logic to check and add if new node could be first one before head
    if (a->getTicker() < head->getStock().getTicker()) {
        new_node->setNext(head);
        this->head = new_node;
        return;
    }

    while (curr->getNext() != nullptr) {
        Stock *s = curr->getNext()->getStockPtr();

        // If there is node already with same ticker
        if (s->getTicker() == a->getTicker()) {
            return;
        }

        if (s->getTicker() > a->getTicker()) {
            StockNode *temp = curr->getNext();
            new_node->setNext(temp);
            curr->setNext(new_node);
            return;
        }
        curr = curr->getNext();
    }

    // logic for last node to check and add if new node could be last one
    if (curr->getNext() == nullptr) {
        cout<<"5"<<endl;
        curr->setNext(new_node);
    }
}

void StockList::display() {
    if (this->head==nullptr) {
        cout << "List Empty!" << endl;
    }

    StockNode *curr = this->head;

    while (curr != nullptr) {
        Stock *cs = curr->getStockPtr();
        cout << left << setw(5) << cs->getTicker() << ": "  << right << setw(5) << (int) cs->getPrice() << " @ $ " << fixed << showpoint << setprecision(2) << right << setw(7) << (float) cs->getQuantity() << " (" << cs->getName() << ")" << endl;
        curr= curr->getNext();
    }
}

void StockList::display2() {
    if (this->head==nullptr) {
        cout << "List Empty!" << endl;
    }

    StockNode *curr = this->head;

    while (curr != nullptr) {
        Stock *cs = curr->getStockPtr();
        cout << *cs << endl;
        curr= curr->getNext();
    }
}

StockNode* StockList::step_helper() {
    if (this->head==nullptr) {
        cout << "List Empty!" << endl;
    }

    StockNode *curr = this->head;

    while (curr != nullptr) {
        Stock *cs = curr->getStockPtr();
        int r = rand() % 10 + 1;
        r = r - 5;
        float s = (float) r/100;
        s = 1 + s;
        cs->setPrice(cs->getPrice() * s);
        curr= curr->getNext();
    }
    
    return this->head;
}

void StockList::writeStockFile_helper(string file_name) {
    ofstream outfile;
    outfile.open(file_name);

    if (this->head==nullptr) {
        cout << "List Empty!" << endl;
    }

    StockNode *curr = this->head;

    while (curr != nullptr) {
        Stock *cs = curr->getStockPtr();
        outfile << *cs << endl;
        curr= curr->getNext();
    }

    outfile.close();
}

bool StockList::contains(string ticker) {
    StockNode *curr = this->head;

    while (curr != nullptr) {
        if (curr->getStock().getTicker() == ticker) {
            return true;
        }
        curr = curr->getNext();
    }

    return false;
}

StockNode* StockList::find(string ticker) {
    StockNode *curr = this->head;

    while (curr != nullptr) {
        if (curr->getStock().getTicker() == ticker) {
            return curr;
        }
        curr = curr->getNext();
    }

    return nullptr;   
}

void StockList::remove(Stock *a) {
    StockNode *curr = this->head;

    if (curr==nullptr) {
        cout << "There is nothing to remove" << endl;
    }

    // Remove first node
    if (curr->getStock().getTicker() == a->getTicker()) {
        StockNode *temp = curr;
        curr = curr->getNext();
        this->head = curr;
        temp->setNext(nullptr);
        return;
    }
    
    // Remove node in between
    while (curr->getNext() != nullptr) {
        if (curr->getNext()->getStock().getTicker() == a->getTicker()) {
            StockNode *temp = curr->getNext();
            curr->setNext(temp->getNext());
            temp->setNext(nullptr);
            return;
        }
        curr = curr->getNext();
    }

    // Remove last node
    if (curr->getNext() == nullptr && curr->getStock().getTicker() == a->getTicker()) {
        cout << "In4" << endl;
        curr->setNext(nullptr);
        return;
    }
}

void StockList::remove(string a) {
    StockNode *curr = this->head;

    if (curr==nullptr) {
        cout << "There is nothing to remove" << endl;
    }

    // Remove first node
    if (curr->getStock().getTicker() == a) {
        StockNode *temp = curr;
        curr = curr->getNext();
        this->head = curr;
        temp->setNext(nullptr);
        return;
    }
    
    // Remove node in between
    while (curr->getNext() != nullptr) {
        if (curr->getNext()->getStock().getTicker() == a) {
            StockNode *temp = curr->getNext();
            curr->setNext(temp->getNext());
            temp->setNext(nullptr);
            return;
        }
        curr = curr->getNext();
    }

    // Remove last node

    if (curr->getNext() == nullptr && curr->getNext()->getStock().getTicker() == a) {
        curr->setNext(nullptr);
        return;
    }
}