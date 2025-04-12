#include "collisionSolver.hpp"
#include <algorithm>

int main() {
    RenderWindow screen(VideoMode(scrw, scrh), "Verlet MK2");
    // create the window for the simulation to be displayed on

    srand(time(NULL));
    // seed the rng

    vector<Particle> particles(10);

    while (true) {
        Event event;
        while (screen.pollEvent(event)) {
            if (event.type == Event::Closed)
                // Close app
                screen.close();
        }

        screen.clear();

        particles = naiiveCollision(particles);

        for (Particle& p : particles) {
            p.updateVerlet(gravity);
        }

        for (Particle& p : particles) {
            screen.draw(p.sprite);
        }
        

        screen.display();
        sleep(milliseconds(16));

    }

    return 0;
}