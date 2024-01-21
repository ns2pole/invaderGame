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

class Beam : public Object {
    public:
        Beam(int x, int y);
        int width;
        int length;
        int velocity;
        void Update(float deltaTime);
};

    
#endif /* Beam_hpp */
