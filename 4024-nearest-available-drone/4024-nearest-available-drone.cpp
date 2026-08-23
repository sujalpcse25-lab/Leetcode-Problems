class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minDistance = INT_MAX; // Initialize minimum distance to a large value
        int nearestIndex = -1; // Initialize the index of the nearest drone to -1

        // Iterate through each drone
        for (int i = 0; i < drones.size(); i++) {
            // Calculate the Manhattan distance
            int distance = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);

            // Check if the drone can reach the target and if it's the closest one found so far
            if (distance <= drones[i][2]) {
                if (distance < minDistance || (distance == minDistance && i < nearestIndex)) {
                    minDistance = distance; // Update the minimum distance
                    nearestIndex = i; // Update the index of the nearest drone
                }
            }
        }

        return nearestIndex; // Return the index of the nearest drone or -1 if none found
    }
};
