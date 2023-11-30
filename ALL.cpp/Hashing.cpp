#include <iostream>
#include <string>

using namespace std;

// Define a structure for a key-value pair
struct KeyValue {
    char key;
    string value;
    KeyValue* next;
    KeyValue(char k, string v) : key(k), value(v), next(nullptr) {}
};

// Define the size of the hashmap array (ASCII values 0-127)
const int HASH_MAP_SIZE = 128;

// Function to insert a key-value pair into the hashmap
void insert(KeyValue* hashmap[], string word) {
    char hash_key = word[0];
    int index = (int)hash_key;

    // Create a new KeyValue pair
    KeyValue* pair = new KeyValue(hash_key, word);

    // Add the pair to the linked list at the appropriate index
    pair->next = hashmap[index];
    hashmap[index] = pair;
}

// Function to retrieve a value based on the key
string get(KeyValue* hashmap[], char key) {
    int index = (int)key;

    // Search for the key in the linked list at the index
    KeyValue* current = hashmap[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return "Key not found";
}

int main() {
    KeyValue* hashmap[HASH_MAP_SIZE] = {nullptr};

    cout << "Enter words. Enter 'exit' to stop." << endl;

    while (true) {
        cout << "Enter a word: ";
        string word;
        cin >> word;

        if (word == "exit") {
            break;
        }

        insert(hashmap, word);
    }

    // Retrieve values based on keys
    cout << "Enter keys to retrieve words. Enter '0' to stop." << endl;

    while (true) {
        cout << "Enter key (single character): ";
        char key;
        cin >> key;

        if (key == '0') {
            break;
        }

        string result = get(hashmap, key);
        cout << "Word: " << result << endl;
    }

    // Clean up memory by deleting allocated KeyValue pairs
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        KeyValue* current = hashmap[i];
        while (current != nullptr) {
            KeyValue* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}
