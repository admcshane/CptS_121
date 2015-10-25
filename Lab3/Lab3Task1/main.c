#include "calorie.h"

int main()
{
	// Variable declarations
	int age = 0, weight = 0, height_in_inches = 0, activity_level = 0;
	char gender = '\0';
	double bmr = 0.0, caloric_intake = 0.0;

	// Step 1: Open the desired file
	printf("Opening marshawn.txt with reading permissions... ");
	FILE *infile = fopen("marshawn.txt", "r");
	printf("Done\n");
	
	// Step 2: Process the file and set variables
	printf("Processing marshawn.txt... ");
	age = get_age(infile);
	gender = get_gender(infile);
	weight = get_weight(infile);
	height_in_inches = get_height(infile);
	printf("Done\n");

	// Step 3: Close the opened file
	printf("Closing marshawn.txt... ");
	fclose(infile);
	printf("Done\n\n");

	// Print processed results
	printf("Processed results:\n------------------\n");
	printf("Age: %d years old\n", age);
	printf("Gender: %c\n", gender);
	printf("Weight: %d lbs\n", weight);
	printf("Height: %d inches\n\n", height_in_inches);

	// Calculate BMR
	bmr = calculate_bmr(gender, weight, height_in_inches, age);

	// Prompt for activity level
	printf("--------- Activity Levels ----------\n");
	printf("1: Sedentary (little to no exercise)\n");
	printf("2: Low activity\n");
	printf("3: Moderate activity\n");
	printf("4: High activity\n");
	printf("5: Extra activity\n");
	printf("------------------------------------\n");
	printf("Enter your activity level (1-5): ");
	scanf("%d", &activity_level);

	// Calculate caloric intake
	caloric_intake = calculate_caloric_intake(bmr, activity_level);

	// Print results and terminate the program
	printf("\nYou should be consuming %.2lf calories per 24\nhours to maintain your current body weight.\n\n", caloric_intake);
	return 0;

}