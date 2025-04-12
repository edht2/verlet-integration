#include "verlet.hpp"

class Particle {
    public:
        CircleShape sprite;
        Vector2f previousPosition;
        Vector2f positionSwitch;

        Particle() {
            sprite.setRadius(particleRadius);
            sprite.setPosition(200 + (rand() % (scrw-200)), rand() % scrh);
            sprite.setFillColor(Color(155 + rand() % 100, 155 + rand() % 100, 155 + rand() % 100));
            // random bright colour
            previousPosition = sprite.getPosition();
        }
    
    void updateVerlet(Vector2f acceleration) {
        positionSwitch = sprite.getPosition();

        sprite.setPosition(sprite.getPosition() + (sprite.getPosition() - previousPosition) + acceleration);
        previousPosition = positionSwitch;

        boundBox(); // Ensure the particle stays in bounds
    }

    void boundBox() {

        // Bouncing mechanics
        if (sprite.getPosition().y + particleRadius * 2 > scrh || sprite.getPosition().y < 0) {
            positionSwitch = sprite.getPosition();
            sprite.setPosition(sprite.getPosition().x + (sprite.getPosition().x - previousPosition.x), previousPosition.y);
            previousPosition = {positionSwitch.x + ((sprite.getPosition().x - positionSwitch.x) * bounceDampeningConstant), positionSwitch.y + ((sprite.getPosition().y - positionSwitch.y) - ((sprite.getPosition().y - positionSwitch.y) * bounceDampeningConstant))};

        }
        if (sprite.getPosition().x + particleRadius * 2 > scrw || sprite.getPosition().x < 0) {
            positionSwitch = sprite.getPosition();
            sprite.setPosition(previousPosition.x, sprite.getPosition().y + (sprite.getPosition().y - previousPosition.y));
            previousPosition = {positionSwitch.x + ((sprite.getPosition().x - positionSwitch.x) - ((sprite.getPosition().x - positionSwitch.x) * bounceDampeningConstant)), positionSwitch.y + ((sprite.getPosition().y - positionSwitch.y) * bounceDampeningConstant)};
        }
        //sprite.setPosition(max(0.f, sprite.getPosition().x), max(0.f, sprite.getPosition().y));
        //sprite.setPosition(min(float(scrh - particleRadius * 2), sprite.getPosition().x), min(float(scrw - particleRadius * 2), sprite.getPosition().y));
    }
};