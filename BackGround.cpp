//
//  BackGround.cpp
//  invader
//
//  Created by nakamura on 2024/01/21.
//

#include "BackGround.hpp"
BackGround::BackGround() {
    dc = new DrawComponent(this, "/Users/nakamura/Program/C++/invader/invader/image/backGround.png");
    scale = 1;
}
