// CATAPULT VARIABLES
int cocksBack;
int shootFwd;
int rightEncVal;
int leftEncVal;
int encValDiff;
float encDiffRatio;

// UPDATE CATAPULT VARIABLES
void catVariables()
{
	shootFwd = vexRT[Btn6U];
	cocksBack = vexRT[Btn5U];
	rightEncVal = SensorValue[rightEncoder];
	leftEncVal = -(SensorValue[leftEncoder]);
	encValDiff = abs(rightEncVal - leftEncVal); //deadzone
	encDiffRatio = (1 + (encValDiff/360));
}

void updateRightCatMotors(int Speed)
{
	motor[top_right_cat] = Speed;
	motor[bot_right_cat] = -Speed;
}

void updateLeftCatMotors(int Speed)
{
	motor[bot_left_cat] = -Speed;
	motor[top_left_cat] = -Speed;
}

// This function is essentially a shortcut for our catapult code.
// It sets the motors all to the same speed, so once the function
// is used elsewhere, all motors move at the same directed speed.
void updateCatMotors(int Speed)
{
	updateRightCatMotors(Speed);
	updateLeftCatMotors(Speed);
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
		updateCatMotors(-100);
	}
	else if(shootFwd == 1)
	{
		updateCatMotors(100);
	}
	else
	{
		updateCatMotors(0);
	}
}

void adjustCatapult()
{
	if(encValDiff > 20)
	{
		if(rightEncVal < leftEncVal)
		{
			updateLeftCatMotors(100);
			updateRightCatMotors(100*encDiffRatio);
		}
		else
		{
			updateLeftCatMotors(100*encDiffRatio);
			updateRightCatMotors(100);
		}
	}
	else
	{
		catapult();
	}
}
