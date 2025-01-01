#include <iostream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

struct Task {
    string name;
    time_t startTime;
    time_t endTime;
};

map<string, Task> completedTasks;
Task currentTask;
bool isTaskRunning = false;

void beginTask(string taskName) {
    if (isTaskRunning) {
        currentTask.endTime = time(nullptr);
        completedTasks[currentTask.name] = currentTask;
    }

    currentTask.name = taskName;
    currentTask.startTime = time(nullptr);
    currentTask.endTime = 0;
    isTaskRunning = true;

    cout << "Task started: " << taskName << endl;
}

void endTask() {
    if (isTaskRunning) {
        currentTask.endTime = time(nullptr);
        completedTasks[currentTask.name] = currentTask;
        isTaskRunning = false;
        cout << "Task completed: " << currentTask.name << endl;
    } else {
        cout << "No current task to complete." << endl;
    }
}

void showStatus() {
    cout << "Completed tasks:" << endl;
    map<string, Task>::iterator it;
    for (it = completedTasks.begin(); it != completedTasks.end(); ++it) {
        Task task = it->second;
        double duration = difftime(task.endTime, task.startTime) / 3600;
        cout << "Task: " << task.name << ", Time: " << duration << " hours" << endl;
    }

    if (isTaskRunning) {
        cout << "Current task: " << currentTask.name << endl;
    } else {
        cout << "No current task." << endl;
    }
}

int main() {
    string command;

    while (true) {
        cout << "Enter command (begin, end, status, exit): ";
        getline(cin, command);

        if (command == "begin") {
            cout << "Enter tasks name: ";
            string taskName;
            getline(cin, taskName);
            beginTask(taskName);
        } else if (command == "end") {
            endTask();
        } else if (command == "status") {
            showStatus();
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command." << endl;
        }
    }

    return 0;
}