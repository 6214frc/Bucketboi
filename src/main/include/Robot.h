#pragma once

#include <frc/Spark.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/TimedRobot.h>
#include <frc/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>
#include <cameraserver/CameraServer.h>

class Robot : public frc::TimedRobot {
 public:
  void PlayerControl();
  void TeleopPeriodic() override;
  void AutonomousPeriodic() override;

 private:
  frc::Joystick Controller{0};
  frc::PWMVictorSPX leftDT{0};
  frc::PWMVictorSPX rightDT{1};

  frc::DifferentialDrive DiffDrive{leftDT, rightDT};

  cs::VideoSink sinkCam = frc::CameraServer::GetInstance()->GetServer();
  cs::UsbCamera backCam = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
   cs::UsbCamera frontCam = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
  

  double speedScale = 1;
  bool cameraView = false;

  frc::Solenoid bucket{0};
  frc::Solenoid hatch{3};
};
