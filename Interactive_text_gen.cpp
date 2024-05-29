#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string requestOpenAI(const std::string& prompt) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    std::string apiKey = "YOUR_API_KEY_HERE";
    std::string data = json({{"prompt", prompt}, {"max_tokens", 60}}).dump();

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/engines/text-davinci-003/completions");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        std::string authHeader = "Authorization: Bearer " + apiKey;
        headers = curl_slist_append(headers, authHeader.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            return "";
        }
    }
    return readBuffer;
}

int main() {
    std::string prompt;
    std::cout << "Enter your prompt: ";
    std::getline(std::cin, prompt);

    std::string response = requestOpenAI(prompt);
    json responseJson = json::parse(response);
    std::cout << "OpenAI response: " << responseJson["choices"][0]["text"] << std::endl;

    return 0;
}
