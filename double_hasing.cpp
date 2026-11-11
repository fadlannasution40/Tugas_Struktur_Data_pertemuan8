#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10;


enum Status { EMPTY = 0, OCCUPIED = 1, DELETED = 2 };


class HashTable {
private:
    vector<pair<int, string>> table;
    vector<int> status;

    int hash1(int key) const {
        return key % TABLE_SIZE;
    }

    int hash2(int key) const {
        return 7 - (key % 7);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE, make_pair(-1, ""));
        status.resize(TABLE_SIZE, EMPTY);
    }

    void insert(int key, const string& value) {
        int index = hash1(key);
        int step = hash2(key);
        int firstDeleted = -1;

        for (int i = 0; i < TABLE_SIZE; i++) {
            if (status[index] == OCCUPIED && table[index].first == key) {
                table[index].second = value;
                return;
            }
            if (status[index] == DELETED && firstDeleted == -1) {
                firstDeleted = index;
            }
            if (status[index] == EMPTY) {
                int target = (firstDeleted != -1) ? firstDeleted : index;
                table[target] = make_pair(key, value);
                status[target] = OCCUPIED;
                return;
            }

            index = (index + step) % TABLE_SIZE;
        }

       
        if (firstDeleted != -1) {
            table[firstDeleted] = make_pair(key, value);
            status[firstDeleted] = OCCUPIED;
        } else {
            cout << "Hash table penuh" << endl;
        }
    }

    void search(int key) const {
        int index = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < TABLE_SIZE && status[index] != EMPTY; i++) {
            if (status[index] == OCCUPIED && table[index].first == key) {
                cout << "Data ditemukan: (" << table[index].first << ", "
                     << table[index].second << ")" << endl;
                return;
            }
            index = (index + step) % TABLE_SIZE;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void remove(int key) {
        int index = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < TABLE_SIZE && status[index] != EMPTY; i++) {
            if (status[index] == OCCUPIED && table[index].first == key) {
                status[index] = DELETED;
                cout << "Data berhasil dihapus: (" << table[index].first << ", "
                     << table[index].second << ")" << endl;
                return;
            }
            index = (index + step) % TABLE_SIZE;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void display() const {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            if (status[i] == OCCUPIED) {
                cout << "(" << table[i].first << " - " << table[i].second << ")";
            } else if (status[i] == DELETED) {
                cout << "deleted";
            } else {
                cout << "empty";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(23, "Andi");
    ht.insert(43, "Budi");
    ht.insert(13, "Citra");
    ht.insert(35, "Dewi");

    cout << "Isi hash table:" << endl;
    ht.display();

    cout << "\nMencari key 43:" << endl;
    ht.search(43);

    cout << "\nMenghapus key 43:" << endl;
    ht.remove(43);

    cout << "\nIsi hash table setelah penghapusan:" << endl;
    ht.display();

    return 0;
}
