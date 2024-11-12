#pragma once
#include <fstream>
#include <filesystem>
#include <string>
#include <nlohmann/json.hpp>
#include <iostream>
#include <stdexcept>
#define LINUX_EXE_PATH "/proc/self/exe"

//required JSON file paths
#define SCAN_COMMAND_JSON_PARAM "ScanCommand"
#define IMAGE_SRC_JSON_PARAM "ImageSource"
namespace check
{
    /**
     * @brief class that manages program config
     */
    class ConfigManager
    {

        /// @brief command used to scan documents
        std::string scanCommand;

        /// @brief file path of the image of the check
        std::string imageSrc;

        /**
         * @brief gets the path of the config file from the executables source directory
         */
        std::filesystem::path getPath(std::string file);

    public:
        /**
         * @brief construscts the ConfigManager Object
         */
        ConfigManager(std::string fileName);
    };
};