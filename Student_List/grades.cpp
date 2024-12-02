// Bria Weisblat Section: 2

#include <iostream>
#include <iomanip>
#include "grades.h"
#include <string>

//Grades constructor
Grades::Grades(string cfirstName, string clastName, char cmajor) {
    firstName = cfirstName;
    lastName = clastName;
    major = cmajor;
}

void Grades::printStudent(){
    //Ensure that first and last names are evenly spaced out
    std::cout << lastName;
    int lTempChars = 20 - lastName.size();
    for (int i =0; i < lTempChars; i++){
        std::cout << " ";
    }
    std::cout << '\t' << firstName;
    int fTempChars = 20 - firstName.size();
    for (int i =0; i < fTempChars; i++){
        std::cout << " ";
    }
    std::cout << '\t';
    major = toupper(major);
    //Print the student's major
    switch (major){
        case 'B':
            std::cout << "Biology";
            break;
        case 'C':
            std::cout << "Computer Science";
            break;
        case 'T':
            std::cout << "Theater";
            break;
    }
}

void Grades::printGradeReport(ostream& exportFile){
    exportFile << firstName << " " << lastName << "     ";
    //Ensure proper amount of spacing
    int temp = 41 - (firstName.size() + lastName.size());
    for (int i = 0; i < temp; i++){
        exportFile << " ";
    }
    exportFile << getFinal() << "    ";
    //Ensure grades have two digits after the decimal
    exportFile << fixed << setprecision(2) << gradeReport() << "   " << defaultfloat << setprecision(6);
}

char Grades::getMajor(){
    major = toupper(major);
    return major;
}

string Grades::getFirstName() {
    return firstName;
}

string Grades::getLastName() {
    return lastName;
}

//Take in biology grades
Biology::Biology(string cfirstName, string clastName, char cmajor, double clabGrade, double ctest1, double ctest2,
                 double ctest3, double cfinalExam) : Grades(cfirstName, clastName, cmajor) {
    labGrade = clabGrade;
    bTest1 = ctest1;
    bTest2 = ctest2;
    bTest3 = ctest3;
    bioFinal = cfinalExam;
}

//Take in theater grades
Theater::Theater(string cfirstName, string clastName, char cmajor, double cparticipation, double cmidterm,
                 double cfinalExam) : Grades(cfirstName, clastName, cmajor) {
    participation = cparticipation;
    midterm = cmidterm;
    theaterFinal = cfinalExam;
}

//Take in compsci grades
ComputerScience::ComputerScience(string cfirstName, string clastName, char cmajor, double cp1, double cp2,
                                 double cp3, double cp4, double cp5, double cp6, double cprogramAvg, double ctest1,
                                 double ctest2, double cfinalExam) : Grades(cfirstName, clastName, cmajor) {
    p1 = cp1;
    p2 = cp2;
    p3 = cp3;
    p4 = cp4;
    p5 = cp5;
    p6 = cp6;
    programAvg = cprogramAvg;
    test1 = ctest1;
    test2= ctest2;
    csFinal = cfinalExam;
}

//Calculate final biology grade
double Biology::gradeReport(){
    double bioFinalGrade;
    bioFinalGrade = (labGrade * 0.3) + (bTest1 * .15) + (bTest2 * .15) + (bTest3 * .15) + (bioFinal * .25);
    return bioFinalGrade;
}

//Calculate final computer science grade
double ComputerScience::gradeReport(){
    programAvg = ( (p1 + p2 + p3 + p4 + p5 + p6) / 6 );
    double compSciFinalGrade = (programAvg * 0.30) + (test1 * 0.20) + (test2 * 0.20) + (csFinal * 0.30);
    return compSciFinalGrade;
}

//Calculate final theater grade
double Theater::gradeReport(){
    double theaterFinalGrade = (participation * 0.40) + (midterm * 0.25) + (theaterFinal * 0.35);
    return theaterFinalGrade;
}

double Biology::getFinal(){
    return bioFinal;
}

double ComputerScience::getFinal(){
    return csFinal;
}

double Theater::getFinal(){
    return theaterFinal;
}