#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class MapColor
{
public:
    // Simple regions
    vector<string> REGIONS = {"1", "2", "3", "4"};

    // Colors to use
    vector<string> COLORS = {"RED", "GREEN", "BLUE"};

    // Neighbors (simple map)
    map<string, vector<string>> NEIGHBORS = {
        {"1", {"2", "3"}},
        {"2", {"1", "3"}},
        {"3", {"1", "2", "4"}},
        {"4", {"3"}}
    };

    // Store assigned colors
    map<string, string> assignment;

    bool backtrack()
    {
        // If all regions are assigned, solution found
        if (assignment.size() == REGIONS.size())
            return true;

        // Choose an unassigned region
        string var;
        for (auto &r : REGIONS)
        {
            if (assignment.find(r) == assignment.end())
            {
                var = r;
                break;
            }
        }

        // Try each color
        for (auto &color : COLORS)
        {
            if (isConsistent(var, color))
            {
                assignment[var] = color; // assign color

                if (backtrack()) // move forward
                    return true;

                assignment.erase(var); // undo if fails
            }
        }
        return false; // no color works → backtrack
    }

    // Check if assigning this color is allowed
    bool isConsistent(const string &var, const string &color)
    {
        for (auto &nb : NEIGHBORS[var])
        {
            // If neighbor has same color → conflict
            if (assignment.find(nb) != assignment.end() && assignment[nb] == color)
                return false;
        }
        return true;
    }

    // Print solution
    void printSolution()
    {
        cout << "Solution:\n";
        for (auto &r : REGIONS)
        {
            cout << "Region " << r << " = " << assignment[r];
            cout << " | Neighbors: ";

            for (auto &nb : NEIGHBORS[r])
            {
                cout << nb << "(";
                if (assignment.find(nb) != assignment.end())
                    cout << assignment[nb];
                else
                    cout << "Not Assigned";
                cout << ") ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    MapColor csp;
    if (csp.backtrack())
    {
        csp.printSolution();
    }
    else
    {
        cout << "No solution found.\n";
    }
    return 0;
}
