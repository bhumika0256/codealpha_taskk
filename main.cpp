#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the current to-do list
void display_list(const vector<pair<string, bool>>& todo_list) {
    if (todo_list.empty()) {
        cout << "Your to-do list is empty!" << endl;
    } else {
        cout << "\nCurrent To-Do List:\n";
        for (size_t i = 0; i < todo_list.size(); ++i) {
            cout << i + 1 << ". " << todo_list[i].first;
            if (todo_list[i].second)
                cout << " [Completed]";
            cout << endl;
        }
    }
}

// Function to add a new task to the to-do list
void add_task(vector<pair<string, bool>>& todo_list) {
    string task;
    cout << "Enter the task: ";
    getline(cin, task);
    todo_list.push_back(make_pair(task, false));
    cout << "Task added successfully!" << endl;
}

// Function to mark a task as completed
void mark_completed(vector<pair<string, bool>>& todo_list) {
    display_list(todo_list);
    if (!todo_list.empty()) {
        int task_num;
        cout << "Enter the task number to mark as completed: ";
        cin >> task_num;
        cin.ignore(); // to ignore the newline character after entering a number
        if (task_num > 0 && task_num <= todo_list.size()) {
            todo_list[task_num - 1].second = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

int main() {
    vector<pair<string, bool>> todo_list;
    int choice;

    while (true) {
        cout << "\nTo-Do List Application\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character after entering a number

        switch (choice) {
            case 1:
                add_task(todo_list);
                break;
            case 2:
                mark_completed(todo_list);
                break;
            case 3:
                display_list(todo_list);
                break;
            case 4:
                cout << "Exiting the application." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}