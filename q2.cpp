#include <iostream>
#include <vector>

using namespace std;

// Function to determine the number of remaining dragons in each dungeon
vector<int> remainingDragons(int N, vector<int>& dragons, int M) {
    vector<int> remaining(N, 0); // Initialize the remaining dragons for each dungeon

    int currentDungeon = 0; // Start from dungeon 1
    while (M > 0) {
        if (dragons[currentDungeon] > 0) {
            dragons[currentDungeon]--; // Eliminate one dragon
            remaining[currentDungeon]++; // Increment the remaining count for this dungeon
            M--; // Reduce the count of dragons to be eliminated
        }

        // Move to the next dungeon
        currentDungeon = (currentDungeon + 1) % N;
    }

    return remaining;
}

int main() {
    int N, M;
    cout << "Enter the number of dungeons: ";
    cin >> N;

    vector<int> dragons(N, 0);
    cout << "Enter the number of dragons in each dungeon:\n";
    for (int i = 0; i < N; i++) {
        cin >> dragons[i];
    }

    cout << "Enter the number of dragons to be eliminated (M): ";
    cin >> M;

    vector<int> remaining = remainingDragons(N, dragons, M);

    cout << "Number of remaining dragons in each dungeon:\n";
    for (int i = 0; i < N; i++) {
        cout << "Dungeon " << i + 1 << ": " << remaining[i] << " dragons\n";
    }

    return 0;
}
