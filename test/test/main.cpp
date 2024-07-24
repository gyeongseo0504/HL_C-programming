#include <iostream>
using namespace std;

struct Stack {
    int* arr;   // ���� �迭�� ���� ������
    int top;    // ������ top�� ��Ÿ���� �ε���
    int capacity; // ������ �ִ� �뷮

    Stack(int size) {   // ������: �ʱ�ȭ �� ���� �޸� �Ҵ�
        capacity = size;
        arr = new int[capacity]; // capacity ũ���� int �迭 ���� �Ҵ�
        top = -1; // ���� �ʱ�ȭ: top�� -1�� �����Ͽ� �� ���¸� ��Ÿ��
    }

    ~Stack() {// �Ҹ���: ���� �޸� ����
        delete[] arr; // ���� �Ҵ�� �޸� ����
    }

    bool isEmpty() {// ������ ����ִ��� Ȯ��
        return (top == -1);
    }

    bool isFull() {// ������ �� á���� Ȯ��
        return (top == capacity - 1);
    }

    void push(int value) {// ���ÿ� ������ �߰� (push)
        if (isFull()) {
            cout << "������ �� á���ϴ�." << endl;
            return;
        }
        arr[++top] = value; // top�� ������Ű�� ���� ���ÿ� �߰�
        cout << value << "��(��) ���ÿ� �߰��߽��ϴ�." << endl;
    }

    void pop() {// ���ÿ��� ������ ���� (pop)
        if (isEmpty()) {
            cout << "������ ����ֽ��ϴ�." << endl;
            return;
        }
        int value = arr[top--]; // top�� ���ҽ�Ű�� ���� ������
        cout << value << "��(��) ���ÿ��� �����߽��ϴ�." << endl;
    }

    void peek() {// ���� ������ top ���� ��ȯ (peek)
        if (isEmpty()) {
            cout << "������ ����ֽ��ϴ�." << endl;
            return;
        }
        cout << "���� ������ top: " << arr[top] << endl;
    }
};
int main() {
    Stack stack(5); // �ִ� ũ�Ⱑ 5�� ���� ����

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.pop();
    stack.peek();

    return 0;
}