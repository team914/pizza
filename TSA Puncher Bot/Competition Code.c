#pragma config(Sensor, in1,    autonPot,       sensorPotentiometer)
#pragma config(Sensor, in2,    platPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEnc,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEnc,        sensorQuadEncoder)
#pragma config(Motor,  port1,           intake,        tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           puncher,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontRight,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           midRight,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           backRight,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           adjuster,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontLeft,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           midLeft,       tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backLeft,      tmotorVex393HighSpeed_HBridge, openLoop, reversed)
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
#include "Auton PID.c"

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

	SensorValue(rightEnc) = 0;
	SensorValue(leftEnc) = 0;
	startTask(pid);
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

// Auton Functions
void redNorth()
{
	if (platPot == true)
	{


		// move forward 10 inches

		while(SensorValue(rightEnc) < 500)
		{
			rotateLeft(); // 90 degrees
		}
		stopDrive();

		shoot();
		intakeIn();
		pUp();
		stopAllMotors();
		shoot();

		while(SensorValue(rightEnc) < 1500)
		{
			moveForward(); // 50 inches
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		while(SensorValue(rightEnc) > -1000)
		{
			moveBack(); // 27 inches
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		while(SensorValue(rightEnc) < 500)
		{
			rotateLeft(); // 90 degrees
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		// move forward 11 inches

		//scraper down

		while(SensorValue(rightEnc) > -100)
		{
			moveBack(); // 6 inches
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		intakeIn();
		wait1Msec(1000);

		while(SensorValue(rightEnc) < 3000)
		{
			moveForward(); // 41 inches
			intakeIn();
		}
		stopAllMotors();
		SensorValue(rightEnc) = 0;

		while(SensorValue(rightEnc) < 500)
		{
			rotateRight(); // 90 degrees
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		shoot();
		intakeIn();
		pDown();
		stopAllMotors();
		shoot();

		/***** RECODE ******/
		while(SensorValue(rightEnc) > -200)
		{
			moveBack();
			intakeIn();
		}
		stopAllMotors();
		SensorValue(rightEnc) = 0;

		// scraper up

		while(SensorValue(rightEnc) > -1000)
		{
			rotateRight();
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		shoot();
		pDown();
		wait1Msec(500);

		while(SensorValue(rightEnc) < 1000)
		{
			rotateLeft();
			intakeIn();
		}
		stopAllMotors();
		SensorValue(rightEnc) = 0;

		while(SensorValue(rightEnc) < 3000)
		{
			moveForward();
			intakeOut();
		}
		stopAllMotors();
		SensorValue(rightEnc) = 0;

		intakeIn();

		while(SensorValue(rightEnc) > -100)
		{
			moveBack();
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		while(SensorValue(rightEnc) > -500)
		{
			rotateRight();
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		shoot();

		while(SensorValue(rightEnc) < 1000)
		{
			moveForward();
		}
		stopAllMotors();
		SensorValue(rightEnc) = 0;

		while(SensorValue(rightEnc) > -1000)
		{
			moveBack();
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		shoot();
		pUp();
		wait1Msec(500);

		// Park on platform and shoot middle top flag
		while(SensorValue(rightEnc) > -2000)
		{
			moveBack();
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		while(SensorValue(rightEnc) > -500)
		{
			rotateRight();
		}
		stopDrive();
		SensorValue(rightEnc) = 0;

		while(SensorValue(rightEnc) > -1000)
		{
			moveBack();
		}
		stopDrive();
		SensorValue(rightEnc) = 0;


		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate right 15-25 degrees
		// move forward
		// rotate left
		// pup
		// shoot
	}
	else
	{
		// move back
		// move forward
		// roll intake in
		// rotate left 30 - 45 degrees
		// shoot
		// roll intake in
		// pup
		// shoot
		// pdown
		// move forward
		// rotate left
		// move forward
		// move back
		// rotate left
		// move forward
		// scraper down
		// move forward
		// intake out
		// scraper up
		// intake in
		// move forward
		// move back
		// rotate right
		// shoot
		// intake in
		// pup
		// shoot
		// pdown
		// move forward

		// Get in a good position for driver and try shooting middle flags
		// intake in
		// move back
		// rotate right 30 - 45 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// intake in
	}
}

void redSouth()
{
	if (platPot == false)
	{
		// move forward
		// intake in
		// rotate left 45 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// pdown
		// rotate right 45 degrees
		// move back
		// rotate right
		// move forward
		// rotate left
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate left ~50 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// rotate right ~50 degrees
		// move forward
		// intake out
		// move back
		// rotate left
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate left 45 degrees
		// shoot
		// pdown

		// Park on platform
		// move back
		// rotate right 45 degrees
		// move back
		// move forward
	}
	else
	{
		// move forward
		// intake in
		// rotate left 45 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// pdown
		// rotate right 45 degrees
		// move back
		// rotate right
		// move forward
		// rotate left
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate left ~50 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// rotate right ~50 degrees
		// move forward
		// intake out
		// move back
		// rotate left
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate left 45 degrees
		// shoot
		// pdown

		// Get in a good position for driver
		// move back
		// rotate right ~135 degrees
	}
}

void blueNorth()
{
	if (platPot == false)
	{
		// move back
		// move forward
		// roll intake in
		// rotate right 30 - 45 degrees
		// shoot
		// roll intake in
		// pup
		// shoot
		// pdown
		// move forward
		// rotate right
		// move forward
		// move back
		// rotate right
		// move forward
		// scraper down
		// move forward
		// intake out
		// scraper up
		// intake in
		// move forward
		// move back
		// rotate left
		// shoot
		// roll intake in
		// pup
		// shoot
		// pdown
		// move forward

		// Park on platform and shoot middle top flag
		// move back
		// rotate left
		// move back
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate left 15-25 degrees
		// move forward
		// rotate right
		// pup
		// shoot
	}
	else
	{
		// move back
		// move forward
		// roll intake in
		// rotate right 30 - 45 degrees
		// shoot
		// roll intake in
		// pup
		// shoot
		// pdown
		// move forward
		// rotate right
		// move forward
		// move back
		// rotate right
		// move forward
		// scraper down
		// move forward
		// intake out
		// scraper up
		// intake in
		// move forward
		// move back
		// rotate left
		// shoot
		// roll intake in
		// pup
		// shoot
		// pdown
		// move forward

		// Get in a good position for driver and  try shooting middle flags
		// intake in
		// move back
		// rotate left 30 - 45 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// intake in
	}
}

void blueSouth()
{
	if (platPot == false)
	{
		// move forward
		// intake in
		// rotate right 45 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// pdown
		// rotate left 45 degrees
		// move back
		// rotate left
		// move forward
		// rotate right
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate right ~50 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// rotate left ~50 degrees
		// move forward
		// intake out
		// move back
		// rotate right
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate right 45 degrees
		// shoot
		// pdown

		// Park on platform
		// move back
		// rotate left 45 degrees
		// move back
		// move forward
	}
	else
	{
		// move forward
		// intake in
		// rotate right 45 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// pdown
		// rotate left 45 degrees
		// move back
		// rotate left
		// move forward
		// rotate right
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate right ~50 degrees
		// shoot
		// intake in
		// pup
		// shoot
		// rotate left ~50 degrees
		// move forward
		// intake out
		// move back
		// rotate right
		// move forward
		// scraper down
		// move back
		// intake in
		// scraper up
		// rotate right 45 degrees
		// shoot
		// pdown

		// Get in a good position for driver
		// move back
		// rotate left ~135 degrees
	}
}

// Just in case no auton is selected
void failSafe()
{
	// Keep this function blank
}

task autonomous()
{
	// Choose Auton
	if (autonPot == false)
	{
		blueNorth();
	}
	else if (false)
	{
		blueSouth();
	}
	else if (true)
	{
		redNorth();
	}
	else if (false)
	{
		redSouth();
	}
	else
	{
		failSafe();
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

// Included files
#include "Deadzone Drive.c";

task usercontrol()
{
	while (true)
	{
		// Starts tasks from Deadzone Drive.c
		startTask (rightDrive);
		startTask (leftDrive);

		if (vexRT(Btn8D) == 1)
		{
			motor[lift] = 127;
		}
		else if (vexRT(Btn7D) == 1)
		{
			motor[lift] = -127;
		}
		else
		{
			motor[lift] = 0;
		}

		if (vexRT(Btn5U) == 1)
		{
			motor[intake] = 127;
		}
		else if (vexRT(Btn5D) == 1)
		{
			motor[intake] = -127;
		}
		else
		{
			motor[intake] = 0;
		}

		if (vexRT(Btn6U) == 1)
		{
			motor[puncher] = 127;
		}
		else
		{
			motor[puncher] = 0;
		}

		if (vexRT(Btn8U) == 1)
		{
			motor[adjuster] = 127;
		}
		else if (vexRT(Btn8D) == 1)
		{
			motor[adjuster] = -127;
		}
		else
		{
			motor[adjuster] = 0;
		}
	}
}
