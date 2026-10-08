#include "linked_list.h"
#include <cstdlib> // for abs
#include "my_vector.h"

class hash_table{ // Array of linked lists
private:
    int size;
    /*Restrains*/
    static constexpr int 
        MAX_SIZE = 211,
        MIN_SIZE = 101,
        MAX_ADD_SIZE = 10000,
        MIN_ADD_SIZE = -10000;
    // Hash table
    LinkedList** buckets; //list of ptrs
public:
    // Creation setting size / allocated memory
    hash_table(const int &size){
        if (size <= 0) // check if >0
            throw std::invalid_argument("Hash table size must be greater than 0");
        if ((size >= MAX_SIZE) || (size <= MIN_SIZE)) // check range 
            throw std::invalid_argument("Hash table size must be in range of 101-211");
        for (int i{2}; i < size; i++)  // check for prime
            if ((size % i) == 0 ) throw std::invalid_argument("Hash table needs to be a Prime Number");

        // Creation
        this->size = size;
        buckets = new LinkedList*[size]{}; // array of pointers; buckets start as null
    }
    // Destructor
    ~hash_table() {
        for (int i{0}; i < size; i++)
            delete buckets[i]; // delete pointer to LL at each index
        delete[] buckets;
    }

    void add(int numberToAdd){
        // validation
        if ((numberToAdd > MAX_ADD_SIZE) || (numberToAdd < MIN_ADD_SIZE))
            throw std::invalid_argument("Number to be added is out of range of instructions");
        //calculate idx once
        int idx = (std::abs(numberToAdd) % size);
        //check if bucket is already a LL
        if (buckets[idx] == nullptr) {
            buckets[idx] = new LinkedList(numberToAdd); // initialize + add at same time
        }
        else {
            buckets[idx]->append(numberToAdd);
        }
    }

    int bucketSize(const int &num){ // Get size of LL Given index
        // Get bucket to check
        const LinkedList* currBucket = buckets[(std::abs(num) % size)];
        if (currBucket == nullptr)
            return 0;
        else
            return currBucket->getSize(); // LL function, not hash function
    }
    int frequency(const int &num){ // get Freq of a number given index
        // Get bucket to check
        const LinkedList* currBucket = buckets[(std::abs(num) % size)];
        if (currBucket == nullptr)
            return 0;
        else
            return currBucket->count(num);
    }

    Vector<int> userInputs() {

        std::cout << "Enter numbers (-1 to end): ";
        Vector<int> userInputs; // vector of user inputs
        int number; // the number user enters

        std::cin >> number;

        // input stops when it is -1
        while (number != -1) {
            // size check (stops from adding any more)
            if (userInputs.size() > 1000) {
                std::cout << "Vector reached max size; will process previous data" << std::endl;
                break;
            }
            // if input can't be processed as integer (ex. string)
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout << "Invalid integer, re-enter: ";
            } else
            // bounds check
            if (number < MIN_ADD_SIZE || number > MAX_ADD_SIZE) {
                std::cin.clear();
                std::cout << "Out of range integer, re-enter: ";
            } else {
                std::cin.clear();
                add(number); // add to hash table
                // determine whether to push to vector based on frequency
                if (buckets[(std::abs(number) % size)]->count(number) == 1)
                    userInputs.pushback(number);
            } std::cin >> number; // reinput
        }
        if (userInputs.isEmpty()) {
            throw std::out_of_range("Vector is empty, cannot process information");
        }
        std::cin.ignore(); // delete remaining buffer
        return userInputs;
    }

    void output(Vector<int> &inputVector) {
        // use user input vector to see each input's frequency
        for (int i = 0; i < inputVector.size(); i++) {
            std::cout << "Value: " << inputVector.at(i) << " -> Frequency: " << frequency(inputVector.at(i)) << std::endl;
        }
    }
};
