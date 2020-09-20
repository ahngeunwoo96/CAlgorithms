// 2020 kakao coding test 자물쇠와 열쇠

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector<int> > rotate(vector <vector<int> >key ) {

    // key를 90도 만큼 회전하기 
    int keysize = key.size();

    for(int i = 0; i < keysize; i++) {
        for(int j = 0; j < keysize; j++) {
            
        }
    }

    return key;
}

bool matching(vector<vector<int> > map, int i, int j, vector<vector<int> >key, vector<vector<int> >lock) {
    // map에서 
    int keysize = key.size();
    int locksize = lock.size();

    for(int a = i; a < i + keysize; a++) [
        for(int b = j; b < j + keysize; b++) {
            map[a][b] = key[a-i][b-j];
        }
    ]

    for(int a = 0 ; a <= locksize; a++) {
        for(int b = 0; b <= locksize; b++) {
            if(map[ a+ keysize - 1][b + keysize -1] == 0 || map[a+keysize - 1][b + keysize - 1] == 2) 
                return false;
        }
    }
    return true;

}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    bool answer = false;

    int keysize = key.size();
    int locksize = lock.size();
    int mapsize = (keysize - 1) * 2 + locksize;

    vector<vector<int> >map(mapsize, vector<int>(mapsize, 0));

    for(int i = 0; i < locksize; i++) {
        for(int j = 0; j < locksize; j++) {
            map[i + keysize - 1][j + keysize - 1] = lock[i][j];
        }
    }

    for(int r = 0; r < 4; r++){
        for(int i = 0; i < keysize - 1 + locksize; i++) {
            for(int j = 0; j < keysize - 1 + locksize; j++) {
                if(matching(map, i , j, key, lock) == true)
                    return true;
            
            }
        }
        key = rotate(key);
    }

    return answer;
}

int main() {
    // 2차원 배열 vector 선언
    vector<vector<int> > key(3, vector<int>(3, 0));
    vector<vector<int> > lock(3, vector<int>(3, 0));
    
    solution(key, lock);

    return 0;
}