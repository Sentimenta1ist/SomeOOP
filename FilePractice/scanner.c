/************************************************************************
*file: scanner.c
*related files: none
*author: sentimental
*written: 11/11/2019
*last modified: 13/11/2019
************************************************************************/
#include "scanner.h"

//delete duplicate
size_t array_unique(char** arr, size_t size) {
	size_t j, i;
	for (i = 0; i < size; ++i) {
		for (j = i + 1; j < size; ++j) {
			if (!strcmp(arr[j], arr[i])) {
				free(arr[j]);
				arr[j] = arr[--size];
				--j;
			}
		}
	}
	return size;
}
//create db on csv 
void create_db(const char* csv, const char* db) {
	if (csv == NULL)return;
	FILE* csv_file = fopen(csv, "r+");
	FILE* db_file = fopen(db, "wb+");
	SCAN_INFO record;
	if (NULL == csv_file || NULL == db_file) {
		return;
	}
	char str[512];
	int quantity_of_records = 0;
	while (!feof(csv_file)) {
		if (fgets(str, 512, csv_file)) {
			quantity_of_records++;
		}
	}
	rewind(csv_file);
	char** arr = (char**)malloc((quantity_of_records) * sizeof(char*));
	int i = 0;
	while (!feof(csv_file)) {
		if (fgets(str, 512, csv_file)) {
			arr[i] = strdup(str);		// strdup()Returns a pointer to a null-terminated byte
			i++;                        //string, which is a duplicate of the string pointed .
		}                               //to by str
	}
	for (int i = 0; i < quantity_of_records; i++) {
		quantity_of_records = array_unique(arr, quantity_of_records);
		fwrite(&quantity_of_records, sizeof(int), 1, db_file);
		for (i = 0; i < quantity_of_records; i++) {
			record.id = i;
			char* interval = strtok(arr[i], " ;");
			int j = 0;
			while (interval != NULL && j < 6)
			{
				switch (j) {
				case 0: strcpy(record.manufacturer, interval); break;
				case 1: strcpy(record.model, interval); break;
				case 2: record.year = atoi(interval);  break;
				case 3: record.price = atof(interval); break;
				case 4: record.x_size = atoi(interval); break;
				case 5: record.y_size = atoi(interval); break;
				}
				interval = strtok(NULL, ";");
				j++;
			}
			fwrite(&record, sizeof(SCAN_INFO), 1, db_file);
			
		}
		for (int i = 0; i < quantity_of_records; i++) {
			free(arr[i]);
		}
		free(arr);
	}
	//printf("%d",_CrtDumpMemoryLeaks());
	fcloseall();
}

//print binary file in txt
void print_db(const char* db) {
	FILE* db_file = fopen(db, "rb+");
	if (NULL == db_file) return;
	FILE* out = fopen("result.txt", "wb+");
	int quantity_of_records;
	SCAN_INFO record;	
	fread(&quantity_of_records, sizeof(int), 1, db_file);
	fprintf(out, " Quantity of records = %d\n", quantity_of_records);
		while (fread(&record, sizeof(SCAN_INFO), 1, db_file)) {
			fprintf(out, "%d, %s, %s, %d, %.3f, %d, %d\n", record.id, 
				record.manufacturer, record.model,
			record.year, record.price, record.x_size, record.y_size);
		}
	fcloseall();
}

//make index by field(sort)
int make_index(const char* db, const char* field_name) {
	FILE* file = fopen(db, "r");
	if (NULL == file) return 0;
	int quantity_of_records = 0;
	fread(&quantity_of_records, sizeof(int), 1, file);
	SCAN_INFO record;
	char temp[127];
	char** arr = (char**)malloc((quantity_of_records) * sizeof(char*));
	int* arr_id = (int*)malloc((quantity_of_records) * sizeof(int));
	for (int i = 0; i < quantity_of_records; i++) {
		fread(&record, sizeof(SCAN_INFO), 1, file);
		if (field_name == "id") {
			arr[i] = strdup(itoa(record.id,temp,10));
			arr_id[i] = record.id;
		}
		else if (field_name == "manufacturer") {
			arr[i] = strdup(record.manufacturer);
			arr_id[i] = record.id;
		}
		else if (field_name == "model") {
			arr[i] = strdup(record.model);
			arr_id[i] = record.id;
		}
		else if (field_name == "year") {
			arr[i] = strdup(itoa(record.year, temp, 10));
			arr_id[i] = record.id;
		}
		else if (field_name == "price") {
			sprintf(temp, "%.3f", record.price);
			arr[i] = strdup(temp);
			arr_id[i] = record.id;
		}
		else if (field_name == "x_size") {
			arr[i] = strdup(itoa(record.x_size, temp, 10));
			arr_id[i] = record.id;
		}
		else if (field_name == "y_size") {
			arr[i] = strdup(itoa(record.y_size, temp, 10));
			arr_id[i] = record.id;
		}
		else return 0;
	}
	char tmp[1][513];
	int tmp_id;
	for (int i = 0; i < quantity_of_records; i++)
	{
		for (int j = 0; j < quantity_of_records - 1; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{
				strcpy(tmp[0], arr[j + 1]);
				strcpy(arr[j + 1], arr[j]);
				strcpy(arr[j], tmp[0]);
				tmp_id = arr_id[j];
				arr_id[j] = arr_id[j + 1];
				arr_id[j + 1] = tmp_id;
			}
		}
	}
	char* name = (char*)malloc(128 * sizeof(char));
	strcpy(name, field_name);
	strcat(name, ".idx");
	FILE* f = fopen(name, "wb+");
	for (int i = 0; i < quantity_of_records; i++) {
		fprintf(f, "%d ", arr_id[i]);
	}
	fcloseall();
	return 1;
}

// indexing across all fields
void reindex(const char* db) {
	FILE* file = fopen(db, "r");
	if (NULL == file) return;
	make_index("scanners.db", "id");
	make_index("scanners.db", "manufacturer");
	make_index("scanners.db", "model");
	make_index("scanners.db", "year");
	make_index("scanners.db", "price");
	make_index("scanners.db", "x_size");
	make_index("scanners.db", "y_size");
	fcloseall();
}

// add record
void add_scanner(const char* db, const char* scanner_str) {
	FILE* file = fopen(db, "rb+");
	if (NULL == file) return;
	char* str = (char*)malloc(strlen(scanner_str) * sizeof(char));
	strcpy(str, scanner_str);
	SCAN_INFO record;
	int j = 0;
	int quantity_of_records = 0;
	fread(&quantity_of_records, sizeof(int), 1, file);
	record.id = quantity_of_records;
	fseek(file, 0 ,SEEK_SET);
	quantity_of_records++;
	fwrite(&quantity_of_records, sizeof(int), 1, file);
	char* interval = strtok(str, " ;");
	while (interval != NULL && j < 6)
	{
		switch (j) {
		case 0: strcpy(record.manufacturer, interval); break;
		case 1: strcpy(record.model, interval); break;
		case 2: record.year = atoi(interval); break;
		case 3: record.price = atof(interval); break;
		case 4: record.x_size = atoi(interval); break;
		case 5: record.y_size = atoi(interval); break;
		}
		interval = strtok(NULL, ";");
		j++;
	}
	fseek(file, 0, SEEK_END);
	fwrite(&record, sizeof(SCAN_INFO), 1, file);
	fcloseall();
	reindex(db);
}

//delete record
void del_scanner(const char* db, int id) {
	FILE* file = fopen(db, "rb+");
	if (NULL == file) return;
	FILE* file_del = fopen("update.db", "wb+");
	SCAN_INFO record;
	int quantity_of_records = 0;
	fread(&quantity_of_records, sizeof(int), 1, file);
	int flag_of_records = quantity_of_records;
	fwrite(&flag_of_records, sizeof(int), 1, file_del);
	for (int i = 0; i < quantity_of_records; i++) {
		fread(&record, sizeof(SCAN_INFO), 1, file);
		if (record.id == id) {
			flag_of_records--;
			continue;
		}
		fwrite(&record, sizeof(SCAN_INFO), 1, file_del);
	}
	fseek(file_del, 0, SEEK_SET);
	fwrite(&flag_of_records, sizeof(int), 1, file_del);
	fcloseall();
	remove(db);
	rename("update.db", db);
	reindex(db);
}

//create structure based (field).idx
RECORD_SET* get_recs_by_index(const char* db, char* indx_field) {
	FILE* file = fopen(db, "r");
	char* str = (char*)malloc(strlen(indx_field + 4) * sizeof(char));
	strcpy(str, indx_field);
	strcat(str, ".idx");
	FILE* file_id = fopen(str, "r");
	if ((NULL == file) || (NULL == file_id)) return NULL;
	int quantity_of_records = 0;
	fread(&quantity_of_records, sizeof(int), 1, file);
	RECORD_SET* res = (RECORD_SET*)malloc(sizeof(RECORD_SET));
	SCAN_INFO record;
	int idx;
	res->rec_nmb = quantity_of_records;
	res->recs = (SCAN_INFO*)malloc(res->rec_nmb * (sizeof(SCAN_INFO)));
	for (int i = 0; i < quantity_of_records; i++) {
		fscanf(file_id,"%d ",&idx);
		rewind(file);
		fread(&quantity_of_records, sizeof(int), 1, file);
		for (int j = 0; j < quantity_of_records; j++) {
			fread(&record, sizeof(SCAN_INFO), 1, file);
			if (idx == record.id) {
				res->recs[i] = record;
				break;
			}
		}
		
	}
	fcloseall();
	return res;
}

//create structure based value some field
RECORD_SET* select(const char* db, const char* field, const char* value) {
	FILE* file = fopen(db, "r");
	if (NULL == file) return NULL;
	SCAN_INFO record;
	RECORD_SET* res = (RECORD_SET*)malloc(sizeof(RECORD_SET));
	int quantity_of_records = 0;
	res->rec_nmb = 0;
	fread(&quantity_of_records, sizeof(int), 1, file);
	res->recs = (SCAN_INFO*)malloc(quantity_of_records * (sizeof(SCAN_INFO)));
	if (field == "id") {
		for (int i = 0; i < quantity_of_records; i++) {
			fread(&record, sizeof(SCAN_INFO), 1, file);
			if (record.id == atoi(value)) {
				res->rec_nmb++;
				res->recs[res->rec_nmb - 1] = record;
			}
		}
		fclose(file);
		res->recs = (SCAN_INFO*)realloc(res ->recs, res->rec_nmb * (sizeof(SCAN_INFO)));
		return res;
	}
	else if (field == "manufacturer") {
		for (int i = 0; i < quantity_of_records; i++) {
			fread(&record, sizeof(SCAN_INFO), 1, file);
			if (strcmp(record.manufacturer,value) == 0) {
				res->rec_nmb++;
				res->recs[res->rec_nmb - 1] = record;
			}
		}
		fclose(file);
		res->recs = (SCAN_INFO*)realloc(res->recs, res->rec_nmb * (sizeof(SCAN_INFO)));
		return res;
	}
	else if (field == "model") {
		for (int i = 0; i < quantity_of_records; i++) {
			fread(&record, sizeof(SCAN_INFO), 1, file);
			if (strcmp(record.model, value) == 0) {
				res->rec_nmb++;
				res->recs[res->rec_nmb - 1] = record;
			}
		}
		fclose(file);
		res->recs = (SCAN_INFO*)realloc(res->recs, res->rec_nmb * (sizeof(SCAN_INFO)));
		return res;
	}
	else if (field == "year") {
		for (int i = 0; i < quantity_of_records; i++) {
			fread(&record, sizeof(SCAN_INFO), 1, file);
			if (record.year == atoi(value)) {
				res->rec_nmb++;
				res->recs[res->rec_nmb - 1] = record;
			}
		}
		fclose(file);
		res->recs = (SCAN_INFO*)realloc(res->recs, res->rec_nmb * (sizeof(SCAN_INFO)));
		return res;
	}
	else if (field == "price") {
		for (int i = 0; i < quantity_of_records; i++) {
			fread(&record, sizeof(SCAN_INFO), 1, file);
			if (record.price == atof(value)) {
				res->rec_nmb++;
				res->recs[res->rec_nmb - 1] = record;
			}
		}
		fclose(file);
		res->recs = (SCAN_INFO*)realloc(res->recs, res->rec_nmb * (sizeof(SCAN_INFO)));
		return res;
	}
	else if (field == "x_size") {
		for (int i = 0; i < quantity_of_records; i++) {
			fread(&record, sizeof(SCAN_INFO), 1, file);
			if (record.x_size == atoi(value)) {
				res->rec_nmb++;
				res->recs[res->rec_nmb - 1] = record;
			}
		}
		fclose(file);
		res->recs = (SCAN_INFO*)realloc(res->recs, res->rec_nmb * (sizeof(SCAN_INFO)));
		return res;
	}
	else if (field == "y_size") {
		for (int i = 0; i < quantity_of_records; i++) {
			fread(&record, sizeof(SCAN_INFO), 1, file);
			if (record.y_size == atof(value)) {
				res->rec_nmb++;
				res->recs[res->rec_nmb - 1] = record;
			}
		}
		fclose(file);
		res->recs = (SCAN_INFO*)realloc(res->recs, res->rec_nmb * (sizeof(SCAN_INFO)));
		return res;
	}
	else return NULL;
	
}

void print_rec_set(RECORD_SET* rs) {
	if (rs == NULL) {
		printf("Incorrect field");
		return;
	}
	printf("Quantity: %d \n", rs->rec_nmb);
	for (int i = 0; i < rs->rec_nmb; i++)
	{
		printf("%d, %s, %s, %d, %.3f, %d, %d\n", rs->recs[i].id, rs->recs[i].manufacturer, 
			rs->recs[i].model, rs->recs[i].year, rs->recs[i].price, rs->recs[i].x_size, rs->recs[i].y_size);
	}
}
