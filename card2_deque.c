/*
회전 큐 문제
N장의 카드가 있다. 각가의 카드는 차례로 1부터 N까지의 번호가 붙어 
있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 
순서대로 카드가 놓여 있다. 

이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 
우선, 제일 위에 있는 바닥에 버린다. 그 다음, 제일 위에 있는 
카드를 제일 아래에 있는 카드 밑으로 옮긴다.
*/

// 첫째 줄에 정수 N(1 <= N <= 500,000)이 주어진다.
// 첫째 줄에 남게 되는 카드의 번호를 출력한다.

/* 
입력
6

출력
4
*/
#include <stdio.h>

#define MAX_N 500000

int main() {
    int N;
    int queue[MAX_N];
    int front = 0, rear = -1;

    // 입력 받기
    scanf("%d", &N);

    // 큐 초기화
    for (int i = 1; i <= N; i++) {
        queue[++rear] = i;
    }

    // 카드 버리기와 이동 반복
    while (front < rear) {
        // 제일 위에 있는 카드 버리기
        front++;

        // 제일 위에 있는 카드를 제일 아래로 이동
        rear++;
        queue[rear] = queue[front];
        front++;
    }

    // 남은 카드 출력
    printf("%d\n", queue[front]);

    return 0;
}
