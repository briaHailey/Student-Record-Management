// Bria Weisblat Section: 2

#include "grades.h"

class StudentList
{
public:
    //Constructor
    StudentList();
    //Destructor
    ~StudentList();

    bool ImportFile(string filename);
    bool CreateReportFile(string filename);
    void ShowList() const;	// print basic list data
    void printGradeDist(ostream& exportFile);
    void sortStudents();

private:
    //Dynamic array
    Grades ** studArray;
    int numStudents;

    //Grade distribtion variables
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int dCount = 0;
    int fCount = 0;
};