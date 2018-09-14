#pragma once

#include <functional>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../utils/Codex.hpp"

namespace sufy { namespace graphics {

        class Animation {
        private:
            typedef std::function<void(void)> Callback;
            std::shared_ptr<sf::Texture> texture;
            std::vector<sf::IntRect> frames;

            bool loop;
            Callback callback;
            bool complete;
            bool backwards;
            int length;
            float hold;
            float time;
            int current;
        public:
            Animation() = default;
            Animation(std::string name, int x, int y, int width, int height, int length, float hold, bool backwards, bool loop, Callback callback);

            void applyToSprite(sf::Sprite& s) const;
            void update(float dt);
            void reset();
        private:
            void previous();
            void next();
        };

}}
