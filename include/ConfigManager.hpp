#pragma once
#include<fstream>
#include<string>
#include<nlohmann/json.hpp>
namespace chk {
    /**
     * @brief class that manages program config
     */
    class ConfigManager{

        
        ConfigManager(std::string& fileName);
    };
};