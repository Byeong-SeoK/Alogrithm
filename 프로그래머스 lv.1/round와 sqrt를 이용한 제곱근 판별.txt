#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    float num = sqrt(n);
    float temp = floor(num);

    if(num - temp != 0){
        answer = -1;
    }
    else{
        answer = pow(num + 1, 2);
    }

    return answer;
}
