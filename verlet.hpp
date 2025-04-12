
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

Vector2f gravity = {0.f, 0.1f};

int scrw = 800;
int scrh = 450;

int particleRadius = 15.f;

float bounceDampeningConstant = 0.8f;
float collisionBounceConstant = 0.3f;