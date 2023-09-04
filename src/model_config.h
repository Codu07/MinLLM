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

#include "model_type.h"

namespace minllm {

class FloatValue;
class IntValue;
class StrValue;

class Value {
public:
    Value() {}
    virtual ~Value() {}

    virtual bool is_object() const {return true;}
    virtual bool is_array() const {return false;}
    virtual bool is_float() const {return false;}
    virtual bool is_str() const {return false;}
    virtual bool is_int() const {return false;}

    std::optional<Value*> field(const std::string& field) {
        auto it = _fields.find(field);
        if (it != _fields.end()) {
            return it->second;
        }
        return std::nullopt;
    }

    virtual std::optional<float> as_float() const {
        return std::nullopt;
    }

    virtual std::optional<int> as_int() const {
        return std::nullopt;
    }

    virtual std::optional<std::string> as_str() const {
        return std::nullopt;
    }

private:
    std::unordered_map<std::string, Value*> _fields; 
}; // class Value

class ArrayValue : public Value {
public:
    ArrayValue() {}

    virtual bool is_array() const {return true;}
    std::optional<Value*> at(size_t i) {
        if (i < _array.size()) {return _array[i];}
        else {return std::nullopt;}
    }

private:
    std::vector<Value*> _array; 
}; // class ArrayValue

class FloatValue : public Value {
public:
    FloatValue(float v) : _value(v) {}
    virtual std::optional<float> as_float() const {return _value;}
    virtual bool is_float() const {return true;}
private:
    float _value {0.0f};
}; // class FloatValue

class StrValue : public Value {
public:
    StrValue(const std::string& v): _value(v) {}
    virtual std::optional<std::string> as_str() const {return _value;}
    virtual bool is_string() const {return true;}
private:
    std::string _value {""};
}; // class StrValue

class IntValue : public Value {
public:
    IntValue(int v): _value(v) {}
    virtual std::optional<int> as_int() const {return _value;}
    virtual bool is_int() const {return true;}
private:
    int _value {0};
}; // class IntValue

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
