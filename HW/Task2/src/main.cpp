#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

struct Birthday {
    string name;
    tm date;
};

vector<Birthday> birthdays;

void inputBirthdays() {
    while (true) {
        string name;
        cout << "Enter friend's name (or 'end' to finish input): ";
        getline(cin, name);

        if (name == "end") {
            break;
        }

        Birthday birthday;
        birthday.name = name;

        cout << "Input date of birth (Year/month/day): ";
        string dateInput;
        getline(cin, dateInput);

        int year, month, day;
        size_t firstSlash = dateInput.find('/');
        size_t secondSlash = dateInput.find('/', firstSlash + 1);

        year = stoi(dateInput.substr(0, firstSlash));
        month = stoi(dateInput.substr(firstSlash + 1, secondSlash - firstSlash - 1));
        day = stoi(dateInput.substr(secondSlash + 1));

        birthday.date.tm_year = year - 1900;
        birthday.date.tm_mon = month - 1;
        birthday.date.tm_mday = day;
        birthday.date.tm_hour = 0;
        birthday.date.tm_min = 0;
        birthday.date.tm_sec = 0;
        birthday.date.tm_isdst = -1;

        birthdays.push_back(birthday);
    }
}

void findNextBirthday() {
    time_t now = time(nullptr);
    tm* currentTime = localtime(&now);

    time_t closestBirthdayTime = 0;
    string closestName;
    bool foundBirthdayToday = false;

    for (Birthday& birthday : birthdays) {
        tm birthdayThisYear = birthday.date;
        birthdayThisYear.tm_year = currentTime->tm_year;

        if (birthdayThisYear.tm_mon < currentTime->tm_mon || 
            (birthdayThisYear.tm_mon == currentTime->tm_mon && birthdayThisYear.tm_mday < currentTime->tm_mday)) {
            birthdayThisYear.tm_year += 1;
        }

        if (birthdayThisYear.tm_year == currentTime->tm_year && 
            birthdayThisYear.tm_mon == currentTime->tm_mon && 
            birthdayThisYear.tm_mday == currentTime->tm_mday) {
            cout << "Today has birthday: " << birthday.name << "!" << endl;
            foundBirthdayToday = true;
        }

        time_t birthdayTime = mktime(&birthdayThisYear);
        if (closestBirthdayTime == 0 || difftime(birthdayTime, closestBirthdayTime) < 0) {
            closestBirthdayTime = birthdayTime;
            closestName = birthday.name;
        }
    }

    if (closestBirthdayTime != 0) {
        tm* closestBirthday = localtime(&closestBirthdayTime);
        cout << "Closest birthday has: " << closestName << " (" 
             << (closestBirthday->tm_mon + 1) << "/" << closestBirthday->tm_mday << ")" << endl;
    }
}

int main() {
    inputBirthdays();
    findNextBirthday();
    return 0;
}