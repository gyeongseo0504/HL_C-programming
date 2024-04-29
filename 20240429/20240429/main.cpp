#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string subjects(int j)
{
    string subject;

    switch (j)
    {
    case 0:
        subject = "국어";
        break;
    case 1:
        subject = "영어";
        break;
    case 2:
        subject = "수학";
        break;
    default:
        subject = "X";
        break;
    }

    return subject;
}

void printSubjectMinScore(int scores[][4], int numStudents, int subjectIndex)
{
    int minScore = scores[0][subjectIndex + 1];
    int minStudentID = scores[0][0];

    for (int i = 1; i < numStudents; ++i)
    {
        if (scores[i][subjectIndex + 1] < minScore)
        {
            minScore = scores[i][subjectIndex + 1];
            minStudentID = scores[i][0];
        }
    }
    cout << "\n" << endl;
    cout << subjects(subjectIndex) << " 과목의 최저 점수: " << minScore << " (학번: " << minStudentID << ")" << endl;
}

void sortByAverage(int scores[][4], int numStudents)
{
    for (int i = 0; i < numStudents - 1; ++i)
    {
        for (int j = 0; j < numStudents - i - 1; ++j)
        {
            double avg1 = static_cast<double>((scores[j][1] + scores[j][2] + scores[j][3])) / 3;
            double avg2 = static_cast<double>((scores[j + 1][1] + scores[j + 1][2] + scores[j + 1][3])) / 3;
            if (avg1 > avg2)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int temp = scores[j][k];
                    scores[j][k] = scores[j + 1][k];
                    scores[j + 1][k] = temp;
                }
            }
        }
    }
}

int main()
{
    const int NUM_STUDENTS = 10;
    const int NUM_SUBJECTS = 3;

    int scores[NUM_STUDENTS][4];

    cout << "학번 | 국어 | 영어 | 수학 | 평균" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        cout << "학생 " << i + 1 << "의 학번을 입력하세요: ";
        int studentID;
        cin >> studentID;
        scores[i][0] = studentID;

        for (int j = 0; j < NUM_SUBJECTS; ++j)
        {
            cout << subjects(j) << " 과목 성적을 입력하세요: ";
            cin >> scores[i][j + 1];
        }
    }

    cout << "\n학번\t | 국어\t | 영어\t | 수학\t | 평균:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        int sum = 0;
        cout << scores[i][0] << " \t| ";
        for (int j = 1; j < NUM_SUBJECTS + 1; ++j)
        {
            cout << scores[i][j] << "\t ";
            sum += scores[i][j];
        }
        double avg = static_cast<double>(sum) / NUM_SUBJECTS;
        cout << "| " << avg << endl;
    }

    for (int j = 0; j < NUM_SUBJECTS; ++j)
    {
        printSubjectMinScore(scores, NUM_STUDENTS, j);
    }

    sortByAverage(scores, NUM_STUDENTS);

    cout << "\n\n평균이 낮은 순서대로 학생 정보 출력:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        double avg = static_cast<double>((scores[i][1] + scores[i][2] + scores[i][3])) / 3;
        cout << "\n학번:\t " << scores[i][0] << ", 평균:\t " << avg << endl;
    }

    return 0;
}