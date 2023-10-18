/*
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그 램을 작성하시오. 명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 10,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
출력 해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
• 입력예제1          • 출력예제1
15 
push 1              1
push 2              2
front               2
back                0
size                1
empty               2
pop                 -1
pop                 0
pop                 1
size                -1
empty               0
pop                 3
push 3 
empty 
front

기존 큐를 원형 큐로 변경해보기 
c언어로 코딩하는 것을 원형 큐를 사용하여 해결 해줘?
*/

#include <stdio.h>

#define MAX_SIZE 10001

// 원형 큐 구조체 정의
struct CircularQueue {
    int data[MAX_SIZE];
    int front, rear;
};

// 큐 초기화 함수
void initQueue(struct CircularQueue *queue) {
    queue->front = 0;
    queue->rear = 0;
}

// 큐에 데이터 추가 함수 (push)
void push(struct CircularQueue *queue, int x) {
    if ((queue->rear + 1) % MAX_SIZE == queue->front) {
        // 큐가 꽉 찼을 경우
        printf("-1\n");
    } else {
        queue->data[queue->rear] = x;
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
}

// 큐에서 데이터 제거 함수 (pop)
void pop(struct CircularQueue *queue) {
    if (queue->front == queue->rear) {
        // 큐가 비어있을 경우
        printf("-1\n");
    } else {
        printf("%d\n", queue->data[queue->front]);
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

// 큐에 들어있는 데이터 개수 반환 함수 (size)
void size(struct CircularQueue *queue) {
    int count = (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE;
    printf("%d\n", count);
}

// 큐가 비어있는지 여부 반환 함수 (empty)
void empty(struct CircularQueue *queue) {
    if (queue->front == queue->rear) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}

// 큐의 가장 앞에 있는 데이터 반환 함수 (front)
void front(struct CircularQueue *queue) {
    if (queue->front == queue->rear) {
        printf("-1\n");
    } else {
        printf("%d\n", queue->data[queue->front]);
    }
}

// 큐의 가장 뒤에 있는 데이터 반환 함수 (back)
void back(struct CircularQueue *queue) {
    if (queue->front == queue->rear) {
        printf("-1\n");
    } else {
        int index = (queue->rear - 1 + MAX_SIZE) % MAX_SIZE;
        printf("%d\n", queue->data[index]);
    }
}

int main() {
    struct CircularQueue queue;
    initQueue(&queue);

    int N;
    char command[10];
    int x;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", command);

        if (command[0] == 'p' && command[1] == 'u') {
            // push 일 경우
            scanf("%d", &x);
            push(&queue, x);
        } else if (command[0] == 'p' && command[1] == 'o') {
            // pop 일 경우
            pop(&queue);
        } else if (command[0] == 's') {
            // size 일 경우
            size(&queue);
        } else if (command[0] == 'e') {
            // empty 일 경우
            empty(&queue);
        } else if (command[0] == 'f') {
            // front 일 경우
            front(&queue);
        } else if (command[0] == 'b') {
            // back 일 경우
            back(&queue);
        }
    }

    return 0;
}
