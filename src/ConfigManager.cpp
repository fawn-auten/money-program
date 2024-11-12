#include <../include/ConfigManager.hpp>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

check::ConfigManager::ConfigManager(std::string configPath){
    std::filesystem::path sourcePath = getPath(configPath);
    std::ifstream jsonFile(sourcePath);
    nlohmann::json data = nlohmann::json::parse(jsonFile);

    //validate if jsonfile has correct values
    if( data.find(SCAN_COMMAND_JSON_PARAM) == data.end() ||
        data.find(IMAGE_SRC_JSON_PARAM) == data.end() ){
            throw new std::invalid_argument("json file " + sourcePath + " lacks essential arguments (see readme for more information)")
    }
}

std::filesystem::path check::ConfigManager::getPath(std::string file){
    std::filesystem::path rootDirectory = std::filesystem::canonical(LINUX_EXE_PATH);
    
    return rootDirectory.parent_path() += ("/" + file);
}