// $Id$
/**
 * @file application.ino
 * @brief Garadget main file
 * @version 1.9
 * @author Denis Grisak
 * @license GPL v3

  This code is firmware for Garadget - cloud-enabled garage door controller.
  For more information please visit http://www.garadget.com/
 */
// $Log$

#include "application.h"
#include "global.h"
#include "door.h"

// Particle platform - product settings
#ifdef ORGMODE
  PRODUCT_ID(PROD_ID);
  PRODUCT_VERSION(VERSION_MAJOR * 100 + VERSION_MINOR);
#endif
STARTUP(WiFi.selectAntenna(ANT_MODE));

c_door o_door;

void setup() {
  #ifdef APPDEBUG
    Serial.begin(115200);
    Serial.println("Setup");
  #endif
  o_door.f_init();
}

void loop() {
  o_door.f_process();
}
