#include "Fader.hpp"

namespace sufy { namespace penner {

    Fader::Fader(Fader::Direction direction, float duration, sufy::constant::Update fadeUpdate, sufy::constant::Render fadeRender, sufy::constant::Callback fadeCallback) {
        this->duration = duration;
        this->current = 0.0f;
        this->fadeUpdate = fadeUpdate;
        this->fadeRender = fadeRender;
        this->fadeCallback = fadeCallback;
        this->overlay = sf::RectangleShape(sufy::constant::DIMENSIONS);
        this->overlay.setPosition(sufy::constant::ORIGIN);
        this->colour = sf::Color();
        this->alpha = sufy::constant::OPAQUE_ALPHA;
        this->direction = direction;
        this->complete = false;
    }

    void Fader::update(float dt) {
        if (this->current >= this->duration) {
            this->current = this->duration;
            this->complete = true;
            this->fadeCallback();
        } else {
            this->current += dt;
            auto percent = this->getPercentage();
            if (this->direction == Fader::Direction::IN) this->alpha = sufy::utils::Clamp((1.0f - percent) * sufy::constant::ALPHA_RANGE, sufy::constant::TRANSPARENT_ALPHA, sufy::constant::OPAQUE_ALPHA);
            else if (this->direction == Fader::Direction::OUT) this->alpha = sufy::utils::Clamp(percent * sufy::constant::ALPHA_RANGE, sufy::constant::TRANSPARENT_ALPHA, sufy::constant::OPAQUE_ALPHA);
            this->colour.a = this->alpha;
            this->overlay.setFillColor(this->colour);
            this->fadeUpdate(dt);
        }
    }

    void Fader::render(sf::RenderTarget &rt) {
        this->fadeRender(rt);
        rt.draw(this->overlay);
    }

    Fader::Direction Fader::getDirection() {
        return this->direction;
    }

    void Fader::setDirection(Fader::Direction direction) {
        this->direction = direction;
    }

    bool Fader::isComplete() {
        return this->complete;
    }

    void Fader::setComplete(bool complete) {
        this->current = 0.0f;
        this->complete = complete;
    }

    float Fader::getPercentage() {
        return this->current / this->duration;
    }
}}
