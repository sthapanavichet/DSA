#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM_CITIES = 5;
const string cities[NUM_CITIES] = {"Toronto", "Mississauga", "Markham", "Brampton", "Etobicoke"};

int distances[NUM_CITIES][NUM_CITIES] = {
        {0, 25, 30, 20, 35},
        {25, 0, 40, 15, 30},
        {30, 40, 0, 45, 20},
        {20, 15, 45, 0, 40},
        {35, 30, 20, 40, 0}
};

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    vector<int> cities_indices(NUM_CITIES);
    for (int i = 0; i < NUM_CITIES; ++i)
        cities_indices[i] = i;

    int min_distance = INT_MAX;
    vector<int> min_path;

    do {
        int current_distance = 0;
        for (int i = 0; i < NUM_CITIES - 1; ++i)
            current_distance += distances[cities_indices[i]][cities_indices[i + 1]];
        current_distance += distances[cities_indices[NUM_CITIES - 1]][cities_indices[0]];

        if (current_distance < min_distance) {
            min_distance = current_distance;
            min_path = cities_indices;
        }

        // Display current path
        cout << "Path: ";
        for (int i = 0; i < NUM_CITIES; ++i)
            cout << cities[cities_indices[i]] << " -> ";
        cout << cities[cities_indices[0]] << "   " << "Distance: " << current_distance << " kilometers" << endl;
    } while (next_permutation(cities_indices.begin() + 1, cities_indices.end()));

    cout << "Shortest path: ";
    for (int i = 0; i < NUM_CITIES; ++i)
        cout << cities[min_path[i]] << " -> ";
    cout << cities[min_path[0]] << "   " << "Total distance: " << min_distance << " kilometers" << endl;

    return 0;
}