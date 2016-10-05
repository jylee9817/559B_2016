// CATAPULT VARIABLES
int cocksBack;
int shootFwd;
int rightEncVal;
int leftEncVal;
int encValDiff;

// UPDATE CATAPULT VARIABLES
void catVariables()
{
	shootFwd = vexRT[Btn5U];
	cocksBack = vexRT[Btn6U];
	rightEncVal = SensorValue[rightEncoder];
	leftEncVal = SensorValue[leftEncoder];
	encValDiff = abs((rightEncVal - leftEncVal));
}

// This function is essentially a shortcut for our catapult code.
// It sets the motors all to the same speed, so once the function
// is used elsewhere, all motors move at the same directed speed.
void updateCatMotors(int leftSpeed, int rightSpeed)
{
	motor[top_left_cat] = -leftSpeed;
	motor[top_right_cat] = rightSpeed;
	motor[bot_left_cat] = -leftSpeed;
	motor[bot_right_cat] = -rightSpeed;
}

void adjustCatapult(int positive)
{
	if((encValDiff > 5) && (rightEncVal < leftEncVal))
	{
		updateCatMotors(positive*90,positive*100);
	}
	else if((encValDiff > 5) && (rightEncVal > leftEncVal))
	{
		updateCatMotors(positive*100,positive*90);
	}
	else
	{
		updateCatMotors(positive*100,positive*100);
	}
}

// This is the actual code for the catapult. It checks if a button
// is pressed (cocksBack or shootFwd), then acts accordingly. If
// it cocks back, then the motors all move at a speed of 100; if
// it shoots forward, all motors move at a speed of -100. If
// nothing is pressed, the catapult motors do not move.
void catapult()
{
	if(cocksBack == 1)
	{
		adjustCatapult(-1);
	}
	else if(shootFwd == 1)
	{
		adjustCatapult(1);
	}
	else
	{
		updateCatMotors(0,0);
	}
}
