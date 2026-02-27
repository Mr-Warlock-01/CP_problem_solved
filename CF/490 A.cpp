#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> children(n);
    for (int i = 0; i < n; ++i) {
        cin >> children[i];
    }

    // Count the number of children for each skill
    int cnt1 = 0; // Programming
    int cnt2 = 0; // Math
    int cnt3 = 0; // PE

    for (int i = 0; i < n; ++i) {
        if (children[i] == 1) {
            cnt1++;
        } else if (children[i] == 2) {
            cnt2++;
        } else {
            cnt3++;
        }
    }

    // Calculate the maximum number of teams
    int max_teams = min(min(cnt1, cnt2), cnt3);

    // Check if we can form at least one team
    if (max_teams == 0) {
        cout << 0 << endl;
    } else {
        // Initialize vectors to store indices of children with different skills
        vector<int> prog;
        vector<int> math;
        vector<int> pe;

        // Assign children to corresponding skill vectors
        for (int i = 0; i < n; ++i) {
            if (children[i] == 1) {
                prog.push_back(i + 1);
            } else if (children[i] == 2) {
                math.push_back(i + 1);
            } else {
                pe.push_back(i + 1);
            }
        }

        // Initialize vectors to store team indices
        vector<int> team1(max_teams);
        vector<int> team2(max_teams);
        vector<int> team3(max_teams);

        // Form teams with programmers
        for (int i = 0; i < max_teams; ++i) {
            team1[i] = prog[i];
            team2[i] = math[i];
            team3[i] = pe[i];
        }

        // Print the number of teams
        cout << max_teams << endl;

        // Print the teams
        for (int i = 0; i < max_teams; ++i) {
            cout << team1[i] << " " << team2[i] << " " << team3[i] << endl;
        }
    }

    return 0;
}