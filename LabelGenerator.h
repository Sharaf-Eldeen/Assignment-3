// LabelGenerator.h

#ifndef LABEL_GENERATOR_H
#define LABEL_GENERATOR_H

#include <string>
using namespace std ;

class LabelGenerator {
private:
    string prefix;  // Prefix for the label (e.g., "Figure " or "P").
    int currentIndex;    // Current index in the sequence.

    // Private method to format the label based on the prefix and current index.
    string formatLabel();

public:
    // Constructor: Initializes the LabelGenerator with a prefix string and an initial index.
    LabelGenerator(const string& prefix, int initialIndex);

    // Destructor: Cleans up any resources if needed.
    ~LabelGenerator();

    // Generates the next label in the sequence and returns it.
    virtual string nextLabel();
};

#endif // LABEL_GENERATOR_H
