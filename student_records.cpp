 
 #include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>

// Enum for grade levels
enum GradeLevel { FRESHMAN = 1, SOPHOMORE, JUNIOR, SENIOR };

// Using alias for simplicity
using StudentName = std::string;
using GPA = double;

namespace StudentUtils {
    // Converts a name to uppercase
    void formatName(std::string &name) {
        std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    }

    // Converts enum to readable string
    std::string gradeToString(GradeLevel grade) {
        switch (grade) {
            case FRESHMAN:  return "Freshman";
            case SOPHOMORE: return "Sophomore";
            case JUNIOR:    return "Junior";
            case SENIOR:    return "Senior";
            default:        return "Unknown";
        }
    }

    // Formats GPA to two decimal places
    std::string formatGPA(GPA gpa) {
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << gpa;
        return stream.str();
    }

    // Displays student info
    void displayStudentInfo(const StudentName &name, GradeLevel grade, GPA gpa) {
        std::cout << "\nStudent Record:\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Grade Level: " << gradeToString(grade) << "\n";
        std::cout << "GPA: " << formatGPA(gpa) << "\n";
    }
}

int main() {
    StudentName name;
    int gradeInput;
    GPA gpa;

    // Input student data
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    std::cout << "Enter grade level (1=Freshman, 2=Sophomore, 3=Junior, 4=Senior): ";
    std::cin >> gradeInput;

    std::cout << "Enter GPA: ";
    std::cin >> gpa;

    // Process data
    StudentUtils::formatName(name);

    // Output student record
    StudentUtils::displayStudentInfo(name, static_cast<GradeLevel>(gradeInput), gpa);

    return 0;
}
