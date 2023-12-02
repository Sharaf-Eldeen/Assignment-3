// LabelGenerator.cpp

#include "LabelGenerator.h"
#include <sstream>

// Constructor
LabelGenerator::LabelGenerator(const string& prefix, int initialIndex)
        : prefix(prefix), currentIndex(initialIndex) {}

// Destructor (if needed, currently not doing anything specific)
LabelGenerator::~LabelGenerator() {}

// Generates the next label in the sequence and returns it.
string LabelGenerator::nextLabel() {
    // Format the label using the prefix and current index.
    string label = formatLabel();

    // Increment the index for the next call.
    currentIndex++;

    return label;
}

// Private method to format the label based on the prefix and current index.
string LabelGenerator::formatLabel() {
    string currentIndexString = to_string(currentIndex);
    string oss = prefix + currentIndexString;
    return oss;
}
