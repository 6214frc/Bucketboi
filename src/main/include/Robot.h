#pragma once

#include <frc/Spark.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/TimedRobot.h>
#include <frc/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>
#include <cameraserver/CameraServer.h>

class Robot : public frc::TimedRobot
{
public:
  void PlayerControl();
  void TeleopPeriodic() override;
  void AutonomousPeriodic() override;

private:                         //Modify Me!
  double speedScale = 1.0;       //Robot Speed Multiplier
  bool cameraView = false;       //Either front or back Camera view; change this to change default camera view
  double speedScalingFactor = 6; //Higher = Slower acceleration; Lower = faster; 1 = fastest. Multiples of 2 Ideally

  frc::Solenoid L2Lift{2}; //Second Level Climb. Barely works
  frc::Solenoid hatch{3};  //Push off hatches from velcro
  frc::Solenoid bucket{0}; //Launch Balls up and into goals

  //Left and Right GetRawAxies values
  const int LeftJoystickY = 1;
  const int RightJoystickY = 4;

  frc::Joystick controller{0};
  frc::PWMVictorSPX leftDT{0};
  frc::PWMVictorSPX rightDT{1};

  frc::DifferentialDrive DiffDrive{leftDT, rightDT};

  //Cameras, including a sink that retrieves camera data from either the front or back
  cs::VideoSink sinkCam = frc::CameraServer::GetInstance()->GetServer();
  cs::UsbCamera backCam = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
  cs::UsbCamera frontCam = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);

  //Don't modify these
  double speedLeft = 0, previousLeftSpeed = 0;
  double speedRight = 0, previousRightSpeed = 0;
};
