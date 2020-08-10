#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>

using namespace std;
bool compare(pair<int, int> a, pair<int, int>b) {
	return a.first < b.first;
}

int main(void) {
	int testcase_num;
	int applicant_num;

	cin >> testcase_num;
	int *test_success = (int*)malloc(sizeof(int) * testcase_num);

	for (int j = 0; j < testcase_num; j++) {

		cin >> applicant_num;
		int doc_score, mee_score;
		vector<pair <int, int>> score;
		test_success[j] = 0;

		for (int i = 0; i < applicant_num; i++) {
			cin >> doc_score >> mee_score;
			score.push_back(pair<int, int>(doc_score, mee_score));
		}

		sort(score.begin(), score.end(), compare);

		int min = 100001;
		for (int i = 0; i < applicant_num; i++) {
			if (score[i].second < min) {
				min = score[i].second;
				test_success[j] += 1;
			}
		}
	}

	for (int j = 0; j < testcase_num; j++) {
		cout << test_success[j] << endl;
	}

	free(test_success);
	return 0;
}