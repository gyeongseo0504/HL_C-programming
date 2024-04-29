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
        subject = "����";
        break;
    case 1:
        subject = "����";
        break;
    case 2:
        subject = "����";
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
    cout << subjects(subjectIndex) << " ������ ���� ����: " << minScore << " (�й�: " << minStudentID << ")" << endl;
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

    cout << "�й� | ���� | ���� | ���� | ���" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        cout << "�л� " << i + 1 << "�� �й��� �Է��ϼ���: ";
        int studentID;
        cin >> studentID;
        scores[i][0] = studentID;

        for (int j = 0; j < NUM_SUBJECTS; ++j)
        {
            cout << subjects(j) << " ���� ������ �Է��ϼ���: ";
            cin >> scores[i][j + 1];
        }
    }

    cout << "\n�й�\t | ����\t | ����\t | ����\t | ���:" << endl;
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

    cout << "\n\n����� ���� ������� �л� ���� ���:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        double avg = static_cast<double>((scores[i][1] + scores[i][2] + scores[i][3])) / 3;
        cout << "\n�й�:\t " << scores[i][0] << ", ���:\t " << avg << endl;
    }

    return 0;
}