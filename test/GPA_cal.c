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

#define IDNUMBER 10

int main(){
	FILE *fp;
	char id[IDNUMBER+1];
	char filename[4+IDNUMBER+4];
	printf("Tell me your student ID number.\n");
	fgets(id, IDNUMBER, stdin);
	sprintf(filename, "%s%s%s", "SIRS", id, ".csv");
	char *fname = filename;
//	char *fname = "SIRS.csv";
	char buf[30];
	char empty[6][30];
	double sum = 0.0;
	int i = 0;
	double ave = 0;
	int ret;
	puts(filename);
	fp = fopen(fname, "r");
	if(fp == NULL){
		printf("%s can't open.\n", fname);
		exit(EXIT_FAILURE);
	}
	while((ret = fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", empty[0], empty[1], empty[2], empty[3], empty[4], empty[5], buf)) != EOF){
//        puts(buf);
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
//        printf("%lf, %d\n", sum, i);
		i++;
	}
	ave = sum / i;
    printf("%lf\n", ave);
    fclose(fp);
	return 0;
}
