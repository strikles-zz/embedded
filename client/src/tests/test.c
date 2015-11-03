/*
 * test.c
 *
 *  Created on: Oct 25, 2015
 *      Author: strikles
 */

#include "test.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ezxml.h"

void xml_test() {

	char xml_str[] = "<?xml version=\"1.0\"?>"
	"<formula1>"
		"<team name=\"McLaren\">"
			"<driver>"
				"<name>Kimi Raikkonen</name>"
				"<points>112</points>"
			"</driver>"
			"<driver>"
				"<name>Juan Pablo Montoya</name>"
				"<points>60</points>"
			"</driver>"
		"</team>"
	"</formula1>";

	const char *teamname;
	ezxml_t f1 = ezxml_parse_str(xml_str, strlen(xml_str));
	ezxml_t team, driver;

    for (team = ezxml_child(f1, "team"); team; team = team->next)
    {
        teamname = ezxml_attr(team, "name");
        for (driver = ezxml_child(team, "driver"); driver; driver = driver->next)
        {
            printf("%s, %s: %s\n", ezxml_child(driver, "name")->txt, teamname,
                   ezxml_child(driver, "points")->txt);
        }
    }

	ezxml_free(f1);
}
