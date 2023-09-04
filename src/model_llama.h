/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file model_llama.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/04 13:46:55
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_MODEL_LLAMA_H
#define MINLLM_MODEL_LLAMA_H

#include "model.h"

namespace minllm {

class LlamaModel : public Model {
public:
    LlamaModel();

    virtual ~LlamaModel();

public:
    virtual error_type_t load_from_path(const std::string& model_path);  
}; // class LlamaModel

} // namespace minllm

#endif  //MINLLM_MODEL_LLAMA_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
