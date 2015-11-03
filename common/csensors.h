/**
 * @file sensors.h
 * @brief mock sensors
 * common mock sensors definitions
 *
 * @author Claudio Neto
 *
 * @date 3/11/2015
 */
#ifndef SENSORS_H_
#define SENSORS_H_

#include <stdint.h>

#include "cdefines.h"

/**
 * helper - gets a measurement
 * @param s
 * @param buffer
 * @return invalid_status
 */
uint16_t getSensorReadingStr(eSensor s, char buffer[]);

/**
 * helper - sets a random measurement value
 * @param s
 * @return invalid_status
 */
int newMeasurement(eSensor s);

/**
 * helper - loop to generate measurements
 * @return invalid_status
 */
uint16_t generateMeasurements(void);

#endif /* SENSORS_H_ */
