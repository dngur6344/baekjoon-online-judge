#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int *relation;
queue<int> q;
void recur(int *visit, int N, int idx);
int rotate(int *a, int *visit,int N);
int main(void)
{
    int N, M, k;
    int *a;
    int *visit;
    int i, j;
    int num1, num2;
    int res, flag = 0;
    scanf("%d %d %d", &N, &M, &k);
    relation = (int*)malloc(sizeof(int)*N);
    a = (int*)malloc(sizeof(int)*N);
    visit = (int*)malloc(sizeof(int)*N);
    for (i = 0; i < N; i++) {
        visit[i] = 0;
    }
    for (i = 0; i < N; i++)
        relation[i] = 0;
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    int cnt = 1;
    for (i = 0; i < M; i++) {
        scanf("%d %d", &num1, &num2);
        if (relation[num1-1] != 0) {
            if(relation[num2-1]==0)
                relation[num2-1] = relation[num1-1];
            else {
                int tmp = relation[num2 - 1];
                relation[num2 - 1] = relation[num1 - 1];
                for (j = 0; j < N; j++) {
                    if (relation[j] == tmp)
                        relation[j] = relation[num1 - 1];
                }
            }
        }
        else if (relation[num2-1] != 0) {
            relation[num1-1] = relation[num2-1];
        }
        else
        {
            relation[num1-1] = cnt;
            relation[num2-1] = cnt;
            cnt++;
        }
    }
    for(i=0;i<N;i++){
        if(relation[i]==0){
            relation[i]=cnt;
            cnt++;
        }
    }
    res = rotate(a, visit, N);
    for (i = 0; i < N; i++) {
        if (visit[i] == 0) {
            flag = 1;
            break;
        }
    }
    free(a);
    free(visit);
    if (res > k || flag == 1)
        printf("Oh no\n");
    else
        printf("%d\n", res);
    return 0;
}
int rotate(int *a, int *visit, int N) {
    int i, j;
    int res = 0;
    int min;
    for (i = 0; i < N; i++) {
        if (visit[i] == 0) {
            visit[i] = 1;
            min = a[i];
            q.push(i);
            recur(visit, N, i);
            while (!q.empty()) {
                if (a[q.front()] < min)
                    min = a[q.front()];
                q.pop();
            }
            res += min;
        }
    }
    return res;
}
void recur(int *visit, int N, int idx){
    int i, j;
    for (i = idx+1; i < N; i++) {
        if (relation[i] == relation[idx]) {
            visit[i] = 1;
            q.push(i);
        }
    }
}

