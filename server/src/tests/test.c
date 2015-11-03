/*
 * test.c
 *
 *  Created on: Oct 25, 2015
 *      Author: strikles
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "unity.h"
#include "ezxml.h"

#include "defines.h"
#include "test.h"
#include "xml.h"


int retrieve_all_test() {

	char sendline[MAX_MSG_LEN];
	char recvline[] = "<retrieve\\>";

	int expected = buildReplyXML(recvline, sendline, strlen(sendline));
	TEST_ASSERT_MESSAGE( expected == 1, "self closing tags are valid" );

	return 0;
}

int invalidXML_test()
{
	char sendline[MAX_MSG_LEN];
	char recvline[] = "<update>"
	" <temperature>10</temperature>"
	"</updat";

	int expected = buildReplyXML(recvline, sendline, strlen(sendline));
	TEST_ASSERT_MESSAGE( expected == 0, "our request is invalid" );

	return 0;
}

int invalidProperty_test()
{
	char sendline[MAX_MSG_LEN];
	char recvline[] = "<update>"
	" <bananas>10</bananas>"
	"</update>";

	int expected = buildReplyXML(recvline, sendline, strlen(sendline));
	TEST_ASSERT_MESSAGE( expected == 0, "property requested is invalid" );

	return 0;
}

int xml_test()
{
	//retrieve_all_test();
	invalidXML_test();
	invalidProperty_test();

	return 0;
}
