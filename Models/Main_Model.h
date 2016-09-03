#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "../config.h"

void get_content(char * file);
int check_file(char * file ,char search[1024]);
std::string get_file_value(char * file, char search[1024], int pos, int array[], int count);