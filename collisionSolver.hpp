#include "particle.hpp"
#include <cmath>


vector<Particle> collisionFix(Particle p1, Particle p2) {
    float distance = sqrt(pow(p1.sprite.getPosition().x - p2.sprite.getPosition().x, 2) + pow(p1.sprite.getPosition().y - p2.sprite.getPosition().y, 2));

    if (distance < particleRadius * 2) {
        // the particles are touching!
        Vector2f delta = p1.sprite.getPosition() - p2.sprite.getPosition();
        float overlap = 0.5 * distance - p1.sprite.getRadius() - p2.sprite.getRadius();
        // the 0.5 could be changed to show the mass of each particle

        Vector2f normal = delta / distance;
        Vector2f separation = {normal.x * overlap, normal.y * overlap};

        p1.sprite.setPosition(p1.sprite.getPosition() - separation);
        p2.sprite.setPosition(p2.sprite.getPosition() + separation);
        // Move each particle away from one another  

        p1.previousPosition = {p1.sprite.getPosition().x + (p1.previousPosition.x - p1.sprite.getPosition().x) * collisionBounceConstant,
        p1.sprite.getPosition().y - (p1.sprite.getPosition().y - p1.previousPosition.y) * collisionBounceConstant};
        p2.previousPosition = {p2.sprite.getPosition().x + (p2.previousPosition.x - p2.sprite.getPosition().x) * collisionBounceConstant,
        p2.sprite.getPosition().y - (p2.sprite.getPosition().y - p2.previousPosition.y) * collisionBounceConstant};
    }

    return {p1, p2};
}
vector<Particle> naiiveCollision(vector<Particle> particles) {
    for (int i = 0; i < particles.size(); ++i) {
        for (int j = 0; j < particles.size(); ++j) {
            if (i == j) continue;
            vector<Particle> parts = collisionFix(particles[i], particles[j]);
            particles[i] = parts[0];
            particles[j] = parts[1];
        }
    }

    return particles;
}
