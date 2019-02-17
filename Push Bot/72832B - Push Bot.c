#pragma config(Sensor, dgtl1,  rightDrive,     sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftDrive,      sensorQuadEncoder)
#pragma config(Motor,  port1,           mongoLeft,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftDrive1,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftDrive2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftDrive3,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           hDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDrive3,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightDrive2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightDrive1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          mongoRight,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	SensorValue[rightDrive] = 0;
	SensorValue[leftDrive] = 0;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

// Declaring functions for auton
void moveForward()
{
	motor[leftDrive1] = 127;
	motor[leftDrive2] = 127;
	motor[leftDrive3] = 127;
	motor[rightDrive3] = 127;
	motor[rightDrive2] = 127;
	motor[rightDrive1] = 127;
}

// Stop all drive motors
void stopDrive()
{
	motor[leftDrive1] = 0;
	motor[leftDrive2] = 0;
	motor[leftDrive3] = 0;
	motor[rightDrive3] = 0;
	motor[rightDrive2] = 0;
	motor[rightDrive1] = 0;
}

void rotateLeft()
{
	motor[leftDrive1] = -127;
	motor[leftDrive2] = -127;
	motor[leftDrive3] = -127;
	motor[rightDrive3] = 127;
	motor[rightDrive2] = 127;
	motor[rightDrive1] = 127;
}

void rotateRight()
{
	motor[leftDrive1] = 127;
	motor[leftDrive2] = 127;
	motor[leftDrive3] = 127;
	motor[rightDrive3] = -127;
	motor[rightDrive2] = -127;
	motor[rightDrive1] = -127;
}

void moveBackward()
{
	motor[leftDrive1] = -127;
	motor[leftDrive2] = -127;
	motor[leftDrive3] = -127;
	motor[rightDrive3] = -127;
	motor[rightDrive2] = -127;
	motor[rightDrive1] = -127;
}

void mongoUp()
{
	motor[mongoRight] = 127;
	motor[mongoLeft] = 127;
}

void mongoDown()
{
	motor[mongoRight] = -127;
	motor[mongoLeft] = -127;
}

// Placeholder platform toggle system
bool platform = false;

void blueFlagSide()
{
	if (platform == true)
	{

	}
	else if (platform == false)
	{

	}
}

void redFlagSide()
{
	if (platform == true)
	{

	}
	else if (platform == false)
	{

	}
}

void blueFarSide()
{
	if (platform == true)
	{

	}
	else if (platform == false)
	{

	}
}

void redFarSide()
{
	if (platform == true)
	{

	}
	else if (platform == false)
	{

	}
}

task autonomous()
{
	// Chooses which auton to run based on where jumper clips/potentiometers are placed
	if (vexRT[dgtl5] != vexRT[dgtl6] == 1)
	{
		blueFlagSide();
	}
	else if (vexRT[dgtl6] != vexRT[dgtl5] == 1)
	{
		redFlagSide();
	}
	else if (vexRT[dgtl6] && vexRT[dgtl5] == 1)
	{
		blueFarSide();
	}
	else if (vexRT[dgtl6] && vexRT[dgtl5] == 0)
	{
		redFarSide();
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// Declaring Variables
	int KpR = 0;
	int errorR = 0;
	int targetLocationR = 0;
	int drivePowerR = 0;
	int KpL = 0;
	int errorL = 0;
	int targetLocationL = 0;
	int drivePowerL = 0;
	bool brakes = false;

	while (true)
	{
		// Drive controls
		if (vexRT(Ch2) > 3 || vexRT(Ch2) < -3)
		{
			motor[rightDrive1] = vexRT[Ch2];
			motor[rightDrive2] = vexRT[Ch2];
			motor[rightDrive3] = vexRT[Ch2];
		}
		if (vexRT(Ch3) > 3 || vexRT(Ch3) < -3)
		{
			motor[leftDrive1] = vexRT[Ch3];
			motor[leftDrive2] = vexRT[Ch3];
			motor[leftDrive3] = vexRT[Ch3];
		}

		// H-Drive controls
		if (vexRT(Ch4) > 3 || vexRT(Ch4) < -3)
		{
			motor[hDrive] = vexRT[Ch4];
		}

		// Six bar controls
		if (vexRT[Btn6U] == 1)
		{
			motor[lift] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[lift] = -127;
		}
		else
		{
			motor[lift] = 0;
		}

		// Four bar controls
		if (vexRT[Btn5U] == 1)
		{
			motor[mongoRight] = 127;
			motor[mongoLeft] = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[mongoRight] = -127;
			motor[mongoLeft] = -127;
		}
		else
		{
			motor[mongoRight] = 0;
			motor[mongoLeft] = 0;
		}

		// PID Parking Brake
		if (vexRT[Btn8D] == 1)
		{
			brakes = !brakes;
			targetLocationR = SensorValue[rightDrive];
			targetLocationL = SensorValue[leftDrive];
		}

		while (brakes == true)
		{
			// PID Parking Brake
			if (vexRT[Btn8D] == 1)
			{
				brakes = !brakes;
			}

			// Right side
			// Find error and integrate P into it
			errorR = targetLocationR - abs(SensorValue[rightDrive]);  // Currently just P, we can add on in the future
			drivePowerR = (int)(KpR*errorR);

			// Change drive power accoring to sensor value
			if (errorR > 5)
			{
				while (SensorValue[rightDrive] < targetLocationR)
				{
					motor[rightDrive1] = drivePowerR;
					motor[rightDrive2] = drivePowerR;
					motor[rightDrive3] = drivePowerR;
				}
				while (SensorValue[rightDrive] > targetLocationR)
				{
					motor[rightDrive1] = drivePowerR;
					motor[rightDrive2] = drivePowerR;
					motor[rightDrive3] = drivePowerR;
				}
			}
			// Left side
			// Find error and integrate P into it
			errorL = targetLocationL - abs(SensorValue[leftDrive]);   // Currently just P, we can add on in the future
			drivePowerL = (int)(KpL*errorL);

			// Change drive power accoring to sensor value
			if (errorL > 5)
			{
				while (SensorValue[leftDrive] < targetLocationL)
				{
					motor[leftDrive1] = drivePowerL;
					motor[leftDrive2] = drivePowerL;
					motor[leftDrive3] = drivePowerL;
				}
				while (SensorValue[rightDrive] > targetLocationL)
				{
					motor[leftDrive1] = drivePowerL;
					motor[leftDrive2] = drivePowerL;
					motor[leftDrive3] = drivePowerL;
				}
			}
		}
	}
}
