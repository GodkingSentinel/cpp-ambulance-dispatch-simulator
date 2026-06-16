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

    int fastestTime = 9999;
    int selectedIndex = -1;

    for (int i = 0; i < ambulances.size(); i++) {

        if (ambulances[i].available &&
            ambulances[i].travelTimeToCall < fastestTime) {

            fastestTime = ambulances[i].travelTimeToCall;
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
     << ", Time to Call=" << ambulances[selectedIndex].travelTimeToCall << " minutes"
     << endl;

        ambulances[selectedIndex].available = false;
    }
}

    return 0;
}
