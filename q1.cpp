#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a group
struct Group {
    int groupSize; // Number of persons in the group
    int ticketPrice; // Cost of the seat ticket for the group

    Group(int size, int price) : groupSize(size), ticketPrice(price) {}
};

// Comparator function to sort groups in descending order of ticket price
bool compareGroups(const Group& a, const Group& b) {
    return a.ticketPrice > b.ticketPrice;
}

// Function to calculate the maximum profit
int calculateMaxProfit(int N, vector<Group>& groups) {
    // Sort groups in descending order based on ticket price
    sort(groups.begin(), groups.end(), compareGroups);

    int maxProfit = 0;
    vector<bool> seatsOccupied(N + 1, false); // Array to track occupied seats

    // Assign seats to groups optimally
    for (const Group& group : groups) {
        for (int seat = 1; seat <= N; ++seat) {
            // Check if there are enough consecutive seats available for the group
            bool seatsAvailable = true;
            for (int i = 0; i < group.groupSize; ++i) {
                if (seat + i > N || seatsOccupied[seat + i]) {
                    seatsAvailable = false;
                    break;
                }
            }

            // If enough seats are available, assign them to the group and update profit
            if (seatsAvailable) {
                for (int i = 0; i < group.groupSize; ++i) {
                    seatsOccupied[seat + i] = true;
                }
                maxProfit += group.ticketPrice * group.groupSize;
                break; // Move to the next group
            }
        }
    }

    return maxProfit;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Group> groups;

    // Input the group details
    for (int i = 0; i < M; ++i) {
        int groupSize, ticketPrice;
        cin >> groupSize >> ticketPrice;
        groups.push_back(Group(groupSize, ticketPrice));
    }

    int maxProfit = calculateMaxProfit(N, groups);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
