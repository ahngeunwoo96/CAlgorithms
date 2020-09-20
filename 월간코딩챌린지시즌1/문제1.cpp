#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i = 0; i < numbers.size(); i++) 
        for(int j = i + 1; j < numbers.size(); j++) {
            int sum, re = 0;
            
            sum = numbers[i] + numbers[j];
            for(int k = 0; k < answer.size(); k++) {
                if(sum == answer[k])
                    re = 1;
            }
            if(re == 0)
                answer.push_back(sum);
        }

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector <int> numbers;

    numbers.push_back(5);
    numbers.push_back(0);
    numbers.push_back(2);
    numbers.push_back(7);
   // numbers.push_back(1);


    solution(numbers);

    return 0;
}