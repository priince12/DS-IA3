
/*
    Data Structures - Internal Assessment 3
    Question 2: Hash Table Implementation

    Student PRN: 202501100060
    Scenario: Mango Varieties
    Seed (S): 60
    Dataset: 20 personalized values
    Hash Function: Division Method
    Collision Strategy: Linear Probing
    Table Size: 29

    Features:
    1. Division Method Hash Function
    2. Linear Probing
    3. Collision Counter
    4. Duplicate Key Detection
    5. Negative Key Validation
    6. Insertion Summary and Statistics
*/

#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 29;

int collisionCount = 0;
int insertedCount = 0;

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insertKey(vector<int>& table, int key)
{
    if (key < 0)
    {
        cout << "\nInvalid key " << key
             << ". Negative values are not allowed.";
        return;
    }

    // Check for duplicate keys
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] == key)
        {
            cout << "\nDuplicate key " << key << " ignored.";
            return;
        }
    }

    int index = hashFunction(key);
    int originalIndex = index;

    cout << "\nInserting " << key
         << " | Hash index = " << index;

    // Linear Probing
    while (table[index] != -1)
    {
        collisionCount++;

        cout << " | Collision at index " << index;

        index = (index + 1) % TABLE_SIZE;

        if (index == originalIndex)
        {
            cout << "\nHash table is full!";
            return;
        }
    }

    table[index] = key;
    insertedCount++;

    cout << " | Inserted at index " << index;
}

void displayTable(const vector<int>& table)
{
    cout << "\n\n========== FINAL HASH TABLE ==========\n";
    cout << "Index\tValue\n";

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << i << "\t";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }
}

// Display insertion statistics
void displayStatistics(const vector<int>& table)
{
    int occupiedCount = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != -1)
            occupiedCount++;
    }

    int emptyCount = TABLE_SIZE - occupiedCount;

    cout << "\n\n========== INSERTION SUMMARY ==========\n";
    cout << "Total dataset values: 20" << endl;
    cout << "Successfully inserted: " << insertedCount << endl;
    cout << "Total collisions: " << collisionCount << endl;
    cout << "Occupied positions: " << occupiedCount << endl;
    cout << "Empty positions: " << emptyCount << endl;
}

int main()
{
    int dataset[20] = {
        60, 73, 86, 99, 12,
        25, 38, 51, 64, 77,
        90, 3, 16, 29, 42,
        55, 68, 81, 94, 7
    };

    vector<int> hashTable(TABLE_SIZE, -1);

    cout << "DATA STRUCTURES IA 3 - QUESTION 2\n";
    cout << "PRN: 202501100060\n";
    cout << "Scenario: Mango Varieties\n";
    cout << "Hash Function: Division Method\n";
    cout << "Collision Handling: Linear Probing\n";
    cout << "Table Size: " << TABLE_SIZE << endl;

    cout << "\nPersonalized Dataset:\n";

    for (int i = 0; i < 20; i++)
        cout << dataset[i] << " ";

    cout << "\n\n========== INSERTION PROCESS ==========\n";

    for (int i = 0; i < 20; i++)
        insertKey(hashTable, dataset[i]);

    // Duplicate-key test
    cout << "\n\n========== DUPLICATE KEY TEST ==========\n";
    insertKey(hashTable, 60);

    // Negative-key test
    cout << "\n\n========== INVALID KEY TEST ==========\n";
    insertKey(hashTable, -10);

    displayStatistics(hashTable);
    displayTable(hashTable);

    return 0;
}
