
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    // Program to allow students to register for courses

    // Preload course information into a map
    map<string, string> courses = {
        {"PROG1783", "Programming Fundamentals"},
        {"INFO8025", "Information Systems"},
        {"PROG2267", "Advanced Programming"},
        {"MATH1000", "Calculus I"}
    };

    // Get student information
    string first_name;
    cout << "Enter your first name: ";
    getline(cin, first_name);

    string last_name;
    cout << "Enter your last name: ";
    getline(cin, last_name);

    string student_number;
    cout << "Enter your student number: ";
    getline(cin, student_number);

    // Store student information in a map
    map<string, string> student_info = {
        {"First Name", first_name},
        {"Last Name", last_name},
        {"Student Number", student_number}
    };

    // Display available courses
    cout << "Available courses:" << endl;
    for (const auto& [code, name] : courses) {
        cout << code << ": " << name << endl;
    }

    // Get course selection from user
    string course_selection;
    cout << "Enter course codes separated by commas: ";
    getline(cin, course_selection);

    // Split course codes into a list
    stringstream ss(course_selection);
    string token;
    map<string, string> selected_courses;
    while (getline(ss, token, ',')) {
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        selected_courses[token] = courses[token];
    }

    // Display student information and selected courses
    cout << "Student Information:" << endl;
    cout << "Full Name: " << student_info["First Name"] << " " << student_info["Last Name"] << endl;
    cout << "Student Number: " << student_info["Student Number"] << endl;

    cout << "Selected Courses:" << endl;
    for (const auto& [code, name] : selected_courses) {
        cout << code << ": " << name << endl;
    }

    return 0;
}
