/*******************************************************************
    Copyright (C) 2009 FreakLabs
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.

    Originally written by Christopher Wang aka Akiba.
    Please post support questions to the FreakLabs forum.

*******************************************************************/
/*!
    \file
    \ingroup


*/
/**************************************************************************/
#ifndef CMD_H
#define CMD_H

// ===============================================

#define __EXTRAS__ //? added help cpmmand
                   // runtime steam redirection
#ifdef __EXTRAS__
void cmdRedirect(Stream *str);
//#define __ADDRESS__ "1314"
float parse_float(int , char **);
 
#endif

#ifndef __ADDRESS__
 #define __INIT__ECHO true
#else
 #define __INIT__ECHO false
#endif


// ===============================================


#define MAX_MSG_SIZE    60
#include <stdint.h>
#include <Arduino.h>

// command line structure
typedef struct _cmd_t
{
    char *cmd;
    void (*func)(int argc, char **argv);
    struct _cmd_t *next;
} cmd_t;

void cmdInit(Stream *);
void cmdPoll();
void cmdAdd(const char *name, void (*func)(int argc, char **argv));
Stream* cmdGetStream(void);
uint32_t cmdStr2Num(char *str, uint8_t base);



#endif //CMD_H
