#include <iostream>
using namespace std;

struct Stack {
    int* arr;   // 동적 배열을 위한 포인터
    int top;    // 스택의 top을 나타내는 인덱스
    int capacity; // 스택의 최대 용량

    Stack(int size) {   // 생성자: 초기화 및 동적 메모리 할당
        capacity = size;
        arr = new int[capacity]; // capacity 크기의 int 배열 동적 할당
        top = -1; // 스택 초기화: top을 -1로 설정하여 빈 상태를 나타냄
    }

    ~Stack() {// 소멸자: 동적 메모리 해제
        delete[] arr; // 동적 할당된 메모리 해제
    }

    bool isEmpty() {// 스택이 비어있는지 확인
        return (top == -1);
    }

    bool isFull() {// 스택이 꽉 찼는지 확인
        return (top == capacity - 1);
    }

    void push(int value) {// 스택에 데이터 추가 (push)
        if (isFull()) {
            cout << "스택이 꽉 찼습니다." << endl;
            return;
        }
        arr[++top] = value; // top을 증가시키고 값을 스택에 추가
        cout << value << "을(를) 스택에 추가했습니다." << endl;
    }

    void pop() {// 스택에서 데이터 제거 (pop)
        if (isEmpty()) {
            cout << "스택이 비어있습니다." << endl;
            return;
        }
        int value = arr[top--]; // top을 감소시키고 값을 가져옴
        cout << value << "을(를) 스택에서 제거했습니다." << endl;
    }

    void peek() {// 현재 스택의 top 원소 반환 (peek)
        if (isEmpty()) {
            cout << "스택이 비어있습니다." << endl;
            return;
        }
        cout << "현재 스택의 top: " << arr[top] << endl;
    }
};
int main() {
    Stack stack(5); // 최대 크기가 5인 스택 생성

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