#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*#define MAX_DATA 512*/
/*#define MAX_ROWS 100*/
int MAX_DATA;
int MAX_ROWS;
int int_size = sizeof(int);

void lowercase(char *string)
{
    int i = 0;
    for (i = 0; string[i]; i++) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32;
        }
    }
}

struct Address {
    int id;
    int set;
    char *name;
    char *email;
};

struct Database {
    int MAX_ROWS;
    int MAX_DATA;
    struct Address *rows;
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

void die(const char *message, struct Connection *conn)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    Database_close(conn);

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to load database.", conn);
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error", conn); // err?!

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error", conn);

    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file", conn);

    return conn;
}


void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database.", conn);

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.", conn);
}

struct Address *create_address(int id, int set)
{
    struct Address *addr;
    addr->id = id;
    addr->set = set;
    addr->name = malloc(MAX_DATA);
    addr->email = malloc(MAX_DATA);
    return addr;
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        /*struct Address addr = {.id = i, .set = 0};*/
        // then just assign it
        /*conn->db->rows[i] = addr;*/
        conn->db->rows[i] = *create_address(i, 0);
    }
}

// create a null terminating version of strncpy
// many consider strncpy to be an unsafe way to copy a string
// as it does not nul terminate strings that are equal to or 
// larger than the size constraint. This is an unfair criticism of
// strngcpy as it is not strictly speaking designed for this task.
char *safe_strncpy(char *dest, const char *src, size_t n)
{
    char *res = strncpy(dest, src, n);
    res[n - 1] = '\0';
    return res;
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die("Already set, delete it first", conn);

    addr->set = 1;
    char *res = safe_strncpy(addr->name, name, MAX_DATA);
    if(!res) die("Name copy failed", conn);

    res = safe_strncpy(addr->email, email, MAX_DATA);
    if(!res) die("Email copy failed", conn);
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set", conn);
    }
}

void Database_delete(struct Connection *conn, int id)
{
    // this should really error if there is no relevant entry!
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}

void Database_find(struct Connection *conn, char *search_term)
{
    // loop through db entries
    int i = 0;
    struct Database *db = conn->db;
    lowercase(search_term);

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        char *email= cur->email;
        lowercase(email);
        char *name = cur->name;
        lowercase(name);

        // compare namestring with search_term
        if (strstr(email, search_term) != NULL || strstr(name, search_term) != NULL) {
            Address_print(cur);
        }
        // compare address string with search_term
        
    }
}

int main(int argc, char *argv[])
{
    // initialise to null in order to have something to pass to die :)
    struct Connection *conn = NULL;
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]", conn);

    char *filename = argv[1];
    char action = argv[2][0];
    conn = Database_open(filename, action);
    int id = 0;
    char *search_term;

    MAX_ROWS = conn->db->MAX_ROWS;
    MAX_DATA = conn->db->MAX_DATA;

    if (action == 'c') {
        if(argc != 5) die("Need more args, mate", conn);
        MAX_ROWS = atoi(argv[3]);
        MAX_DATA = atoi(argv[4]);
    } else {
        if(argc > 3) id = atoi(argv[3]);
        if(id >= MAX_ROWS) die("There's not that many records.", conn);
    }

    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if(argc != 4) die("Need an id to get", conn);

            Database_get(conn, id);
            break;

        case 's':
            if(argc != 6) die("Need id, name, email to set", conn);

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die("Need id to delete", conn);

            Database_get(conn, id);
            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
            
        case 'f':
            if(argc > 3) search_term =  argv[3];
            Database_find(conn, search_term);
            break;

        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list", conn);
    }

    Database_close(conn);

    return 0;
}
