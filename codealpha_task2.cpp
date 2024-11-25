#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct User {
    string name;
    int score;
};

struct Question {
    string question;
    vector<string> options;
    char correctOption;
};

void registerUser(User &user) {
    cout << "Enter your name: ";
    cin >> user.name;
    user.score = 0;
}

void askQuestions(User &user, vector<Question> &questions) {
    for (Question &q : questions) {
        cout << q.question << endl;
        for (int i = 0; i < q.options.size(); ++i) {
            cout << char('A' + i) << ": " << q.options[i] << endl;
        }

        char userOption;
        cout << "Your answer: ";
        cin >> userOption;

        if (toupper(userOption) == toupper(q.correctOption)) {
            cout << "Correct!" << endl;
            user.score++;
        } else {
            cout << "Wrong! The correct answer was " << q.correctOption << endl;
        }
        cout << endl;
    }
}

void displayScore(User &user) {
    cout << user.name << ", your final score is: " << user.score << endl;
}

int main() {
    User user;
    vector<Question> questions = {
        {"What is the capital of France?", {"Paris", "Berlin", "London", "Rome"}, 'A'},
        {"What is 2 + 2?", {"3", "4", "5", "6"}, 'B'},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 'B'}
    };

    registerUser(user);
    askQuestions(user, questions);
    displayScore(user);

    return 0;
}