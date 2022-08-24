#include <iostream>
#include <vector>
#include "include/caesarCipher.h"

int main(){

    // std::string str1 = {"CJLUSEC{my-easy-caesar}"};
    std::string str1;
    std::string enStr = {"FMOXVHF1pb5hdvb5fdhvdu0"};
    std::cout << "input flag : ";
    std::cin >> str1;
    for (int i = 0; i < str1.length(); i++) {
        if(str1[i] == '{') {
            str1[i] = '1';
        }
        if(str1[i] == '}') {
            str1[i] = '0';
        }
        if(str1[i] == '-') {
            str1[i] = '5';
        }
    }
    // std::string cry = {"iodj{whvw}"};
    Caesar C1 = Caesar(3);
    if(enStr.compare(C1.encrypt(str1)) == 0) {
        std::cout << "success\n";
    }else {
        std::cout << "failed\n";
    }
    // std::vector<std::string> V1;
    // V1 = C1.decrypt(cry);
    // for(int j = 0; j < V1.size(); j++) {
        // std::cout << "[key => " << j << "] " << V1[j] << std::endl;
    // }
    return 0;
}