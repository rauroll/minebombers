/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConfigManager.h
 * Author: henrinurmi
 *
 * Created on December 13, 2015, 5:30 PM
 */

#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <string>
#include <map>

class ConfigManager {
public:
    ConfigManager();
    ConfigManager(const ConfigManager& orig);
    virtual ~ConfigManager();
    
    static ConfigManager& getInstance() {
        static ConfigManager instance;
        return instance;
    }
    
    void loadFromFile(const std::string& path);
    
    std::string getString(const std::string& key);
    int getInt(const std::string& key);
private:
    std::map<std::string, std::string> values;
};

#endif /* CONFIGMANAGER_H */

