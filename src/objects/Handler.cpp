#include "Handler.hpp"

namespace sufy { namespace objects {

    void Handler::add(std::shared_ptr<Object> o) {
        this->objects.emplace_back(o);
    }

    void Handler::remove(std::shared_ptr<Object> o) {
        this->objects.erase(std::remove(this->objects.begin(), this->objects.end(), o), this->objects.end());
    }

    void Handler::update(float dt) {
        for (auto o : this->objects) o->update(dt);
    }

    void Handler::render(sf::RenderTarget &rt) {
        for (auto o : this->objects) o->render(rt);
    }
}}
