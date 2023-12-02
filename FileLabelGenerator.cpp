// FileLabelGenerator.cpp

#include "FileLabelGenerator.h"

// Constructor
FileLabelGenerator::FileLabelGenerator(const string& prefix, int initialIndex, const string& fileName)
    : LabelGenerator(prefix, initialIndex), fileStream(fileName) {}

// Destructor
FileLabelGenerator::~FileLabelGenerator() {
    // Close the file stream when the object is destroyed.
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

// Overrides the nextLabel method to read labels from the file and append them to the generated label.
string FileLabelGenerator::nextLabel() {
    // Call the parent's nextLabel to get the base label.
    string baseLabel = LabelGenerator::nextLabel();

    // Read the next line from the file.
    string fileLabel = readNextLine();

    // Combine the base label and file label.
    return baseLabel + " " + fileLabel;
}

// Private method to read the next line from the file.
string FileLabelGenerator::readNextLine() {
    string line;
    if (getline(fileStream, line)) {
        return line;
    } else {
        // If the end of the file is reached, rewind to the beginning for the next iteration.
        fileStream.clear();
        fileStream.seekg(0, ios::beg);

        // Read the first line.
        getline(fileStream, line);
        return line;
    }
}
