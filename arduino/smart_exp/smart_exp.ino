// Mario Ciccioni

#include "Scheduler.h"
#include "DetectOperatorTask.h"
#include "DynamicObjectTask.h"
#include "SpeedVisTask.h"
#include "BlinkTask.h"
#include "Pir.h"
#include "Led.h"
#include "Button.h"
#include "Sonar.h"
#include "ServoMotorImpl.h"
#include "TemperatureSensor.h"
#include "Utility.h"
#include "Pot.h"
#include "MsgService.h"

Scheduler scheduler;

void setup() {
  Serial.begin(9600);
  scheduler.init(20);
  MsgService.init();

  Pir* pir = new Pir(2);
  Led* ledRed = new Led(4);
  Led* ledGreen = new Led(5);
  Button* bStart = new Button(12);
  Button* bStop = new Button(3);
  TemperatureSensor* sTemp = new TemperatureSensor();
  Sonar* sonar = new Sonar(7, 8, sTemp);
  ServoMotorImpl* servo = new ServoMotorImpl(11);
  Utility* ut = new Utility(2);
  Potentiometer* pot = new Potentiometer(A0);

  Task* detectOperatorTask = new DetectOperatorTask(pir, ledRed, ledGreen, bStart, bStop, sonar, ut);
  detectOperatorTask->init(20);
  detectOperatorTask->setActive(true);

  Task* dynamicObjectTask = new DynamicObjectTask(sonar, pot);
  dynamicObjectTask->init(20);
  dynamicObjectTask->setActive(true);

  Task* blinkLed = new BlinkTask(4);
  blinkLed->init(40);
  blinkLed->setActive(true);

  Task* speedVisTask = new SpeedVisTask(servo);
  speedVisTask->init(20);
  speedVisTask->setActive(true);

  scheduler.addTask(speedVisTask);
  scheduler.addTask(blinkLed);
  scheduler.addTask(dynamicObjectTask);
  scheduler.addTask(detectOperatorTask);
}

void loop() {
  scheduler.schedule();
}
