/**
* @file defines.h
* @brief defines
* common definitions
*
* @author Claudio Neto
*
* @date 3/11/2015
*/

#ifndef DEFINES_H_
#define DEFINES_H_

#define MAX_MSG_LEN 1024
#define SRV_PORT 6423
#define SRV_ADDR "127.0.0.1"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/**
 * true - false enum
 */
typedef enum {
	true,//!< true
	false//!< false
} eBool;

/**
 * request types
 */
typedef enum {
	configure,//!< generate configuration xml
	retrieve, //!< retrieve data
	update    //!< update data
} eRequest;

/**
 * brightness levels
 */
typedef enum {
	dark,                //!< dark
	average,             //!< average
	bright,              //!< bright
	max_brightness_levels//!< max_brightness_levels
}  eBrightness;

/**
 * the various mock sensors
 */
typedef enum {
	battery,      //!< battery
	brightness,   //!< brightness
	humidity,     //!< humidity
	noise,        //!< noise
	personsPassed,//!< personsPassed
	temperature,  //!< temperature
	max_sensors   //!< max_sensors
} eSensor;

/**
 *
 */
typedef struct {
	int value;
	int elapsed;
	int interval;

} Reading_t;

extern const char const* request_str[];
extern const char const* brightness_str[];
extern const char const* sensor_str[];

#endif /* DEFINES_H_ */
