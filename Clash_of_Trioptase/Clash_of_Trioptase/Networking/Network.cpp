#include "Network.h"

string Network::json_to_string(json& _message) {
    vector<uint8_t> temp_vec = json::to_msgpack(_message);
    string text = "";
    for (int i = 0; i < temp_vec.size(); i++) {
      text += temp_vec[i];
    }
    return text;
}