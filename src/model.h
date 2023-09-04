/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file model.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 13:18:55
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_MODEL_H
#define MINLLM_MODEL_H

#include <string>

#include "error.h"
#include "model_config.h"

namespace minllm {

class Model {
public:
    Model* create_model_from(const std::string& model_path, const ModelConfig& config);

public:
    Model() {}

    virtual ~Model() {}

public:
    virtual error_type_t load_from_path(const std::string& model_path); 
}; // class Model

} // namespace minllm

#endif  //MINLLM_MODEL_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
