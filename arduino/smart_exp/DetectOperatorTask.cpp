#include "DetectOperatorTask.h"
#include "Arduino.h"
#include "MsgService.h"
#include "Config.h"

bool detectedStatus;
bool expStart;
bool expFinish;
unsigned long lt = 0;

DetectOperatorTask::DetectOperatorTask(Pir* pir, Led* ledRed, Led* ledGreen, Button* bStart, Button* bStop, Sonar* sonar, Utility* ut) {
  this->pir = pir;
  this->ledRed = ledRed;
  this->ledGreen = ledGreen;
  this->bStart = bStart;
  this->bStop = bStop;
  this->sonar = sonar;
  this->ut = ut;
}

void DetectOperatorTask::init(int period) {
  Task::init(period);
  pir->calibrate();
  detectedStatus = false;
  expStart = false;
  expFinish = false;
}

void DetectOperatorTask::tick() {
  unsigned long nt = millis();
  
  if (!detectedStatus && ((nt - lt) >= SLEEP_TIME)) {
    MsgService.sendMsg("SLEEP");
    lt = nt;
    ledGreen->switchOff();
    ledRed->switchOff();
    ut->sleep();
  }
  
  if (pir->isDetected() && !bStart->isPressed() && !expStart) {
    ledGreen->switchOn();
    MsgService.sendMsg("IDLE");
  }
  
  if (pir->isDetected() && bStart->isPressed()) {
    MsgService.sendMsg("START");
    detectedStatus = true;
    expStart = true;
    expFinish = true;
    ledGreen->switchOff();
    ledRed->switchOn();
  }

  if (expStart && (bStop->isPressed() || ((nt - lt) >= MAX_TIME))) {
    lt = nt;
    expFinish = true;
    expStart = false;
    detectedStatus = false;
    ledRed->switchOff();
    MsgService.sendMsg("STOP");
    Msg* msg = MsgService.receiveMsg();
    if (msg->getContent() == "ok") {
      Serial.println("IDLE");
    }
    delete msg;
  }
}
