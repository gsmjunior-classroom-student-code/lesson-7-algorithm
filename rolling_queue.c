/*
회전하는 큐
큐에 처음에 포함되어 있던 수 N개가 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.)
이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다.
N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다.
둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.
*/
/*
10 3
1 2 3

0
*/

/*
입력 예제
10 3
2 9 5

출력 예제
8
*/
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int positions[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &positions[i]);
    }

    int queue[N];
    for (int i = 0; i < N; i++) {
        queue[i] = i + 1;
    }

    int total = 0;
    for (int i = 0; i < M; i++) {
        int index = 0;
        while (queue[index] != positions[i]) {
            index++;
        }
        int left = index;
        int right = N - index;

        if (left < right) {
            for (int j = 0; j < left; j++) {
                int front = queue[0];
                for (int k = 0; k < N - 1; k++) {
                    queue[k] = queue[k + 1];
                }
                queue[N - 1] = front;
                total++;
            }
        } else {
            for (int j = 0; j < right; j++) {
                int back = queue[N - 1];
                for (int k = N - 1; k > 0; k--) {
                    queue[k] = queue[k - 1];
                }
                queue[0] = back;
                total++;
            }
        }

        // 뽑아낸 원소를 큐에서 제거
        for (int j = 0; j < N; j++) {
            if (queue[j] == positions[i]) {
                for (int k = j; k < N - 1; k++) {
                    queue[k] = queue[k + 1];
                }
                N--;
                break;
            }
        }
    }

    printf("%d\n", total);

    return 0;
}
