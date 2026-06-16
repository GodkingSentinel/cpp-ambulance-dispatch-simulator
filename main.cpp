#include <iostream>
#include <string>
#include <vector>

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

    return 0;
}
