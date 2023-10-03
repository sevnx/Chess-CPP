#include <iostream>
#include "src/Position.h"
#include <functional>

bool assertThrows(const std::function<void()>& func){
    try{
        func();
    }catch(std::invalid_argument& e){
        return true;
    }
    return false;
}

void testPosition(){
    assertThrows([]{Position p(9, 0);});
}

int main(){
    testPosition();
    return 0;
}
