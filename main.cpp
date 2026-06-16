#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

struct Ambulance {
    string id;
    string location;
    bool available;
};

struct EmergencyCall {
    string callId;
    string callType;
    string location;
    int priority;
};

struct Route {
    string from;
    string to;
    int travelTime;
};

int findTravelTime(const vector<Route>& routes, const string& from, const string& to) {
    for (const auto& route : routes) {
        if (route.from == from && route.to == to) {
            return route.travelTime;
        }
    }

    return 9999;
}

int main() {

    cout << "C++ Ambulance Dispatch Simulator" << endl;

    vector<Ambulance> ambulances = {
        {"AMB-1", "StationA", true},
        {"AMB-2", "StationB", true},
        {"AMB-3", "StationC", true}
    };

    vector<EmergencyCall> calls = {
        {"CALL-1001", "Cardiac", "LocationX", 1},
        {"CALL-1002", "Trauma", "LocationY", 2},
        {"CALL-1003", "Fall", "LocationZ", 3}
    };

    vector<Route> routes = {
        {"StationA", "LocationX", 12},
        {"StationB", "LocationX", 7},
        {"StationC", "LocationX", 15},

        {"StationA", "LocationY", 10},
        {"StationB", "LocationY", 14},
        {"StationC", "LocationY", 6},

        {"StationA", "LocationZ", 8},
        {"StationB", "LocationZ", 11},
        {"StationC", "LocationZ", 9}
    };

    sort(calls.begin(), calls.end(),
         [](const EmergencyCall& a, const EmergencyCall& b) {
             return a.priority < b.priority;
         });

    cout << "Ambulances loaded: " << ambulances.size() << endl;
    cout << "Emergency calls loaded: " << calls.size() << endl;

    cout << "\nCalls sorted by priority:" << endl;

    for (const auto& call : calls) {
        cout << call.callId
             << " | "
             << call.callType
             << " | Priority "
             << call.priority
             << endl;
    }

    cout << "\nDispatch Results:" << endl;

    auto startTime = chrono::high_resolution_clock::now();

    for (const auto& call : calls) {

        int fastestTime = 9999;
        int selectedIndex = -1;

        for (int i = 0; i < ambulances.size(); i++) {

            int routeTime = findTravelTime(
                routes,
                ambulances[i].location,
                call.location
            );

            if (ambulances[i].available && routeTime < fastestTime) {
                fastestTime = routeTime;
                selectedIndex = i;
            }
        }

        if (selectedIndex != -1) {

            cout << "Dispatch Record: "
                 << "Call ID=" << call.callId
                 << ", Call Type=" << call.callType
                 << ", Call Location=" << call.location
                 << ", Selected Ambulance=" << ambulances[selectedIndex].id
                 << ", Ambulance Location=" << ambulances[selectedIndex].location
                 << ", Time to Call=" << fastestTime
                 << " minutes"
                 << endl;

            ambulances[selectedIndex].available = false;
        }
    }

    auto endTime = chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast<chrono::microseconds>(
            endTime - startTime);

    cout << "\nAlgorithm Execution Time: "
         << duration.count()
         << " microseconds"
         << endl;

    return 0;
}
