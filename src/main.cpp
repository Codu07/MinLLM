/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/01 21:14:12
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <spdlog/spdlog.h>
#include <cxxopts.hpp>

#include "error.h"

namespace minllm {

int run(int argc, char** argv) {
    cxxopts::Options options("ail");
    options.add_options()
        ("c,conf", "Configure file", cxxopts::value<std::string>())
        ("m,model", "Specify Model file", cxxopts::value<std::string>())
        ("t,type", "Specify Model Type", cxxopts::value<std::string>());

    auto opt = options.parse(argc, argv);

    std::string config_path("");
    if (opt.count("conf") != 0) {
        try {
            config_path = opt["conf"].as<std::string>();
        } catch(...) {
            spdlog::error("cmd [conf] error!");
            return ERROR_CONFIG_ERROR;
        }
    }

    return ERROR_SUCC;
}

} // namespace minllm

int main(int argc, char** argv) {
    return minllm::run(argc, argv);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
