//
//  Beam.hpp
//  invader
//
//  Created by nakamura on 2024/01/16.
//

#ifndef Beam_hpp
#define Beam_hpp

#include <stdio.h>
#include "Object.hpp"
#include "component/DrawComponent.hpp"

class Beam : public Object {
public:
    Beam(int x, int y);
    int velocity;
    void Update(float deltaTime);
    DrawComponent* dc;
//    AudioComponent* oc;
};

    
#endif /* Beam_hpp */
