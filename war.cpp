#include <iostream>
#include "math2.h"
#include <fstream>
#include <time.h>

using namespace std;

#define gravity 9.807
#define ballRadius 0.6
int rand();
void start(){
	cout << endl << "Welcome to Artillery" << endl;
	cout << "You are in the middle of a war and surrouded by many enemies" << endl << endl;
	cout << "You have one cannon to shoot" << endl;
	cout << "Here, the gravity is 9.807m*s^-2" << endl;
	cout << "And the radius of your cannonball is " << to_string(ballRadius) << " meters" << endl;
	cout << "Your task is to control the cannon at the right angle AND velocity so it hits an enemy" << endl << endl;
}
int seeEnemy(){
	int distance;
	srand (time(NULL));
	distance = rand()%300 + 100;
	cout << "I see an enemy " << to_string(distance) << "m away" << endl;
	return distance;
}
int shoot(int d1){
	double angle, velocity;
	cout << "Shoot at what angle? (in degrees)" << endl;
	double a;
	cin >> a;
	angle = a/180*π;
	cout << "Shoot at what speed?" << endl;
	cin >> velocity;
	double d2 = calculateDistance(gravity, angle, velocity);
	cout << endl << "Your cannonball landed " << to_string(d2) << "m away" << endl;
	cout << endl << "the enemy is " << to_string(d1) << "m away" << endl << endl;
	if(abs(d1-d2) < ballRadius){
		cout << "You killed the enemy" << endl << endl;
		return true;
	}
	else{
		cout << "You didn't kill the enemy, try again" << endl << endl;
		return false;
	}
}

int main(){
	int killed = 0, dd = 0, playAgain = 0;
	start();
	do{
		dd = seeEnemy();
		int ff = false;
		do {
			ff = shoot(dd);
			if(ff){++killed;}
		} while (ff == false);
		cout << endl << "I see another enemy, are you ready? (y/n) "<< endl;
		string s;
		cin >> s;
		if(s == "n"){playAgain = 0;}else{playAgain = 1;}
	} while(playAgain);
	cout << "You have killed " << to_string(killed) << " enemies." << endl;
	return 0;
}