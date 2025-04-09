#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    
    string questions[10] = {
        "Who was the founder of Pakistan?",
        "What is 127 * 3?",
        "Which language is known for its speed and performance?",
        "Which planet is known as the Red Planet?",
        "What color is a ripe banana?",
        "Which number is divisible by 4?",
        "Who is known as the Father of Computers?",
        "What is the freezing point of water in Celsius?",
        "Which number is a square number?",
        "How many hours are there in two days?"
    };

   
    string options[10][4] = {
        {"Allama Iqbal", "Liaquat Ali Khan", "Quaid-e-Azam", "Sir Syed Ahmed Khan"},
        {"371", "381", "391", "401"},
        {"Python", "C++", "JavaScript", "HTML"},
        {"Venus", "Mars", "Saturn", "Neptune"},
        {"Yellow", "Blue", "Green", "Purple"},
        {"7", "9", "12", "15"},
        {"Charles Babbage", "Isaac Newton", "Alan Turing", "Nikola Tesla"},
        {"0", "10", "100", "32"},
        {"3", "16", "20", "18"},
        {"12", "36", "48", "24"}
    };

   
    int correct[10] = { 2, 0, 1, 1, 0, 2, 0, 0, 1, 2 };

 
    int selected[5];
    int count = 0;

    while (count < 5) {
        int randIndex = rand() % 10;
        bool alreadySelected = false;

        for (int i = 0; i < count; i++) {
            if (selected[i] == randIndex) {
                alreadySelected = true;
                break;
            }
        }

        if (!alreadySelected) {
            selected[count] = randIndex;
            count++;
        }
    }

    int score = 0;

    cout << "=== Welcome to the Online Exam Portal ===\n";

    for (int i = 0; i < 5; i++) {
        int qIndex = selected[i];
        cout << "\nQuestion " << i + 1 << ": " << questions[qIndex] << endl;
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << options[qIndex][j] << endl;
        }

        int userAnswer;
        cout << "Your answer (1-4): ";
        cin >> userAnswer;

        while (userAnswer < 1 || userAnswer > 4) {
            cout << "Invalid input. Enter a number between 1 and 4: ";
            cin >> userAnswer;
        }

        if (userAnswer - 1 == correct[qIndex]) {
            cout << "Correct!\n";
            score++;
        }
        else {
            cout << "Wrong! Correct answer: " << options[qIndex][correct[qIndex]] << "\n";
        }
    }
    cout << "\n=== Exam Finished ===\n";
    cout << "Your score: " << score << " out of 5\n";
    cout << "Percentage: " << (score * 100) / 5 << "%\n";

    return 0;
}
