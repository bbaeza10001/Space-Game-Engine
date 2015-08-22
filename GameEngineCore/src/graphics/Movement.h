#pragma once
#include <vector>

using namespace std;

struct input{
	//Movement

	float moveRight(float x);
	float moveLeft(float x);
	float moveUp(float y);
	float moveDown(float y);

	float driftRight(float x);
	float driftLeft(float x);
	float driftUp(float y);
	float driftDown(float y);

	//Location
	float makeX(float&);
	float makeY(float&);

};
