#include<iostream>
using namespace std;
int arr[4]={0,1,2,3};
bool visited[4]={false};
int result[4];
void combination(int idx){
    if (idx >= 4){
        for (int i = 0; i < 4; i++){
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!visited[i]){
            result[idx] = arr[i];
            visited[i] = true;
            combination(idx + 1);
            visited[i] = false;
        }
    }
}
int main(void){
	combination(0);
	return 0;
}
