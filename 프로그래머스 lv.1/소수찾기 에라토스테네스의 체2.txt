int solution(int n) {
    int answer = 0;
    int* temp = new int[n+1];

    for(int i = 0; i <= n; i++){
        temp[i] = i;
    }

    for(int j = 0; j < n+1; j++){
        if(temp[j] == 0 || temp[j] == 1){
            continue;
        }
        else{
            for(int k = 2*j; k < n+1; k = k + j){
                temp[k] = 0;
            }
        }
    }

    for(int l = 0; l < n+1; l++){
        if(temp[l] != 0){
            answer++;
        }
        else{
            continue;
        }
    }
    answer = answer - 1;

    return answer;
}
