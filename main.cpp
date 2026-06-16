#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    sort(calls.begin(), calls.end(),
        [](const EmergencyCall& a, const EmergencyCall& b) {
            return a.priority < b.priority;
        });

    cout << "Ambulances loaded: " << ambulances.size() << endl;
    cout << "Emergency calls loaded: " << calls.size() << endl;

    cout << "\nCalls sorted by priority:" << endl;

    for (const auto& call : calls) {
        cout << call.callId << " | "
             << call.callType << " | Priority "
             << call.priority << endl;
    }

    return 0;
}
