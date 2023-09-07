/***************************************************************************
 * 
 * Copyright (c) 2023 Wang Tao. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file conf.h
 * @author wangtao(wtzhuque@163.com)
 * @date 2023/09/05 13:42:01
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MINLLM_CONF_H
#define MINLLM_CONF_H

#include <optional>
#include <string>
#include <vector>
#include <map>

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
    std::map<std::string, Value*> _fields; 
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

class Configure {
public:
    Configure() {}

    Configure(Value* value) : _root(value) {}

    ~Configure() {}

public:
    /**
     * load config from a yaml file
     */
    int load_from_yaml(const std::string& path);

    /**
     * load config from a json file
     */
    int load_from_json(const std::string& path);

    int reload();

    void reset();

public:
    std::optional<Value*> get(const std::string& field_name) {
        if (_root == nullptr) {
            return std::nullopt;
        }

        return _root->field(field_name);
    }

private:
    Value* _root {nullptr};
}; // class Configure

} // namespace minllm

#endif  //MINLLM_CONF_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
