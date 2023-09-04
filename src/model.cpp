/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file model.cpp
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 13:19:01
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include "error.h"
#include "model.h"
#include "model_llama.h"

namespace minllm {

Model* Model::create_model_from(const std::string& model_path, const ModelConfig& config) {
    Model* model = nullptr;
    switch (config.model_type()) {
    case MODEL_TYPE_LLAMA:
        model = new LlamaModel(); 
        break;
    default:
        break;
    }

    error_type_t ret = ERROR_SUCC;
    ret = model->load_from_path(model_path);
    if (ret != ERROR_SUCC) {
        return nullptr;
    }

    return model; 
}

error_type_t Model::load_from_path(const std::string& model_path) {
    return ERROR_UNKNOWN;
}

} // namespace minllm

/* vim: set ts=4 sw=4 sts=4 tw=100 */
