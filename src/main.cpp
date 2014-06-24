#include <iostream>
#include <string>

#include <sqlite3.h>

#include "Sqlite3_error.hpp"


using namespace std;
using namespace sqlite;


const string db_name = "test.db";

int
select_handler(void* data, int argc, char** argv, char** column_name)
{
	(void)data;

	for (int i = 0; i < argc; i++) {
		cout << column_name[i] << " " << argv[i] << '\n';
	}

	return 0;
}


int
main(void)
{
	sqlite3* db = nullptr;
	char* sqlite_error = nullptr;

	int ret = sqlite3_open(db_name.c_str(), &db);
	if (ret != SQLITE_OK) {
		throw Sqlite3_error("Failed to open DB " + db_name);
	}

	ret = sqlite3_exec(db, "create table if not exists "
		"users(id text primary key , pass text);", nullptr, nullptr,
		&sqlite_error);
	if (ret != SQLITE_OK) {
		cout << sqlite_error << '\n';
	}
	sqlite3_free(sqlite_error);

	ret = sqlite3_exec(db, "insert or ignore into users values "
		"('user1', 'pass1');", nullptr, nullptr,
		&sqlite_error);
	if (ret != SQLITE_OK) {
		cout << sqlite_error << '\n';
	}
	sqlite3_free(sqlite_error);

	ret = sqlite3_exec(db, "select * from users;", select_handler, nullptr,
		&sqlite_error);
	if (ret != SQLITE_OK) {
		cout << sqlite_error << '\n';
	}
	sqlite3_free(sqlite_error);

	ret = sqlite3_close(db);
	if (ret != SQLITE_OK) {
		throw Sqlite3_error("Failed to close DB.");
	}

	return 0;
}
