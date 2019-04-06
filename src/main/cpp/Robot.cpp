/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

void Robot::AutonomousPeriodic() {
    PlayerControl();
}

void Robot::TeleopPeriodic() {
    PlayerControl();
}

void Robot::PlayerControl() {
    
    hatch.Set(Controller.GetRawButton(4));
    bucket.Set(Controller.GetRawButton(1));
    
    DiffDrive.ArcadeDrive(Controller.GetThrottle(), Controller.GetY());
    
    if(Controller.GetRawButtonPressed(/*WhatButton*/3)) {
        cameraView = !cameraView;
        speedScale = speedScale * -1;
        sinkCam.SetSource(cameraView ? frontCam : backCam);
    }

}

int main() { return frc::StartRobot<Robot>(); }