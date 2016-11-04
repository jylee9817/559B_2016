//New Drive Variables
int forward;
int turn;
int newStrafe;

int driveY;
int driveX;
int strafe;

int DEADZONE = 15;

// UPDATING DRIVE VARIABLES
void driveVariables()
{
	driveY = vexRT[Ch3];
	driveX = vexRT[Ch1];
	strafe = vexRT[Ch4];
}

//new drive
int setForward(int forVal)
{
	if(abs(forVal) > DEADZONE)
	{
		forward = forVal;
	}
	else
	{
		forward = 0;
	}
	return forward;
}

int setTurn(int turnVal)
{
	if(abs(turnVal) > DEADZONE)
	{
		turn = turnVal;
	}
	else
	{
		turn = 0;
	}
	return turn;
}

int setStrafe(int strafeVal)
{
	if(abs(strafeVal) > DEADZONE)
	{
		newStrafe = strafeVal;
	}
	else
	{
		newStrafe = 0;
	}
	return newStrafe;
}


void newDrive(int forInput, int turnInput, int strafeInput)
{
	setForward(forInput);
	setTurn(turnInput);
	setStrafe(strafeInput);

	motor[front_left_drive] = forward + newStrafe + turn;
	motor[front_right_drive] = forward - newStrafe - turn;
	motor[back_left_drive] = forward - newStrafe + turn;
	motor[back_right_drive] = forward + newStrafe - turn;
}
