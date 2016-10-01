#include "main.h"

/**
 * Initializes a new drive object composed of six PantherMotors, two encoders and a gyro.
 */
Drive initDrive(PantherMotor frontLeftMotor, PantherMotor frontRightMotor,
		PantherMotor rearLeftMotor, PantherMotor rearRightMotor,
		Encoder frontLeftEncoder, Encoder frontRightEncoder,
		Encoder rearLeftEncoder, Encoder rearRightEncoder, Gyro gyro)
{
	Drive newDrive = {frontLeftMotor, frontRightMotor,
			rearLeftMotor, rearRightMotor,
			frontLeftEncoder, frontRightEncoder,
			rearLeftEncoder, rearRightEncoder,
			gyro};

	return newDrive;
}

void tankDrive(Drive drive, int left, int right)
{
	left = limit(left, 127, -127);
	right = limit(right, 127, -127);

	setPantherMotor(drive.frontLeftMotor, left);
	setPantherMotor(drive.rearLeftMotor, right);
	setPantherMotor(drive.frontRightMotor, left);
	setPantherMotor(drive.rearRightMotor, right);
}

void arcadeDrive(Drive drive, int magnitude, int rotation)
{
	int left = magnitude + rotation;
	int right = magnitude - rotation;

	left = limit(left, 127, -127);
	right = limit(right, 127, -127);

	setPantherMotor(drive.frontLeftMotor, left);
	setPantherMotor(drive.rearLeftMotor, right);
	setPantherMotor(drive.frontRightMotor, left);
	setPantherMotor(drive.rearRightMotor, right);
}
