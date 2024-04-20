/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** asm.h
*/

#include <stdbool.h>

#ifndef ASM_H_
    #define ASM_H_

    #define DIR_V 0b10
    #define IND_V 0b11
    #define REG_V 0b01
    #define OTH_V 0b00


//data structure
typedef struct data_t {
    char *name;
    char *comment;
    char **instructions;
    bool *begin_instruct;
} data_t;

//transcription label chained_list
typedef struct label_t {
    char *name;
    int pos;
    struct label_t *next;
} label_t;

//transcription body structure
typedef struct body_t {
    char **array;
    int fd;
    int nb_args;
    int verif;
    int i_arg;
    char *args;
    bool isIndex;
    int index_cb;
    int coding_byte[4];
    label_t *label;
} body_args;

//index function
int help(void);
int malloc_struct(data_t *data, body_args *body);

//data
char **get_array(const char *av[]);
char *file_content(const char *path);
int create_data(const char *av[], data_t *data);
int init_structure(char **array, data_t *data);
char *retrieve_data(char **array, char *name);
char *retrieve_instructions(char *buffer, data_t *data, int j);
bool is_valid_instruction(char *buffer);
int check_data_instructions(data_t *data);
int condition_full_reg(char **array, int max_args, int decal);
int condition_full_dir(char **array, int max_args, int decal);

//header
int fill_struct(data_t *data, body_args *body, const char *av[]);
int convert_big_endian_int(int little_endian);
short convert_big_endian_short(short value);
int prog_size(data_t *data);

//body
int convert_body_into_binary(data_t *data, body_args *body, int fd);
int check_instructions(body_args *body, int fd);
int check_args(body_args *body, int pos_instruction, int pos_struct,
data_t *data);
int get_coding_byte(body_args *body, int fd);
int condition_instructions(body_args *body, int i);
void write_args(body_args *body, int fd);
void write_index(body_args *body, int fd);
bool verif_index(body_args *body, int *coding_byte);
bool is_exceptions(body_args *body);
void condition_loop_args(body_args *body, int i, data_t *data,
int pos_instruction);
int check_verif(int i, body_args *body);
char *get_args(body_args *body, int i, data_t *data, int pos_instruction);
int loop_args(body_args *body, int pos_instruction, data_t *data);
void process_args(body_args *body);
label_t *create_list_label(label_t *label, data_t *data);
char* is_label(char* line, int j);
char *calc_dist(data_t *data, char *name_label, int pos_instruction,
body_args *body);
int is_index(char *instruction);
int verif_conding_byte(char *instruction);
int calc_size_instruction(char *instruction, char *arg);
int get_size_instruction(char **line);
int neg_dist(data_t *data, int pos_instruction, int pos_label);
int pos_dist(data_t *data, int pos_instruction, int pos_label);
int get_pos_label(label_t *label, char *name_label);
char *get_name_label(char *str, int j);
char *calc_dist(data_t *data, char *name_label, int pos_instruction,
body_args *body);
char* is_label(char* line, int j);
void free_label(label_t *label);

#endif /* !ASM_H_ */
