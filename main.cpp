#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Ambulance {
    string id;
    string location;
    bool available;
    int travelTimeToCall;
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
    {"AMB-1", "StationA", true, 12},
    {"AMB-2", "StationB", true, 7},
    {"AMB-3", "StationC", true, 15}
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
    cout << "\nDispatch Results:" << endl;

for (const auto& call : calls) {
    for (auto& ambulance : ambulances) {
        if (ambulance.available) {
            cout << call.callId << " assigned to "
                 << ambulance.id << " from "
                 << ambulance.location << endl;

            ambulance.available = false;
            break;
        }
    }
}

    return 0;
}
