#include <iostream>
#include <ctime>
#define FORMAT_TIME(minutes, seconds) ((minutes < 10 ? "0" : "") + to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + to_string(seconds))
using namespace std;

int main() {
    int minutes, seconds;

    cout << "Enter the number of minutes: ";
    cin >> minutes;
    cout << "Enter the number of seconds: ";
    cin >> seconds;

    int totalTimeInSeconds = minutes * 60 + seconds;
    time_t startTime = time(nullptr);
    time_t endTime = startTime + totalTimeInSeconds;

    while (totalTimeInSeconds > 0) {
        time_t currentTime = time(nullptr);
        totalTimeInSeconds = endTime - currentTime;
        int remainingMinutes = totalTimeInSeconds / 60;
        int remainingSeconds = totalTimeInSeconds % 60;

        cout << "\rRemaining time: " << FORMAT_TIME(remainingMinutes, remainingSeconds) << flush;

        time_t waitUntil = time(nullptr) + 1;
        while (time(nullptr) < waitUntil) {
            // Delay for 1 second
        }
    }

    cout << "\nDING! DING! DING!" << endl;
    return 0;
}