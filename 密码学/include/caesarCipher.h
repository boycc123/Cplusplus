#pragma once

#include <string>
#include <vector>

class Caesar {
public:
    Caesar(int _key) : key(_key){};
    std::string encrypt(std::string str) {
        std::string retStr;
        char tmp;
        for (int i = 0; i < str.length(); i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                tmp = (str[i] - 'a' + key) % 26 + 'a';
            }else if (str[i] >= 'A' && str[i] <= 'Z') {
                tmp = (str[i] - 'A' + key) % 26 + 'A';
            }else {
                tmp = str[i];
            }
            retStr.push_back(tmp);
        }
        return retStr;
    }

    std::vector<std::string> decrypt(std::string str) {      // 穷举法破解
        std::string tmpStr;
        std::vector<std::string> retVector;
        char tmp;
        for (int k = 0; k < 26; k++){
            for (int i = 0; i < str.length(); i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    tmp = (str[i] - 'a' + k) % 26 + 'a';
                }else if (str[i] >= 'A' && str[i] < 'Z') {
                    tmp = (str[i] - 'A' + k) % 26 + 'A';
                }else {
                    tmp = str[i];
                }
                tmpStr.push_back(tmp);
            }
            retVector.push_back(tmpStr);
            tmpStr.clear();
        }
        return retVector;
    }

private:
    int key;


};
