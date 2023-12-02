// main.cpp

#include "LabelGenerator.cpp"
#include "FileLabelGenerator.cpp"
#include <iostream>

int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    FileLabelGenerator figureLabels("Figure ", 1, "labels.txt");

    cout << "Task 1" << endl << endl;

    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel();
        if (i<2){
            cout << ", " ;
        }
    }

    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel();
        if (i<4){
            cout << ", " ;
        }
    }

    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel();
        if (i<2){
            cout << ", " ;
        }
    }

    cout << endl << endl;

    cout << "Task 2" << endl << endl;
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }

    return 0;
}
