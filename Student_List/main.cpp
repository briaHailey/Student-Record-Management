// Bria Weisblat Section: 2

#include <iostream>
#include <string>
#include "studentlist.h"

int main() {
    char selection;
    StudentList s;

    //Print the menu for the first time
    std::cout << "\t\t*** Student List menu ***\n";
    std::cout << "I       Import students from a file\n";
    std::cout << "S       Show student list (brief)\n";
    std::cout << "E       Export a grade report (to file)\n";
    std::cout << "M       Show this Menu\n";
    std::cout << "O       sOrt student list\n";
    std::cout << "Q       Quit Program\n";

    //Keep asking the user to make a selection unless they enter Q
    do {
        std::cout << "\nMake a selection: ";
        std:: cin >> selection;
        // Accept upper and lowercase input
        selection = toupper(selection);
        // Print an error message if the user entered an invalid selection
        while ( (selection != 'I') && (selection != 'S') && (selection != 'E') && (selection != 'M') && (selection != 'O') && (selection != 'Q')){
            std:: cout << "This is not a valid selection. Enter a new selection: ";
            std:: cin >> selection;
            selection = toupper(selection);
        }

        switch (selection){
            //Import a file
            case 'I': {
                string filename;
                cout << "Please enter a file: ";
                cin >> filename;
                bool isWork = s.ImportFile(filename);
                if (isWork) {
                    cout << "Imported!";
                } else {
                    cout << "Import failed.";
                }
                break;
            }
            //Show list of students
            case 'S':
                s.ShowList();
                break;

            //Export a grade report to a file
            case 'E': {
                string filename;
                cout << "Please enter a file: ";
                cin >> filename;
                bool isWork = s.CreateReportFile(filename);
                if (isWork) {
                    cout << "Exported!";
                } else {
                    cout << "Export failed.";
                }
                break;
            }
            //Print the menu
            case 'M':
                std::cout << "\t\t*** Student List menu ***\n";
                std::cout << "I       Import students from a file\n";
                std::cout << "S       Show student list (brief)\n";
                std::cout << "E       Export a grade report (to file)\n";
                std::cout << "M       Show this Menu\n";
                std::cout << "O       sOrt student list\n";
                std::cout << "Q       Quit Program\n";
                break;

            //Alphabetically sort the students
            case 'O':
                s.sortStudents();
                std::cout << "Sorted!";
                break;
        }

    } while (selection != 'Q');

    // Goodbye message
    if (selection == 'Q'){
        std::cout << "\nGoodbye!";
    }
}
