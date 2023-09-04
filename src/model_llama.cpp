/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file model_llama.cpp
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 13:47:03
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include "model_llama.h"

namespace minllm {

LlamaModel::LlamaModel() {

}

LlamaModel::~LlamaModel() {

}

error_type_t LlamaModel::load_from_path(const std::string& model_path) {
    return ERROR_UNKNOWN;
}

} // namespace minllm

/* vim: set ts=4 sw=4 sts=4 tw=100 */
