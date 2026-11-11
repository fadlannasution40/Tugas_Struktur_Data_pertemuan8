#include <iostream>
#include<vector>
#include<string>
using namespace std;

const int table_size =10;
class HashTable{
    private:
        vector<int> table;
        vector<string> nama;
        int hashFunction1(int key){
        return key % table_size;
    }
        int hashFunction2(int key){
        return 7 - (key % 7);
    }
        public:
        HashTable(){
            table.resize(table_size, -1);
            nama.resize(table_size, "");
        }

        void insert(int key, string value){
            int index = hashFunction1(key);
            int step = hashFunction2(key);
            int firstDeleted = -1;

            for(int i=0; i<table_size; i++){
                int pos = (index + i * step) % table_size;

                if (table[pos] == key) {
                    cout << "NIM " << key << " sudah ada" << endl;
                    return;
                }
                if (table[pos] == -2 && firstDeleted == -1) {
                    firstDeleted = pos;
                }
                if (table[pos] == -1) {
                    if (firstDeleted != -1) pos = firstDeleted;
                    table[pos] = key;
                    nama[pos] = value;
                    return;
                }
            }

            if (firstDeleted != -1) {
                table[firstDeleted] = key;
                nama[firstDeleted] = value;
                return;
            }
            cout << "Hash table penuh" << endl;
        }

        void search(int key){
            int index = hashFunction1(key);
            int step = hashFunction2(key);

            for(int i=0; i<table_size; i++){
                int pos = (index + i * step) % table_size;

                if (table[pos] == -1) {
                    break;
                }
                if (table[pos] == key) {
                    cout << "NIM " << key << " ditemukan di index " << pos
                         << ", nama: " << nama[pos] << endl;
                    return;
                }
            }
            cout << "NIM " << key << " tidak ditemukan" << endl;
        }

        void remove(int key){
            int index = hashFunction1(key);
            int step = hashFunction2(key);

            for(int i=0; i<table_size; i++){
                int pos = (index + i * step) % table_size;

                if (table[pos] == -1) {
                    break;
                }
                if (table[pos] == key) {
                    table[pos] = -2;
                    nama[pos] = "";
                    cout << "NIM " << key << " dihapus dari index " << pos << endl;
                    return;
                }
            }
            cout << "NIM " << key << " tidak ditemukan" << endl;
        }

        void display(){
            for(int i=0; i<table_size; i++){
                cout << "Index " << i << ": ";
                if (table[i] >= 0) {
                    cout << table[i] << " - " << nama[i];
                } else if (table[i] == -2) {
                    cout << "deleted";
                } else {
                    cout << "null";
                }
                cout << endl;
            }
        }
};

int main(){
    HashTable ht;

    ht.insert(2024001, "Andi");
    ht.insert(2024002, "Budi");
    ht.insert(2024011, "Citra");
    ht.insert(2024021, "Dewi");
    ht.insert(2024005, "Eka");
    ht.insert(2024015, "Fajar");

    ht.search(2024011);
    ht.search(2024099);

    ht.remove(2024001);
    ht.remove(2024099);

    ht.search(2024001);
    ht.search(2024011);

    ht.display();

    return 0;
}
