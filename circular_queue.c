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
