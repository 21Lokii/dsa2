#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
int rollNo;
string name;
string division;
string address;

void getData() {
cout << "Enter Roll Number: ";
cin >> rollNo;
cout << "Enter Name: ";
cin.ignore();
getline(cin, name);
cout << "Enter Division: ";
getline(cin, division);
cout << "Enter Address: ";
getline(cin, address);
}

void displayData() {
cout << "Roll Number: " << rollNo << endl;
cout << "Name: " << name << endl;
cout << "Division: " << division << endl;
cout << "Address: " << address << endl;
}
};

void addStudent() {
ofstream outFile("students.dat", ios::binary | ios::app);
Student student;
student.getData();
outFile.write(reinterpret_cast<char*>(&student), sizeof(student));
outFile.close();
cout << "Student record added successfully." << endl;
}

void displayStudent(int rollNo) {
ifstream inFile("students.dat", ios::binary);
Student student;
bool found = false;
while (inFile.read(reinterpret_cast<char*>(&student), sizeof(student))) {
if (student.rollNo == rollNo) {
student.displayData();
found = true;
break;
}
}
inFile.close();
if (!found) {
cout << "Student record not found." << endl;
}
}

void deleteStudent(int rollNo) {
ifstream inFile("students.dat", ios::binary);
ofstream outFile("temp.dat", ios::binary);
Student student;
bool found = false;
while (inFile.read(reinterpret_cast<char*>(&student), sizeof(student))) {
if (student.rollNo == rollNo) {
found = true;
} else {
outFile.write(reinterpret_cast<char*>(&student), sizeof(student));
}
}
inFile.close();
outFile.close();
remove("students.dat");
rename("temp.dat", "students.dat");
if (found) {
cout << "Student record deleted successfully." << endl;
} else {
cout << "Student record not found." << endl;
}
}

int main() {
int choice, rollNo;
while (true) {
cout << "\n1. Add Student\n2. Display Student\n3. Delete Student\n4. Exit\nEnter your choice: ";
cin >> choice;
switch (choice) {
case 1:
addStudent();
break;
case 2:
cout << "Enter Roll Number to display: ";
cin >> rollNo;
displayStudent(rollNo);
break;
case 3:
cout << "Enter Roll Number to delete: ";
cin >> rollNo;
deleteStudent(rollNo);
break;
case 4:
exit(0);
default:
cout << "Invalid choice. Please try again." << endl;
}
}
return 0;
}
