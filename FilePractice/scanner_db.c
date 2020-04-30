#include "scanner.h"

int main() {
	create_db("scanners.csv", "scanners.db");
	print_db("scanners.db");
	reindex("scanners.db");
	add_scanner("scanners.db", "ASUS;AS1055;2009;199.99;210;297");
	print_db("scanners.db");
	del_scanner("scanners.db", 1);
	print_db("scanners.db");
	RECORD_SET* rs = select("scanners.db", "year", "2005");
	print_rec_set(rs);
	rs = get_recs_by_index("scanners.db", "y_size");
	print_rec_set(rs);
	return 0;
}

