#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Define a simple hash table entry to store word-frequency pairs.
struct HashEntry {
    string word;
    int frequency;

    HashEntry(const string& w) : word(w), frequency(1) {}
};

// Define a custom hash table class with basic operations.
class HashTable {
    public:
    vector<HashEntry> table;
    size_t size;

    // Custom hash function (simple example for demonstration purposes).
    size_t customHash(const string& key) {
        size_t hash = 0;
        for (char c : key) {
            hash = (hash * 31 + static_cast<size_t>(c)) % size;
        }
        return hash;
    }


   HashTable(size_t tableSize) : size(tableSize), table(tableSize, HashEntry("")) {}

    // Custom insert operation.
    void insert(const string& key) {
        size_t index = customHash(key);
        for (size_t i = index; i < size; i++) {
            if (table[i].word == key) {
                table[i].frequency++;
                return;
            }
            if (table[i].word.empty()) {
                table[i] = HashEntry(key);
                return;
            }
        }
    }

    // Custom search operation.
    int search(const string& key) {
        size_t index = customHash(key);
        for (size_t i = index; i < size; i++) {
            if (table[i].word == key) {
                return table[i].frequency;
            }
            if (table[i].word.empty()) {
                return 0;
            }
        }
        return 0;
    }
};

int main() {
    // Input text (you can replace this with your own text).
    string text = "This is a simple word frequency counter. It counts the frequency of each word in a given input text. This is a simple example.";

    // Split the input text.
    string word;
    istringstream stream(text);
    HashTable wordFrequency(100);//Example of 100 unit hash table

    while (stream >> word) {
        // Convert the word to lowercase (optional, for case-insensitive counting).
        for (char &c : word) {
            c = tolower(c);
        }
        // Update word frequency in the custom hash table.
        wordFrequency.insert(word);
    }

    // Print word frequencies.
    for (size_t i = 0; i < wordFrequency.size; i++) {
    if (!wordFrequency.table[i].word.empty()) {
        cout << wordFrequency.table[i].word << ": " << wordFrequency.table[i].frequency << endl;
    }
}

    return 0;
}
