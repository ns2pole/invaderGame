//
//  Beam.cpp
//  invader
//
//  Created by nakamura on 2024/01/16.
//

#include "Beam.hpp"
#include "Ship.hpp"

Beam::Beam(int xx, int yy) {
    x = xx;
    y = yy;
    width = 10;
    height = 35;
    velocity = 300;
    scale = 0.05;
    dc = new DrawComponent(this, "/Users/nakamura/Program/C++/invader/invader/image/beam.png");
    ac = new AudioComponent(this, "/Users/nakamura/Program/C++/invader/invader/audio/beam.wav");
}

void Beam::Update(float deltaTime){
    y -= velocity * deltaTime;
}
