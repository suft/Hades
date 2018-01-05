#include "Codex.hpp"

namespace sufy { namespace utils {

    template <typename T>
    std::unordered_map<std::string, std::shared_ptr<T>> Codex<T>::content;

    template<typename T>
    std::shared_ptr<T> Codex<T>::Acquire(const std::string &name) {
        const auto i = content.find(name);
        if (i != content.end()) return i->second;
        else {
            auto cont = std::make_shared<T>();
            cont->loadFromFile(name);
            content.insert({name, cont});
            return cont;
        }
    }

    template<typename T>
    void Codex<T>::Clean() {
        for (auto i = content.begin(); i != content.end();) {
            if (i->second.unique()) i = content.erase(i);
            else ++i;
        }
    }
}}
