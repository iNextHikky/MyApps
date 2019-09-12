/*
 ============================================================================
 Name        : GPA_cal.c
 Author      : K.M
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDNUMBER 9

int main(){
	FILE *fp;
	char id[IDNUMBER+1];
	char filename[4+IDNUMBER+4];
	printf("Tell me your student ID number.\n");
	fgets(id, IDNUMBER, stdin);
	sprintf(filename, "%s%s%s", "SIRS", id, ".csv");
	char *fname = filename;
//	char *fname = "SIRSB17T2100B.csv";
	char buf[3];
	char empty[30];
	double sum = 0.0;
	int ave = 0;
	int ret;

	fp = fopen(fname, "r");
	if(fp == NULL){
		printf("%s can't open.\n", fname);
		exit(EXIT_FAILURE);
	}
	while((ret = fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],", empty, empty, empty, empty, empty, empty, buf,empty)
) != EOF){
		switch(buf[1]){
			case 'A':
				sum += 4;
				break;
			case 'B':
				sum += 3;
				break;
			case 'C':
				sum += 2;
				break;
			case 'D':
				sum += 1;
				break;
			default:
				;
		}
		ave++;
	}
	ave = sum / ave;
	puts(ave);
	return 0;
}
