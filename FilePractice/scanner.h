#pragma once
/************************************************************************
*file: scanner.h
*purpose: declarations for argz functions, types, constants
*author: sentimental
*written: 10/11/2019
*last modified: 11/11/2019
*************************************************************************/
#ifndef _SCANNER_H
#define _SCANNER_H
#include <stddef.h> // for  size_t
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

typedef struct {
	int id;//унікальний ідентифікатор
	char manufacturer[127];// виготовлювач
	char model[127];// найменування моделі
	int year;	 // рік виготовлення
	double price;// ціна
	int x_size;// горизонтальний розмір області сканування
	int y_size;// вертикальний розмір області сканування
} SCAN_INFO;

typedef struct {
	int rec_nmb;//number of records
	SCAN_INFO* recs;//records 
}RECORD_SET;

void create_db(const char* , const char* );
void print_db(const char* );
int make_index(const char* , const char* );
void reindex(const char*);
void add_scanner(const char* , const char* );
void del_scanner(const char* db, int id);
RECORD_SET* get_recs_by_index(const char* , char* );
RECORD_SET* select(const char* , const char* , const char* );
void print_rec_set(RECORD_SET* );
size_t array_unique(char** , size_t sze);
#endif