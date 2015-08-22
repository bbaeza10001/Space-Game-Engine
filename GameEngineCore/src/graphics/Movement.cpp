#include "Movement.h"

float input::moveRight(float x){
		x += 0.05f;
	
	return x;
}

float input::moveLeft(float x){
		x -= 0.05f;
	
	return x;
}

float input::moveUp(float y){
		y -= 0.05f;

	return y;
}

float input::moveDown(float y){
		y += 0.05f;

	return y;
}

float input::driftRight(float x){
		x += 0.00125f;

	return x;
}

float input::driftLeft(float x){
		x -= 0.00125f;

	return x;
}

float input::driftUp(float y){
		y += 0.00125f;

	return y;
}

float input::driftDown(float y){
		y -= 0.00125f;

	return y;
}

float input::makeX(float& x){
		x = (x / 400.0f) - 1;

	return x;
}

float input::makeY(float& y){
		y = (y / -300.0f) + 1;

	return y;
}



