#include <iostream>
#include <string>
#include <map>

using namespace std;

string analyzeSentiment(const string& input) {
    if (input.find("happy") != string::npos || input.find("good") != string::npos) {
        return "positive";
    } else if (input.find("sad") != string::npos || input.find("bad") != string::npos) {
        return "negative";
    } else {
        return "neutral";
    }
}

string getResponse(const string& input) {
    map<string, string> responses;
    responses["hello"] = "Hello! How can I assist you today?";
    responses["bye"] = "Goodbye! Have a great day!";
    responses["how are you"] = "I'm an AI, so I don't have feelings, but I'm here to help you!";

    // Use an iterator for C++98 compatibility
    for (map<string, string>::const_iterator it = responses.begin(); it != responses.end(); ++it) {
        if (input.find(it->first) != string::npos) {
            return it->second;
        }
    }
    return "I'm sorry, I didn't understand that.";
}

int main() {
    string userInput;
    cout << "Chatbot: Hello! How can I assist you today?" << endl;

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        if (userInput == "exit" || userInput == "quit" || userInput == "bye") {
            cout << "Chatbot: Goodbye!" << endl;
            break;
        }

        string sentiment = analyzeSentiment(userInput);
        cout << "Chatbot: I sense your sentiment is " << sentiment << "." << endl;

        string response = getResponse(userInput);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}

