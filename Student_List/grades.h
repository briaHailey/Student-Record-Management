// Bria Weisblat Section: 2

#include <string>
using namespace std;

class Grades {

public:
    Grades(string cfirstName, string clastName, char cmajor);
    void printStudent();
    void printGradeReport(ostream& exportFile);
    char getMajor();
    void printGradeDist();
    virtual double gradeReport() =0;
    virtual double getFinal() = 0;
    string getFirstName();
    string getLastName();

protected:
    string firstName;
    string lastName;
    char major;

private:

};

class Biology: public Grades{

public:
    Biology(string cfirstName, string clastName, char cmajor, double clabGrade, double ctest1, double ctest2,
            double ctest3, double cfinalExam);

    double gradeReport();
    double getFinal();
protected:

private:
    double labGrade;
    double bTest1;
    double bTest2;
    double bTest3;
    double bioFinal;
};

class Theater: public Grades{

public:
    Theater(string cfirstName, string clastName, char cmajor, double cparticipation, double cmidterm,
            double cfinalExam);

    double gradeReport();
    double getFinal();
protected:

private:
    double participation;
    double midterm;
    double theaterFinal;

};

class ComputerScience : public Grades{

public:
    ComputerScience(string cfirstName, string clastName, char cmajor, double cp1, double cp2,
                    double cp3, double cp4, double cp5, double cp6, double cprogramAvg, double ctest1,
                    double ctest2, double cfinalExam);

    double gradeReport();
    double getFinal();

protected:

private:
    double p1;
    double p2;
    double p3;
    double p4;
    double p5;
    double p6;
    double programAvg;
    double test1;
    double test2;
    double csFinal;
};
