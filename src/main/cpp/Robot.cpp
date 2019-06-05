#include "Robot.h"

#include <iostream>

void Robot::AutonomousPeriodic()
{
    PlayerControl();
}

void Robot::TeleopPeriodic()
{
    PlayerControl();
}

void Robot::PlayerControl()
{

    //Pneumatic control
    hatch.Set(controller.GetRawButton(4));
    bucket.Set(controller.GetRawButton(1));

    //Toggles the lift
    if (controller.GetRawButtonPressed(2))
    {
        L2Lift.Set(!L2Lift.Get());
    }

    //Tank Drive
    speedLeft += (controller.GetRawAxis(LeftJoystickY) - previousLeftSpeed) / speedScalingFactor;
    speedRight += (controller.GetRawAxis(RightJoystickY) - previousRightSpeed) / speedScalingFactor;

    DiffDrive.TankDrive(speedLeft * speedScale, speedRight * speedScale);

    previousLeftSpeed = speedLeft;
    previousRightSpeed = speedRight;

    //Invert the controls when using the second camera
    if (controller.GetRawButtonPressed(3))
    {
        cameraView = !cameraView;
        speedScale = speedScale * -1;
        sinkCam.SetSource(cameraView ? frontCam : backCam);
    }
}

int main() { return frc::StartRobot<Robot>(); }