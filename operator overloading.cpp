#include <iostream>

using namespace std;

class YouTubeChannel {
public:
    string Name;
    int subscriberCount;

    YouTubeChannel(string name, int subscriberCount) {
        this->Name = name;
        this->subscriberCount = subscriberCount;
    }

    // define the "+" operator for the YouTubeChannel class.
    YouTubeChannel operator+(const YouTubeChannel& channel2) const {
        string newName = Name + channel2.Name;
        int newSubscriberCount = subscriberCount + channel2.subscriberCount;
        return YouTubeChannel(newName, newSubscriberCount);
    }
};

// define the "<<" operator for the YouTubeChannel class.
ostream& operator<<(ostream& os, YouTubeChannel& channel) {
    os << "Channel Name: " << channel.Name << endl;
    os << "Subscriber count: " << channel.subscriberCount << endl;
    return os;
}

/*
// define the "+" operator for the YouTubeChannel class.
YouTubeChannel& operator+(const YouTubeChannel& channel1, const YouTubeChannel& channel2) {
    string newName = channel1.Name + channel2.Name;
    int newSubscriberCount = channel1.subscriberCount + channel2.subscriberCount;
    return *(new YouTubeChannel(newName, newSubscriberCount));
}
*/

int main() {
    YouTubeChannel yt1 = YouTubeChannel("Grade A Under A", 3680000);
    YouTubeChannel yt2 = YouTubeChannel("Grade A Under S+", 7680000);
    cout << yt1 << endl; // Use the overloaded << operator to output yt1
    YouTubeChannel b = yt1 + yt2;
    cout << b << endl;

    return 0;
}
