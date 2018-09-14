#include "Camera.hpp"

namespace sufy { namespace window {

        Camera::Camera(): view(sufy::constant::CENTER, sufy::constant::DIMENSIONS) {
            this->view.zoom(0.60);
        }

        void Camera::render(sf::RenderTarget &rt) {
            rt.setView(this->view);
        }

        void Camera::reset(sf::RenderTarget &rt) {
            sf::View v = rt.getDefaultView();
            rt.setView(v);
        }

        void Camera::move(sf::Vector2f position, sf::Vector2f speed) {
            sf::Vector2f center = this->view.getCenter();
            this->view.move(
                    (position.x - center.x) * speed.x,
                    (position.y - center.y) * speed.y
            );
        }
    }}
