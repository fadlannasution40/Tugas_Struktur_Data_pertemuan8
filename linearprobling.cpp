#include <iostream>
#include<vector>
using namespace std;

const int table_size =10;
class HashTable{
    private:
        vector<int> table;
        int hashFunction(int key){
        return key % table_size;
    }
        public:
        HashTable(){
            table.resize(table_size, -1);
        }
        
        void insert(int key){
            int index = hashFunction(key);

            while (table[index] != -1) {
                index = (index + 1) % table_size;
            }
            table[index] = key;
        }

        void display(){
            for(int i=0; i<table_size; i++){
                cout << "Index " << i << ": ";
                if (table[i] != -1) {
                    cout << table[i];
                } else {
                    cout << "null";
                }
                cout << endl;
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
