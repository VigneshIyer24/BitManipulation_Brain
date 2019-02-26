/* Created by Vignesh Iyer

Bit Manipulation using basic C functions
Date: 23th February, 2019

*/


#include<stdio.h>
#include<stdlib.h>
#include "message.h"


typedef enum
{
	ERROR=-1,	//Returns -1 for error in writing or reading
	SUCCESS=0,	//Returns 0 on success
	WRITE=1	//Will return 1 when writing is in progress
}msg_type;

typedef struct message_data
{

	uint8_t packet_id;
	uint8_t message_type;
	uint16_t message_length;
	uint32_t message_data0;
	uint32_t message_data1;



}Message_data;

struct motor_msg
{
	float forward_back[4];
	float left_right[4];
};

void update_motor(Message_data data);
void display_message(u_int16_t *data);

msg_type distinguish(uint8_t packet[])
{

	Message_data send_data;
	struct motor_msg motor_data;
	send_data.packet_id=packet[0];
	send_data.message_type=packet[1];
	send_data.message_length=packet[2];
	send_data.message_length|=(packet[3]<<8);//bitwise leftshift by 8 points
	send_data.message_data0=((packet[7]<<24)|(packet[6]<<16)|(packet[5]<<8)|(packet[4]));
	send_data.message_data1=((packet[12]<<24)|(packet[10]<<16)|(packet[9]<<8)|(packet[8]));

	
	if(send_data.message_type=MOTOR)
	{

		update_motor(send_data);
		return SUCCESS;
	}


        if(send_data.message_type=DISPLAY)
        {

                display_message(&send_data.message_length);
		return SUCCESS;
        }
	else
	{
		return ERROR;
	}
}
 

