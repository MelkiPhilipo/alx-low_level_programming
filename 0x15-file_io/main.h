#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <string.h>
#include <error.h>

int main(int ac, char **av);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void error_98(int fi0, char *folder, char *arv);
void error_99(int fi0, char *folder, char *arv);
void error_100(int fi0, char *folder);

#endif /* MAIN_H */
