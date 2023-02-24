#include <iostream>
using namespace std;

long hms_to_secs(int hours, int minutes, int seconds) {
    int hoursToSeconds = hours * 3600;
    int minutesToSeconds = minutes * 60;
    long resultInSeconds = hoursToSeconds + minutesToSeconds + seconds;

    return resultInSeconds;
}

int main() {
    string exit;
    int hours, minutes, seconds = 0;

    while (exit != "exit") {
        cout << "Please enter a time in the format (12:59:59) to convert into seconds.\n";
        scanf("%i:%i:%i", &hours, &minutes, &seconds);
        if (hours != 0 || minutes != 0 || seconds != 0) {
            long timeInSeconds = hms_to_secs(hours, minutes, seconds);
            cout << "The time in seconds is " << timeInSeconds << ".\n\n";
            cout << "To exit the program type 'exit' or type anything else to rerun the program.\n";
            cin >> exit;
        } else {
            cout << "Please enter a time in the appropriate format.";
        }

    }

    return 0;
}
