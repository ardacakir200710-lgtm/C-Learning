/*Learning SQL basics and SQLite integration with C*/

#include <stdio.h>
#include <sqlite3.h>

// ** for string arrays.

int callback(void *data, int sutun_sayisi, char **sutun_degerleri, char **sutun_isimleri){
    for(int i=0;i<sutun_sayisi;i++){
		printf("%s : %s\n",sutun_isimleri[i],sutun_degerleri[i]);
    }
    printf("---\n");

    return 0;
}


int main(void)
{
	sqlite3 *db;
	int rc; // varible responsiable for db handling errors
	char* err = NULL; // variable responsiable for holding sqlite exec func errors.

	rc = sqlite3_open("data.db",&db);

	if (rc != SQLITE_OK){
		printf("Failed to open database: %s\n",sqlite3_errmsg(db));
		return -1;
	}
	printf("Database opeend succesfully!\n");
	const char *sql = "SELECT * FROM Ogrenciler;";

	rc = sqlite3_exec(db,sql,callback,0,&err);

	if(rc != SQLITE_OK){
	    printf("An error occured: %s",sqlite3_errmsg(db));
	    sqlite3_free(err);	
	    return -1;
	}
	else{
		printf("data added succesfully!");	
	}


	sqlite3_close(db);

	printf("Database closed succefully!\n");

	return 0;
}
