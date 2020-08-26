//
// Created by xiaoming on 2020/8/26.
//

#include "helper.h"

namespace Helper {
    std::string hello(JNIEnv *env) {
        const std::string hello = "helper: hello.";
        return hello;
    }
}