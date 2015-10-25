#include "calorie.h"

// Gets an int from the input file stream
int get_int(FILE *infile)
{
	int i = 0;
	fscanf(infile, "%d\n", &i);

	return i;
}

// Gets a char from the input file stream
char get_char(FILE *infile)
{
	char c = '\0';
	fscanf(infile, "%c\n", &c);

	return c;
}

// Gets the age by calling get_int()
int get_age(FILE *infile)
{
	return get_int(infile);
}

// Get the gender by calling get_char()
char get_gender(FILE *infile)
{
	return get_char(infile);
}

// Get the weight by calling get_int()
int get_weight(FILE *infile)
{
	return get_int(infile);
}

// Get the height by calling get_int()
int get_height(FILE *infile)
{
	return get_int(infile);
}

// Calculates the BMR based on inputs
double calculate_bmr(char gender, int weight, int height_in_inches, int age)
{
	double bmr = 0.0;

	// Male
	if (gender == 'm' || gender == 'M')
	{
		bmr = 66 + (6.23 * weight) + (12.7 * height_in_inches) - (6.8 * age);
	}
	// Female
	else if (gender == 'f' || gender == 'F')
	{
		bmr = 655 + (4.35 * weight) + (4.7 * height_in_inches) - (4.7 * age);
	}

	return bmr;
}

// This function calculates the caloric intake based on the BMR and activity level
double calculate_caloric_intake(double bmr, int activity_level)
{
	double caloric_intake = 0.0;

	if (activity_level == 1) { caloric_intake = bmr * 1.2; }
	else if (activity_level == 2) { caloric_intake = bmr * 1.375; }
	else if (activity_level == 3) { caloric_intake = bmr * 1.55; }
	else if (activity_level == 4) { caloric_intake = bmr * 1.725; }
	else if (activity_level == 5) { caloric_intake = bmr * 1.9; }

	return caloric_intake;
}

// This function calculates the bonus based on the response
int calculate_bonus(char response)
{
	int bonus_amount = 25000; // Bonus amount for first one

	if (response == 'y') // If user responded yes
	{
		return bonus_amount; // Return the bonus amount
	}
	else // User responded anything else
	{
		return 0; // Otherwise return 0 because the bonus isn't applied
	}
}