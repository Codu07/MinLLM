/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file model_config.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 13:31:41
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_MODEL_CONFIG_H
#define MINLLM_MODEL_CONFIG_H

#include <vector>
#include <unordered_map>

#include <yaml-cpp/yaml.h>

#include "conf.h"
#include "model_type.h"

namespace minllm {

class ModelConfig {
public:
    static ModelConfig& default_config();

public:
    ModelConfig() {}

    ~ModelConfig() {}

    virtual model_type_t model_type() const {
        return MODEL_TYPE_UNKNOWN;
    }

private:
    Value* _root {nullptr};
}; // class ModelConfig

} // namespace minllm

#endif  //MINLLM_MODEL_CONFIG_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
