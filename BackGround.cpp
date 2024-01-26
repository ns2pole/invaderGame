//
//  BackGround.cpp
//  invader
//
//  Created by nakamura on 2024/01/21.
//

#include "BackGround.hpp"
BackGround::BackGround() {
    imageURL = "/Users/nakamura/Program/C++/invader/invader/image/backGround.png";
    dc = new DrawComponent(this);
    scale = 1;
}
