#include <iostream>
#include<vector>
#include<list>
using namespace std;

const int table_size =10;
class HashTable{
    private:
        vector<list<int>> table;
        int hashFunction(int key){
        return key % table_size;
    }
        public:
        HashTable(){
            table.resize(table_size);
        }
        
        void insert(int key){
            int index = hashFunction(key);

            table[index].push_back(key);
        }

        void display(){
            for(int i=0; i<table_size; i++){
                cout << "Index " << i << ": ";
                for(int data: table[i]){
                    cout << data << " -> ";
                }
                cout << "null" << endl;
            }
        }
};

int main(){
    HashTable ht;

    ht.insert(23);
    ht.insert(43);
    ht.insert(13);
    ht.insert(35);

    ht.display();

    return 0;
}
