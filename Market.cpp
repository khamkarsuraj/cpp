#include <iostream>
#include "Market.h"

Market::Market() {
    day = 0;
    name="Default";
    head = new StockList();
}