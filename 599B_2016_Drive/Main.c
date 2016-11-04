#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           front_left_drive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           front_right_drive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           back_left_drive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          back_right_drive, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   // Main competition background code provided by ROBOTC for VEX Robotics.
#include "Drive.h"											// Including the Drive file.

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


task autonomous()
{

}


task usercontrol()
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	while (true)
	{
		driveVariables();
		newDrive(driveY, driveX, strafe);
	}
}
