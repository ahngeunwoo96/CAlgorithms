// SCPC 2020 카드 게임

#include <iostream>
#include <math.h>

using namespace std;

int card_a[3000], card_b[3000];

int case_1(int num, int lim) {
    int case_1_ans = 4;

    for (int i = 3; i <= 2 * num; i++) {
        int sum = 0;
        
        for(int j = 0; j <= i; j++) {
            int a_cnt = j, b_cnt = i - j;
            if(a_cnt > num || b_cnt > num) continue;

            if(a_cnt > 1){

            for(int k = 1; k < a_cnt; k++) {
                sum += card_a[k];
            }

            for(int k = 0; k < b_cnt; k++) {
                sum += card_b[k];
            
            }

            if(sum <= lim) case_1_ans++;
            sum = 0;
            }

            if(b_cnt > 1){
                for(int k = 0; k < a_cnt; k++) {
                    sum += card_a[k];
                }

               for(int k = 1; k < b_cnt ; k++) {
                    sum += card_b[k];
                }

                if(sum <= lim) case_1_ans++;
                sum = 0;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        int a_cnt, b_cnt, suc = 1; 
        a_cnt = i, b_cnt = 2-i;

        for(int k = num - 1; k >= a_cnt; k--) {
            if(card_a[k] == lim){
            }
            else {
                suc = 0;
                break;
            }
        }

        for(int k = num - 1; k >= b_cnt; k--) {
            if(card_b[k] == lim) {
            }
            else 
            {
                suc = 0;
                break;
            }
        }

        if(suc == 1) case_1_ans++;
        
    }
    
    
    return case_1_ans;

}

int case_2(int num, int lim) {
    // a에 한 개만 남거나, b에 한 개만 남는경우는 모든 경우에 포함되므로 2가지 경우는 base 
    int case_2_ans = 2;

    // [ (1, 2) (1, 1, 1) ], [ (1, 2) (1, 2) ]
    for(int i = 0; i <= num; i++) 
        for(int j = 0; j <= num; j++) {
            int suc_i = 0, suc_j = 0;

            int sum = 0;
            
            for(int k = 1; k <= i; k++) {
                sum += card_a[k - 1];
                if(sum > 3 * lim)
                break;
            }

            for(int k = 1; k <= j; k++) {
                sum += card_b[k - 1];
                if(sum > 3 * lim)
                break;
            }

            if(sum > lim && sum <= lim * 3 && i + j > 2) {
                int del_x, del_y;
                int suc_2 = 1;

                for(del_x = 0; del_x <= i; del_x++) {
                    for(del_y = 0; del_y <= j; del_y++) {
                        int rest_sum = sum;
                        int del_sum = 0;
                        int suc = 1;

                        for(int k = i - 1; k >= del_x; k--) {
                            del_sum += card_a[k];
                            if(del_sum > lim){
                                suc = 0;
                                break;
                            }
                        }

                        for(int k = j - 1; k >= del_y; k--){
                            del_sum += card_b[k];
                            if(del_sum > lim){
                                suc = 0;
                                break;
                            }
                        }
                        
                        rest_sum = sum - del_sum;
                        if(del_sum > 0 &&suc == 1 && rest_sum <= lim * 2 && min(del_x, i) + min(del_y, j) >= 2) {
                        }
                        else if(del_sum > 0 && del_sum <= lim){
                            suc_2 = 0;
                            continue;
                        }
                    }
                }
                

                if(suc_2 == 1){
                    if(suc_i != i && suc_j != j){
                        case_2_ans++;
                        suc_i = i;
                        suc_j = j;
                    }
                }
                
            }
        }
        

        



    return case_2_ans;

}

int main() {
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int Answer = 0;
        int num, lim; // num : 한 더미의 카드 수, lim : 한 번에 가져갈 수 있는 카드들의 숫자의 합 제한 
        int a_cnt = 0, b_cnt = 0;
        cin >> num >> lim;

        for(int i = 0; i < num; i++) {
            cin >> card_a[i];
        }

        for(int i = 0; i <num; i++) {
            cin >> card_b[i];
        }

        Answer = case_1(num, lim);

        cout << "Case #" << tc <<"\n" << Answer;

        Answer = case_2(num, lim);

        cout << " " << Answer<< endl;

    }
    return 0;
}

// #include <iostream>

// using namespace std;

// int card_a[3000], card_b[3000], case_1_ans = 0, case_2_ans = 0, suc[3000][3000], num, lim, tot_sum = 0, a_cnt, b_cnt;

// int find_best_way(int sum) {
    
//     if(sum > lim){
//         return sum;
//     }
//     else {
//         a_cnt += 1;
//         find_best_way(card_a[a_cnt - 1]);
//         a_cnt -= 1;
//         b_cnt += 1;
//         find_best_way(card_b[b_cnt - 1]);
//         b_cnt -= 1;
//     }
    

// }

// void card_game( int sum) {
    
//     if(a_cnt == 0 && b_cnt == 0) {
//         suc[a_cnt][b_cnt] = 1;
//         case_1_ans++;
//     }

//     sum += find_best_way(0);
    
// }

// int main() {

//     int T;
//     cin >> T;

//     for(int tc = 1; tc <= T; tc++) {
//         cin >> num >> lim;

//         for(int i = 0; i < num; i++) {
//             cin >> card_a[i];
//             tot_sum += card_a[i];
//         }

//         for(int i = 0; i < num; i++) {
//             cin >> card_b[i];
//             tot_sum += card_b[i];
//         }   
//     }
    
//     a_cnt = 0, b_cnt = 0;
//     card_game(a_cnt, b_cnt, 0);
//     return 0;
// }

// #include <iostream>

// using namespace std;

// int card_a[3000], card_b[3000], num, lim, a_cnt, b_cnt;

// int find_best_way(int sum) {

//     if(sum + card_a[a_cnt - 1] > lim && sum + card_b[b_cnt - 1] > lim) {
//         return sum;
//     }
//     else if(sum + card_a[a_cnt - 1] > lim) {
//         a_cnt--;
//         find_best_way(sum + card_a[a_cnt ]);
//         a_cnt++;
//     }
//     else if(sum + card_b[b_cnt - 1] > lim) {
//         b_cnt--;
//         find_best_way(sum + card_b[b_cnt]);
//         b_cnt++;
//     }
//     else {
//         a_cnt--;
//         find_best_way(sum + card_a[a_cnt ]);
//         a_cnt++;
//         b_cnt--;
//         find_best_way(sum + card_b[b_cnt]);
//         b_cnt++;
//     }
// }

// void card_game(int sum) {

//     if(a_cnt == 0 && b_cnt == 0)
//         return;

//     sum += find_best_way(0);

//     card_game(sum);
// }

// int main (){
//     int T;
//     cin >> T;

//     for(int tc = 1; tc <= T; tc++) {
//         cin >> num >> lim;

//         for(int i = 0; i < num; i++) {
//             cin >> card_a[i];
//         }

//         for(int i = 0; i < num; i++) {
//             cin >> card_b[i];
//         }

//         a_cnt = num, b_cnt = num;

//         card_game(a_cnt, b_cnt, 0);



//     }
//     return 0;
// }