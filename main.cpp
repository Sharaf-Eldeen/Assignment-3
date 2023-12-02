#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    double gpa;

    // Default constructor
    Student() : name(""), gpa(0.0) {}

    // Parameterized constructor
    Student(string name, double gpa) : name(name), gpa(gpa) {}

    // Overload == operator
    bool operator==(const Student& other) const {
        return (name == other.name && gpa == other.gpa);
    }

    // Overload != operator
    bool operator!=(const Student& other) const {
        return !(*this == other);
    }
};

template <typename T>
class Set {
private:
    vector<T> items;

public:
    // Add a new item to the set.
    void add(const T& item) {
        if (find(items.begin(), items.end(), item) == items.end()) {
            items.push_back(item);
        }
    }

    // Remove an item from the set.
    void remove(const T& item) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            items.erase(it);
        }
    }

    // Return the number of items in the set.
    size_t size() const {
        return items.size();
    }

    // Determine if an item is a member of the set.
    bool contains(const T& item) const {
        return find(items.begin(), items.end(), item) != items.end();
    }

    // Return a pointer to a dynamically created array containing each item in the set.
    T* toArray() const {
        T* array = new T[items.size()];
        copy(items.begin(), items.end(), array);
        return array;
    }
};

int main() {
    // Example usage with integers
    Set<int> intSet;
    intSet.add(1);
    intSet.add(2);
    intSet.add(3);
    intSet.add(1);

    cout << "Size of intSet: " << intSet.size() << endl;

    intSet.remove(2);

    cout << "Size of intSet after removal: " << intSet.size() << endl;

    cout << "Is 1 in intSet? " << (intSet.contains(1) ? "Yes" : "No") << endl;

    int* intArray = intSet.toArray();
    cout << "The address of dynamically created array: " << intArray << endl;
    delete[] intArray;
    cout << "We have already de-allocated the memory." << endl;

    // Example usage with Student class
    Set<Student> studentSet;
    studentSet.add(Student("Mahmoud", 3.0));
    studentSet.add(Student("Ahmed", 2.0));
    studentSet.add(Student("Omar", 3.5));
    studentSet.add(Student("Mahmoud", 3.0));
    
    cout << "Size of studentSet: " << studentSet.size() << endl;

    studentSet.remove(Student("Ahmed", 2.0));

    cout << "Size of studentSet after removal: " << studentSet.size() << endl;

    cout << "Is Ahmed in studentSet? " << (studentSet.contains(Student("Ahmed", 2.0)) ? "Yes" : "No") << endl;

    Student* studentArray = studentSet.toArray();
    cout << "The address of dynamically created array: " << studentArray << endl;
    delete[] studentArray;
    cout << "We have already de-allocated the memory." << endl;

    return 0;
}
