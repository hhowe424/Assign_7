//11-22-2021
/* This program asks for the input of students' answers of A, B, C, or D
for a 20 question assignment, compares them to the answer key,
and outputs the questions the student got wrong. It also outputs
whether the student passed or failed the exam, and the accumulated
number of correct and incorrect answers. */

#include <iostream>

using namespace std;

void input(char [], int);
void checkAnswers(char [], const char [], int &, int &, int);

int main() {
    const int SIZE = 20;
    char answer[SIZE];
    int correctAnswers = 0;
    int incorrectAnswers = 0;
    const char CORRECTANSWER[] = {'A','D','B','B','C','B','A','B','C','D',
                                     'A','C','D','B','D','C','C','A','D','B'};
    input(answer, SIZE);
    checkAnswers(answer, CORRECTANSWER, correctAnswers,
                 incorrectAnswers, SIZE);

    if (correctAnswers >= 15)
        cout << "\nThe student passed the exam." << endl;
    else {
        cout << "\nThe student failed the exam." << endl;
    }

    cout << "Correct Answers: " << correctAnswers << endl;
    cout << "Incorrect Answers: " << incorrectAnswers << endl;
}

//This function creates an array for the student's answers
void input(char answer [], int SIZE) {
    int i = 0;
    int questionNum = 1;

    cout << "Please enter the student's answers for each "
            "of the questions.\n"
            "Press Enter after typing each answer.\n"
            "Please enter only an A, B, C, D or a, b, "
            "c, d for each question.\n";

    while (i < 20) {
        cout << "Question " << questionNum << " = ";
        cin >> answer[i];
        answer[i] = toupper(answer[i]); //makes all letter input uppercase

        if (answer[i] == 'A' || answer[i] == 'B' || answer[i] == 'C'
            || answer[i] == 'D')
        {
            i++;
            questionNum++;
        }
        else {
            cout << "Use only an A, B, C, D or a, b, c, d!\n"
                    "Please try again.\n";
        }
    }
}

//This function checks the student's answers and determines which are correct
void checkAnswers(char answer [], const char CORRECTANSWER[],
                  int & totalCorrect, int & totalIncorrect, int SIZE)
{
    cout << "\nQuestions that were answered incorrectly: " << endl;

    for(int i = 0; i < SIZE; i++) {
        if (answer[i] == CORRECTANSWER[i]) {
            totalCorrect += 1;
        }
        else {
            cout << i + 1 << endl;
            totalIncorrect += 1;
        }
    }
}
/*
Please enter the student's answers for each of the questions.
Press Enter after typing each answer.
Please enter only an A, B, C, D or a, b, c, d for each question.
Question 1 = a
Question 2 = B
Question 3 = b
Question 4 = f
Use only an A, B, C, D or a, b, c, d!
Please try again.
Question 4 = B
Question 5 = c
Question 6 = b
Question 7 = a
Question 8 = b
Question 9 = g
Use only an A, B, C, D or a, b, c, d!
Please try again.
Question 9 = A
Question 10 = d
Question 11 = a
Question 12 = C
Question 13 = D
Question 14 = A
Question 15 = d
Question 16 = C
Question 17 = c
Question 18 = B
Question 19 = D
Question 20 = b

Questions that were answered incorrectly:
2
9
14
18

The student passed the exam
Correct Answers: 16
Incorrect Answers: 4

Process finished with exit code 0
 */
