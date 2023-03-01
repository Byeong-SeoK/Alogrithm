#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    if(m == n){
        answer.push_back(n);
        answer.push_back(m);
    }
    else{
        if(n < m){
            if(m % n == 0){
                answer.push_back(n);
                answer.push_back(m);
            }
            else{
                int num = 0;
                for(int i = 1; i <= n; i++){
                    if(n % i == 0 && m % i == 0){
                        num = i;
                    }
                    else{
                        continue;
                    }
                }

                answer.push_back(num);
                answer.push_back(num * (m / num) * (n / num));
            }
        }
        else{
            if(n % m == 0){
                answer.push_back(m);
                answer.push_back(n);
            }
            else{
                int num = 0;
                for(int i = 1; i <= m; i++){
                    if(n % i == 0 && m % i == 0){
                        num = i;
                    }
                    else{
                        continue;
                    }
                }

                answer.push_back(num);
                answer.push_back(num * (m / num) * (n / num));                
            }
        }
    }

    return answer;
}
