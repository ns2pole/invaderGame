//
//  Component.hpp
//  invader
//
//  Created by nakamura on 2024/01/26.
//

#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include "Object.hpp"

class Component {
    public:
        Object* owner;
        Component(Object* owner);
};
#endif /* Component_hpp */
