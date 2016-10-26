#include "Drive.h"
#include "Catapult.h"

void Strafe(int speed)
{
	motor[front_right_drive] = speed;
	motor[front_left_drive] = -speed;
	motor[back_left_drive] = speed;
	motor[back_right_drive] = -speed;
}

void auto1()//ask Amy for the exact values
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	updateDriveMotors(127,127);
	wait1Msec(450);
	updateDriveMotors(0,0);
	wait1Msec(200);

	updateCatMotors(100);
	wait1Msec(1200);
	updateCatMotors(0);
	wait1Msec(500);

	Strafe(-127);
	wait1Msec(1500);
	Strafe(0);
	wait1Msec(200);

	Strafe(127);
	wait1Msec(200);
	Strafe(0);
	wait1Msec(200);

	updateDriveMotors(127,127);
	wait1Msec(350);
	updateDriveMotors(0,0);
	wait1Msec(200);

	Strafe(127);
	wait1Msec(3000);
	Strafe(0);
}
