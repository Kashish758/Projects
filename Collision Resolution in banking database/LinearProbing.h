#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "BaseClass.h"
#include <iostream>
#include <vector>
using namespace std;

class LinearProbing : public BaseClass {
public:
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;
    int binarysearch(vector<int> &vec, int count);
    void insert(vector<int> &vec, int count);
    LinearProbing(){
        size = 0;
        bankStorage1d.resize(resize_value);
        for (int i = 0; i<bankStorage1d.size(); i++){
            bankStorage1d[i].balance = -1;
        }
    }
    
private:
    // Other data members and functions specific to Linear Probing
    int size;
    vector<int> vec;
    int const resize_value = 100000;
};

#endif // LINEARPROBING_H
