#include <stdio.h>

// Generic functions
int get_int(FILE *infile);
char get_char(FILE *infile);

// Specific functions
int get_age(FILE *infile);
char get_gender(FILE *infile);
int get_weight(FILE *infile);
int get_height(FILE *infile);

// This function calculates the BMR of the user based on inputs
double calculate_bmr(char gender, int weight, int height_in_inches, int age);

// This function calculates the caloric intake based on the BMR and activity level
double calculate_caloric_intake(double bmr, int activity_level);