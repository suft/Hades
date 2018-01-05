#pragma once

#include <string>
#include <memory>
#include <unordered_map>

namespace sufy { namespace utils {

    template <typename T>
    class Codex {
    private:
        static std::unordered_map<std::string, std::shared_ptr<T>> content;
    public:
        static std::shared_ptr<T> Acquire(const std::string& name);
        static void Clean();
    };
}}
