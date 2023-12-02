// FileLabelGenerator.h

#ifndef FILE_LABEL_GENERATOR_H
#define FILE_LABEL_GENERATOR_H

#include "LabelGenerator.h"
#include <fstream>
#include <string>

class FileLabelGenerator : public LabelGenerator {
public:
    // Constructor: Initializes the FileLabelGenerator with a prefix, initial index, and a file name.
    FileLabelGenerator(const string& prefix, int initialIndex, const string& fileName);

    // Destructor: Cleans up any resources if needed.
    ~FileLabelGenerator();

    // Overrides the nextLabel method to read labels from the file and append them to the generated label.
    string nextLabel() override;

private:
    ifstream fileStream;  // Input file stream to read labels from the file.

    // Private method to read the next line from the file.
    string readNextLine();
};

#endif // FILE_LABEL_GENERATOR_H
