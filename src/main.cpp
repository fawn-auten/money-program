#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <../include/ConfigManager.hpp>
int main(void){
    
    check::ConfigManager programConfig("config.json");
}