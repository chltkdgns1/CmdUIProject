#pragma once

#include <iostream>
#include <vector>
#include "Object.h"
using namespace std;

class Renderer {
public:
	static void Render() {
		for (auto obj : Object::objMap) {
			obj.second->Render();
		}
	}
};