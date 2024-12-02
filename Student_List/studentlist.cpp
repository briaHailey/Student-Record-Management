// Bria Weisblat Section: 2

#include "studentlist.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;


//Calculates and assigns letter grades based on the final average
char LetterGrade(double finalAvg) {
    if (finalAvg >= 90){
        return 'A';
    }
    else if ( (finalAvg < 90) && (finalAvg >= 80)){
        return 'B';
    }
    else if ((finalAvg < 80) && (finalAvg >= 70)){
        return 'C';
    }
    else if ((finalAvg < 70) && (finalAvg >= 60)){
        return 'D';
    }
    else if (finalAvg < 60){
        return 'F';
    }
}

//Creates an empty student list
StudentList::StudentList() {
    studArray = nullptr;
    numStudents = 0;
}

//Import student information from a file
bool StudentList::ImportFile(string filename) {
    //Create a file object
    int fileStudents;

    bool didWork = true;
    ifstream import;

    //Open the file
    import.open(filename);
    //Print an error message if the file cannot be opened
    if (!import)
    {
        std::cout << "Invalid file. No data imported.";
        didWork = false;
    }
    //Read in the number of students from the file
    import >> fileStudents;
    //Create a new array if needed
    if (!studArray)
        studArray = new Grades * [fileStudents];
    else {
        // Create new array of the full size (numstudents+filestudents)
        Grades ** temp = new Grades *[numStudents + fileStudents];
        //Copy values over
        for (int i =0; i < numStudents; i++){
            temp[i] = studArray[i];
        }
        delete [] studArray;
        //Reassign poiters
        studArray = temp;
    }
    //For each student in the file
    for (int i = 0; i < fileStudents; i++) {
        char type;
        string tempLast;
        string tempFirst;
        //Get the last name up to the comma
        import.ignore();
        getline(import, tempLast, ',');
        //Get the first name up until newline
        import.ignore();
        getline(import, tempFirst);
        //Get the student's course
        import.get(type);
        //Ignore leading white space and read in grades depending on the student's major
        switch (type) {
            case 'B': {
                double labGrade, test1, test2, test3, bioFinal;
                import.ignore(7);
                import >> labGrade >> test1 >> test2 >> test3 >> bioFinal;
                studArray[numStudents] = new Biology(tempFirst, tempLast, type, labGrade, test1, test2, test3, bioFinal);
                break;
            }
            case 'C': {
                double p1, p2, p3, p4, p5, p6, programAvg, test1, test2, csFinal;
                import.ignore(16);
                import >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
                import >> test1 >> test2 >> csFinal;
                studArray[numStudents] = new ComputerScience(tempFirst, tempLast, type, p1, p2, p3, p4, p5, p6, programAvg, test1, test2, csFinal);
                break;
            }
            case 'T':
                double participation, midterm, theaterFinal;
                import.ignore(7);
                import >> participation >> midterm >> theaterFinal;
                studArray[numStudents] = new Theater(tempFirst, tempLast, type, participation, midterm, theaterFinal);
                break;
        }
        numStudents++;
        if (!import)
            cout << "Error";
    }
    return didWork;
}

bool StudentList::CreateReportFile(string filename) {
    bool didExport = true;
    ofstream exportGrades;
    exportGrades.open(filename);

    //Print an error message if the information cannot be exported
    if(!exportGrades.is_open()) {
        cout << "Bad file.";
        didExport = false;
    }

    //Biology heading
    exportGrades << "Student Grade Summary\n---------------------";
    exportGrades << "\n\nBIOLOGY CLASS\n\n";
    exportGrades << "Student                                        Final Final   Letter\n";
    exportGrades << "Name                                           Exam  Avg     Grade\n";
    exportGrades << "----------------------------------------------------------------------\n";

    char letterGrade = 'O';
    for (int i = 0; i < numStudents; i++){
        //Only print biology students under the biology heading
        if ( studArray[i]->getMajor() == 'B' ){
            studArray[i]->printGradeReport(exportGrades);
            //Assign corresponding letter grade and keep track
            letterGrade = LetterGrade(studArray[i]->gradeReport());
            switch (letterGrade) {
                case 'A':
                    aCount++;
                    break;
                case 'B':
                    bCount++;
                    break;
                case 'C':
                    cCount++;
                    break;
                case 'D':
                    dCount++;
                    break;
                case 'F':
                    fCount++;
                    break;
            }
            exportGrades << letterGrade << '\n';
        }
    }

    //Theater heading
    exportGrades << "\n\nTHEATER CLASS\n\n";
    exportGrades << "Student                                        Final Final   Letter\n";
    exportGrades << "Name                                           Exam  Avg     Grade\n";
    exportGrades << "----------------------------------------------------------------------\n";

    for (int i = 0; i < numStudents; i++){
        //Only print theater students under the theater heading
        if ( studArray[i]->getMajor() == 'T' ){
            studArray[i]->printGradeReport(exportGrades);
            //Assign corresponding letter grade and keep track
            letterGrade = LetterGrade(studArray[i]->gradeReport());
            switch (letterGrade) {
                case 'A':
                    aCount++;
                    break;
                case 'B':
                    bCount++;
                    break;
                case 'C':
                    cCount++;
                    break;
                case 'D':
                    dCount++;
                    break;
                case 'F':
                    fCount++;
                    break;
            }
            exportGrades << letterGrade << '\n';
        }
    }
    //Computer Science heading
    exportGrades << "\n\nCOMPSCI CLASS\n\n";
    exportGrades << "Student                                        Final Final   Letter\n";
    exportGrades << "Name                                           Exam  Avg     Grade\n";
    exportGrades << "----------------------------------------------------------------------\n";

    for (int i = 0; i < numStudents; i++){
        //Only print compsci students under the compsci heading
        if ( studArray[i]->getMajor() == 'C' ){
            studArray[i]->printGradeReport(exportGrades);
            //Assign corresponding letter grade and keep track
            letterGrade = LetterGrade(studArray[i]->gradeReport());
            switch (letterGrade) {
                case 'A':
                    aCount++;
                    break;
                case 'B':
                    bCount++;
                    break;
                case 'C':
                    cCount++;
                    break;
                case 'D':
                    dCount++;
                    break;
                case 'F':
                    fCount++;
                    break;
            }
            exportGrades << letterGrade << '\n';
        }
    }
    //Print the grade distribution after all of the student information has been printed
    printGradeDist(exportGrades);

    return didExport;
}

//Destructor
StudentList::~StudentList() {
    delete [] studArray;
}

//Print the students last and first name and the course they are in
void StudentList::ShowList() const {
    std::cout << "Last" << "                \t" << "First               \t" << "Course" << "\n\n";
    for (int i = 0; i < numStudents; i++){
        studArray[i]->printStudent();
        std::cout << "\n";
    }
}

//Print the grade distribution
void StudentList::printGradeDist(ostream& exportFile) {
    exportFile << "\nOVERALL GRADE DISTRIBUTION\n";
    exportFile << "A:   " << aCount << "\n";
    exportFile << "B:   " << bCount << "\n";
    exportFile << "C:   " << cCount << "\n";
    exportFile << "D:   " << dCount << "\n";
    exportFile << "F:   " << fCount << "\n";
}

//Sort students alphabetically
void StudentList::sortStudents(){
    //Create a new dynamic array of string objects
    string* tempLower = new string[numStudents];
    //Populate the string with the last names of every student
    for (int k =0; k < numStudents; k++){
        tempLower[k] = studArray[k]->getLastName();
        //Convert all characters in all of the last names to lowercase
        for (int l=0; l < studArray[k]->getLastName().length(); l++){
            tempLower[k][l] = tolower(studArray[k]->getLastName()[l]);
        }
    }

    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            // Bubble sort based on last name
            if ((tempLower[j].compare(tempLower[j + 1]) ) > 0) {
                Grades* temp = StudentList::studArray[j];
                studArray[j] = studArray[j + 1];
                studArray[j + 1] = temp;
                // Switch the positions of the names in the array
                string temp2 = tempLower[j];
                tempLower[j] = tempLower[j+1];
                tempLower[j+1] = temp2;
           }
            //If the last names are the same, bubble sort by the first name
            else if (((tempLower[j].compare(tempLower[j + 1]) ) == 0)){
                //Create a new dynamic array of string objects
                string* tempLowerFirst = new string[numStudents];
                //Populate the string with the first names
                for (int k =0; k < numStudents; k++){
                    tempLowerFirst[k] = studArray[k]->getFirstName();
                    //Convert all of the characters of the first names to lower case
                    for (int l=0; l < studArray[k]->getFirstName().length(); l++){
                        tempLowerFirst[k][l] = tolower(studArray[k]->getFirstName()[l]);
                    }
                }
                //Bubble sort based on first name
                if ((tempLowerFirst[j].compare(tempLowerFirst[j + 1]) ) > 0) {
                    Grades* temp = StudentList::studArray[j];
                    studArray[j] = studArray[j + 1];
                    studArray[j + 1] = temp;
                    // Switch the positions of the names in the array
                    string temp2 = tempLower[j];
                    tempLower[j] = tempLower[j+1];
                    tempLower[j+1] = temp2;
                }
            }
        }
    }
}
