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
#include "conf.h"
#include "server.h"

namespace minllm {

static const std::string DEFAULT_CONFIG_PATH = "";
static const int         DEFAULT_PORT = 8086;

int run(int argc, char** argv) {
    cxxopts::Options options("ail");
    options.add_options()
        ("c,conf", "Configure file", cxxopts::value<std::string>())
        ("m,model", "Specify Model file", cxxopts::value<std::string>())
        ("t,type", "Specify Model Type", cxxopts::value<std::string>())
        ("p,port", "Specify service port", cxxopts::value<int>());

    auto opt = options.parse(argc, argv);

    std::string config_path(DEFAULT_CONFIG_PATH);
    if (opt.count("conf") != 0) {
        try {
            config_path = opt["conf"].as<std::string>();
        } catch(...) {
            spdlog::error("cmd [conf] error!");
            return ERROR_CONFIG_ERROR;
        }
    }

    int port = DEFAULT_PORT;
    if (opt.count("port") != 0) {
        try {
            port = opt["port"].as<int>();
        } catch (...) {
            spdlog::error("cmd [port] error!");
            return ERROR_CONFIG_ERROR;
        }
    }

    int ret = ERROR_SUCC;

    Configure conf;
    ret = conf.load_from_yaml(config_path);
    if (ret != ERROR_SUCC) {
        spdlog::error("load conf failed!");
        return ret;
    }
    
    Server server;
    ret = server.init(&conf);
    if (ret != 0) {
        spdlog::error("init server failed!");
        return ret;
    }

    ret = server.start_on_port(opt["port"].as<int>());
    if (ret != 0) {
        spdlog::error("start server failed!");
        return ret;
    }

    ret = server.wait_to_exit();
    if (ret != 0) {
        spdlog::error("server exit failed!");
    }

    return ERROR_SUCC;
}

} // namespace minllm

int main(int argc, char** argv) {
    return minllm::run(argc, argv);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
