/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConfigManager.cpp
 * Author: henrinurmi
 * 
 * Created on December 13, 2015, 5:30 PM
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

#include "ConfigManager.h"

//from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

ConfigManager::ConfigManager() {
}

ConfigManager::ConfigManager(const ConfigManager& orig) {
}

ConfigManager::~ConfigManager() {
}

void ConfigManager::loadFromFile(const std::string& path) {
    values.clear();
    std::ifstream file(path);
    
    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);
        if(line.length() > 0 && line[0] != '#') {
            std::string value, key;
            std::stringstream ss(line);
            std::getline(ss, key, '=');
            std::getline(ss, value, '=');
            
            if(!value.empty()) {
                values[key] = value;
            }
        }
    }
}

int ConfigManager::getInt(const std::string& key) {
    std::cout << values[key] << std::endl;
    return std::stoi(values[key]);
}

std::string ConfigManager::getString(const std::string& key) {
    return values[key];
}


