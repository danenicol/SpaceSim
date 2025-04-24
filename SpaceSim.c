/*START OF CODE, Dane Nicol, 130822325, COMPE 271 */

#include <stdio.h>



/* Defining  constants for simulator */

#define ship_max_fuel 1000
#define ship_max_oxygen 500
#define ship_max_water 500
#define max_mealworm_health 10
#define max_plant_health 10

/* Global Resource Integers for ship resouces */

int mealworm_farm_health = 7;
int plant_farm_health = 7;
	
int water = 300;
int oxygen = 300;
int fuel = 700;


/* Global Controller Integer */
int global_Orbit_Number = 0; /* YopYop = 0, Xin = 1 */
int global_Land_Number = 0; /* In orbit = 0, landed = 1 */
int research_Points = 0; 


/* Prototype General Functions */
void radiation_Data();
void land_On_Body();
void maintain_Farm();
void mine_Asteroid();
void check_Diagnostics();
void random_Farm_Event();
void display_Inner_System();
void display_Outer_System();
void display_Orbit_Change();
void display_Hub();

/* Prototype Location Orbit Functions */

void fuel_Check();
void orbit_Change();


void orbit_Change_Inner_System();
void orbit_Change_YopYop();

void orbit_Change_Outer_System();
void orbit_Change_Xin();

/* Prototype Location Surface Functions */

void surface_YopYopt();
void surface_Xin();





void fuel_Check_Land() {
	printf("Checking fuel for landing/liftoff...\n");
	
	while (getchar() != '\n'); 
	getchar();

	if (fuel <= 300) {
		printf("Not enough fuel to make a landing and liftoff... mine asteroids!\n");
		while (getchar() != '\n'); 
		getchar();
		main();
	}
	else {
		printf("You have enough fuel, proceed with cation!\n");
		while (getchar() != '\n'); 
		getchar();
	}
}






void fuel_Check_Orbit() {
	printf("Checking fuel for orbit change...\n");
	
	while (getchar() != '\n'); 
	getchar();

	if (fuel <= 500) {
		printf("Not enough fuel to make a orbital change... mine asteroids!\n");
		while (getchar() != '\n'); 
		getchar();
		main();
	}
	else {
		printf("You have enough fuel, proceed with cation!\n");
		while (getchar() != '\n'); 
		getchar();
	}
}
		

  
  
void display_Hub() {
	
	printf("0=======================================================================================================0 \n");
	printf("| \\                                                                                                  / | \n");
	printf("|   \\                                                                                              /   | \n");
	printf("|     \\                                                                                          /     | \n");
	printf("|       \\                                                                                      /       | \n");
	printf("|         \\                                                                                  /         | \n");
	printf("|           \\                                                                              /           | \n");
	printf("|             \\                                                                          /             | \n");
	printf("|               \\                                                                      /               | \n");
	printf("|                 \\                                                                  /                 | \n");
	printf("|                   \\                                                              /                   | \n");
	printf("|                     \\                                                          /                     | \n");
	printf("|                       \\------------------------------------------------------/                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                     [View Port]                     |                       | \n");
	printf("|                        |                  |--------------|                   |                       | \n");
	printf("|                        |                  |   *      *   |                   |                       | \n");
	printf("|                        |                  | *     *   *  |                   |                       | \n");
	printf("|                        |                  |     *   *   *|                   |                       | \n");
	printf("|                        |                  |--------------|                   |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |_ ___________________________________________________|                       | \n");    
	printf("|                       /  | ------------------------------------------------ |\\                       | \n");
	printf("|                     /    | |[0]                                     [0]   | |  \\                     | \n");
	printf("|                   /      | | ((Welcome to your control hub, operator))    | |    \\                   | \n");
	printf("|                 /        | |                                              | |      \\                 | \n");
	printf("|               /          | | {1}       [Change orbital trajectory]        | |        \\               | \n");
	printf("|             /            | | {2} [Land on current orbiting celetial body] | |          \\             | \n");
	printf("|           /              | | {3}           [Maintain bio farm]            | |            \\           | \n");
	printf("|         /                | | {4}          [Mine local asteroids]          | |              \\         | \n"); 
	printf("|       /                  | | {5}         [Check ship diagnostics]         | |                \\       | \n"); 
	printf("|     /                    | | {6}         [Observe Radiation Data]         | |                  \\     | \n"); 
	printf("|     /                    | | {7}            [Cryogeneic Sleep]            | |                  \\     | \n"); 
	printf("|   /                      | |                                              | |                    \\   | \n");
    printf("| /                        |_|----------------------------------------------|_|                      \\ | \n");
	printf("                           | |----------------------------------------------| |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");

	
}


void display_Inner_System() {
	printf("0=======================================================================================================0 \n");
	printf("| \\                                                                                                  / | \n");
	printf("|   \\                                                                                              /   | \n");
	printf("|     \\                                                                                          /     | \n");
	printf("|       \\                                                                                      /       | \n");
	printf("|         \\                                                                                  /         | \n");
	printf("|           \\                                                                              /           | \n");
	printf("|             \\                                                                          /             | \n");
	printf("|               \\                                                                      /               | \n");
	printf("|                 \\                                                                  /                 | \n");
	printf("|                   \\                                                              /                   | \n");
	printf("|                     \\                                                          /                     | \n");
	printf("|                       \\------------------------------------------------------/                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                     [View Port]                     |                       | \n");
	printf("|                        |                  |--------------|                   |                       | \n");
	printf("|                        |                  |   *      *   |                   |                       | \n");
	printf("|                        |                  | *     *   *  |                   |                       | \n");
	printf("|                        |                  |     *   *   *|                   |                       | \n");
	printf("|                        |                  |--------------|                   |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |_ ___________________________________________________|                       | \n");    
	printf("|                       /  | ------------------------------------------------ |\\                       | \n");
	printf("|                     /    | |[0]                                     [0]   | |  \\                     | \n");
	printf("|                   /      | | ((Which orbit shall the ship relocate to?))  | |    \\                   | \n");
	printf("|                 /        | |                                              | |      \\                 | \n");
	printf("|               /          | | {1}               [Yop Yop]                  | |        \\               | \n");
	printf("|             /            | | {2}               [Cancel]                   | |          \\             | \n");
	printf("|           /              | |                                              | |            \\           | \n");
	printf("|         /                | |                                              | |              \\         | \n");
	printf("|       /                  | |                                              | |                \\       | \n");
	printf("|     /                    | |                                              | |                  \\     | \n"); 
	printf("|   /                      | |                                              | |                    \\   | \n");
    printf("| /                        |_|----------------------------------------------|_|                      \\ | \n");
	printf("                           | |----------------------------------------------| |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	
}
	
	
void display_Outer_System() {
	printf("0=======================================================================================================0 \n");
	printf("| \\                                                                                                  / | \n");
	printf("|   \\                                                                                              /   | \n");
	printf("|     \\                                                                                          /     | \n");
	printf("|       \\                                                                                      /       | \n");
	printf("|         \\                                                                                  /         | \n");
	printf("|           \\                                                                              /           | \n");
	printf("|             \\                                                                          /             | \n");
	printf("|               \\                                                                      /               | \n");
	printf("|                 \\                                                                  /                 | \n");
	printf("|                   \\                                                              /                   | \n");
	printf("|                     \\                                                          /                     | \n");
	printf("|                       \\------------------------------------------------------/                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                     [View Port]                     |                       | \n");
	printf("|                        |                  |--------------|                   |                       | \n");
	printf("|                        |                  |   *      *   |                   |                       | \n");
	printf("|                        |                  | *     *   *  |                   |                       | \n");
	printf("|                        |                  |     *   *   *|                   |                       | \n");
	printf("|                        |                  |--------------|                   |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |_ ___________________________________________________|                       | \n");    
	printf("|                       /  | ------------------------------------------------ |\\                       | \n");
	printf("|                     /    | |[0]                                     [0]   | |  \\                     | \n");
	printf("|                   /      | | ((Which orbit shall the ship relocate to?))  | |    \\                   | \n");
	printf("|                 /        | |                                              | |      \\                 | \n");
	printf("|               /          | | {1}                [Xin]                     | |        \\               | \n");
	printf("|             /            | | {2}               [Cancel]                   | |          \\             | \n");
	printf("|           /              | |                                              | |            \\           | \n");
	printf("|         /                | |                                              | |              \\         | \n");
	printf("|       /                  | |                                              | |                \\       | \n");
	printf("|     /                    | |                                              | |                  \\     | \n"); 
	printf("|   /                      | |                                              | |                    \\   | \n");
    printf("| /                        |_|----------------------------------------------|_|                      \\ | \n");
	printf("                           | |----------------------------------------------| |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	
}


/* This function will take a long time to complete, I will finish this one later */
void display_Orbit_Change() {
	printf("0=======================================================================================================0 \n");
	printf("| \\                                                                                                  / | \n");
	printf("|   \\                                                                                              /   | \n");
	printf("|     \\                                                                                          /     | \n");
	printf("|       \\                                                                                      /       | \n");
	printf("|         \\                                                                                  /         | \n");
	printf("|           \\                                                                              /           | \n");
	printf("|             \\                                                                          /             | \n");
	printf("|               \\                                                                      /               | \n");
	printf("|                 \\                                                                  /                 | \n");
	printf("|                   \\                                                              /                   | \n");
	printf("|                     \\                                                          /                     | \n");
	printf("|                       \\------------------------------------------------------/                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                     [View Port]                     |                       | \n");
	printf("|                        |                  |--------------|                   |                       | \n");
	printf("|                        |                  |   *      *   |                   |                       | \n");
	printf("|                        |                  | *     *   *  |                   |                       | \n");
	printf("|                        |                  |     *   *   *|                   |                       | \n");
	printf("|                        |                  |--------------|                   |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |                                                     |                       | \n");
	printf("|                        |_ ___________________________________________________|                       | \n");    
	printf("|                       /  | ------------------------------------------------ |\\                       | \n");
	printf("|                     /    | |[0]                                     [0]   | |  \\                     | \n");
	printf("|                   /      | | ((Which orbit shall the ship relocate to?))  | |    \\                   | \n");
	printf("|                 /        | |                                              | |      \\                 | \n");
	printf("|               /          | | {1}            [Inner System]                | |        \\               | \n");
	printf("|             /            | | {2}            [Outer System]                | |          \\             | \n");
	printf("|           /              | | {3}               [Cancel]                   | |            \\           | \n");
	printf("|         /                | |                                              | |              \\         | \n");
	printf("|       /                  | |                                              | |                \\       | \n");
	printf("|     /                    | |                                              | |                  \\     | \n"); 
	printf("|   /                      | |                                              | |                    \\   | \n");
    printf("| /                        |_|----------------------------------------------|_|                      \\ | \n");
	printf("                           | |----------------------------------------------| |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	printf("                           | |                                              | |                           \n");
	
	
}


/* IMPORTANT NOTE: Default in my switches across the entire code is looping infinitely and break does not seem to be working. I will need to fix that. */

void orbit_Change() {
	int choice;
	fuel_Check_Orbit();
	display_Orbit_Change();
	
	
	while (1) {
	scanf("%d", &choice);
	
	switch (choice) {
	
	
	case 1:
	orbit_Change_Inner_System();
	break;
	
	case 2:
	orbit_Change_Outer_System();
	break;
	
	case 3:
	display_Hub();
	break;
	
	
	default:
	printf("Invalid choice! Please select options 1 - (unknown) \n");
	break;
	}
	
	}

}


void orbit_Change_Inner_System() {
	int choice;
	display_Inner_System();

	
	while (1) {
	scanf("%d", &choice);
	
	switch (choice) {
	
	
	case 1:
	orbit_Change_YopYop();
	break;
	
	case 2:
	orbit_Change();
	break;
	
	
	default:
	printf("Invalid choice! Please select options 1 - (unknown) \n");
	break;
	}
	
	}

}


void orbit_Change_Outer_System() {
	int choice;
	display_Outer_System();
	
	
	while (1) {
	scanf("%d", &choice);
	
	switch (choice) {
	
	
	case 1:
	orbit_Change_Xin();
	break;
	
	case 2:
	orbit_Change();
	break;
	
	
	default:
	printf("Invalid choice! Please select options 1 - (unknown) \n");
	break;
	}
	
	}

}


void orbit_Change_YopYop() {

	
	printf("Your orbit has been changed to YopYop!\n");
	
	
	
	
	printf("0=======================================================================================================0 \n");
	printf("|                                                                                                       | \n");
	printf("|                                                                              *                        | \n");
	printf("|                  *                                                                           *        | \n");
	printf("|                                *                       *                                              | \n");
	printf("|                                                                                                       | \n");
	printf("|            *                                                                                          | \n");
	printf("|                            *                                                                          | \n");
	printf("|                                               //---------\\                                           | \n");
	printf("|                                              //           \\                 *                        | \n");
	printf("|        *                                    //  *  __      \\                                         | \n");
	printf("|                          *                  |    //  \\     |                                         | \n");
	printf("|                                             |   |     |     |    *                                    | \n");
	printf("|                                             |    \\ __//     |                                        | \n");
	printf("|                                             \\             //                                 *       | \n");
	printf("|                  *                       *   \\           //                                          | \n");
	printf("|       *                                       \\---------//                                           | \n");
	printf("|                                                                                                       | \n");
	printf("|                                                                                                       | \n");
	printf("|                                *                                                     *                | \n");
	printf("|                   *                                                                                   | \n");
	printf("|        *                                                           *                                  | \n");
	printf("|                                                                                                       | \n");
	printf("|                                                                                                       | \n");
	printf("0=======================================================================================================0 \n");  
	
	
	global_Orbit_Number = 0;
	
	while (getchar() != '\n'); 
	getchar();
		
	fuel = fuel - 500;

	printf("Your ship fuel has decreased by 500\n");
	printf("Current fuel: %d\n", fuel);

	
	printf("\n");
	
	printf("Your plant and mealworm health has gone down by 3 points!\n");
	mealworm_farm_health = mealworm_farm_health - 3;
	plant_farm_health = plant_farm_health - 3;
	printf("Current health stats:\n");
	printf("Plant Farm: %d\n",  plant_farm_health); \
	printf("Mealworm Farm: %d\n",  mealworm_farm_health); 
	
	while (getchar() != '\n'); 
	getchar();
	main();
}

void orbit_Change_Xin() {

		
	printf("Your orbit has been changed to Xin!\n");
	
	printf("0=======================================================================================================0 \n");
	printf("|                                                                                                       | \n");
	printf("|                                                                              *                        | \n");
	printf("|                  *                                                                           *        | \n");
	printf("|                                *                       *                                              | \n");
	printf("|                                                                                                       | \n");
	printf("|            *                                                                                          | \n");
	printf("|                            *                                                                          | \n");
	printf("|                                               //---------\\                                           | \n");
	printf("|                                              //           \\                 *                        | \n");
	printf("|        *                                    //  *  __      \\                                         | \n");
	printf("|                          *                  |    //  \\     |                                         | \n");
	printf("|                                             |   |     |     |    *                                    | \n");
	printf("|                                             |    \\ __//     |                                        | \n");
	printf("|                                             \\             //                                 *       | \n");
	printf("|                  *                       *   \\           //                                          | \n");
	printf("|       *                                       \\---------//                                           | \n");
	printf("|                                                                                                       | \n");
	printf("|                                                                                                       | \n");
	printf("|                                *                                                     *                | \n");
	printf("|                   *                                                                                   | \n");
	printf("|        *                                                           *                                  | \n");
	printf("|                                                                                                       | \n");
	printf("|                                                                                                       | \n");
	printf("0=======================================================================================================0 \n");  
	
	global_Orbit_Number = 1;
	
	while (getchar() != '\n'); 
	getchar();
	
	fuel = fuel - 500;

		
	printf("Your ship fuel has decreased by 500\n");
	printf("Current fuel: %d\n", fuel);

	
	printf("\n");
	
	printf("Your plant and mealworm health has gone down by 3 points!\n");
	mealworm_farm_health = mealworm_farm_health - 3;
	plant_farm_health = plant_farm_health - 3;
	printf("Current health stats:\n");
	printf("Plant Farm: %d\n",  plant_farm_health);
	printf("Mealworm Farm: %d\n",  mealworm_farm_health); 
	
	while (getchar() != '\n'); 
	getchar();
	main();

}





/* Random_farm_event is going to be were outbreaks can occur. Still working on this function */ 
void random_Farm_Event() {
	int event = rand() % 5;
	
	switch (event) {
	
		case 0: /* Bacterial or Viral Outbreak */
		
			printf("      [Plant Farm]              [Mealworm Farm]     \n");
			printf("           ??                          ??           \n");
			printf("+----------------------+   +----------------------+ \n");
  			printf("| {} {} {} {} {} {} {} |   |  ~~ ~ ~~ ~  ~ ~~~ ~  | \n");
 		 	printf("| {} {} {} {} {} {} {} |   |    [Mealworm Trays]  | \n"); 
  			printf("|  [Hydroponic Trays]  |   |      [Substrate]     | \n");
  			printf("| <><><><><><><><><><> |   |   MMMMMMMMMMMMMMMMM  | \n");
  			printf("+----------------------+   +----------------------+ \n");
  			printf("  | Pumps | Nutrients |     | Temperature: ?? F  | \n");
  			printf("  | ??? % % |   ??? % %   |     |   Humidity: ?? % %   | \n");
			printf("\n");
			printf("Calibration Error! Bio farm malfunction! Suspected viral or bacterial infection. Automatic reset running...\n");
			printf("Press any key to proceed with diagnostics\n");
			
			while (getchar() != '\n'); 
			getchar();
			
			printf("Bacterial or viral outbreak! Risk Level for mealworm farm: Extreme! Risk Level for plant farm: Extreme!\n");
			printf("The outbreak hurts your plants and mealworms!\n");
			printf("Mealworm and Plant Farm Health -3.\n");
			mealworm_farm_health = mealworm_farm_health - 3;
			plant_farm_health = plant_farm_health - 3;
			printf("Press any key to proceed with maintenance.\n");
			
			while (getchar() != '\n'); 
			getchar();
			
			break;
			
			

		default:
			break;
		}
			
	
	
}
			
/* maintain_farm function is simply just were the ASCII image of the farms are and where the incrementation (or max) occurs. */
void maintain_Farm() {

	random_Farm_Event();
	
	mealworm_farm_health++;
	plant_farm_health++;

	printf("      [Plant Farm]              [Mealworm Farm]     \n");
	printf("           %d                          %d           \n",plant_farm_health, mealworm_farm_health);
    printf("+----------------------+   +----------------------+ \n");
    printf("| {} {} {} {} {} {} {} |   |  ~~ ~ ~~ ~  ~ ~~~ ~  | \n");
    printf("| {} {} {} {} {} {} {} |   |    [Mealworm Trays]  | \n"); 
    printf("|  [Hydroponic Trays]  |   |      [Substrate]     | \n");
    printf("| <><><><><><><><><><> |   |   MMMMMMMMMMMMMMMMM  | \n");
    printf("+----------------------+   +----------------------+ \n");
    printf("  | Pumps | Nutrients |     | Temperature: 80 F  | \n");
    printf("  | 100 % % |   100 % %   |     |   Humidity: 55 % %   | \n");
	
	
	if (mealworm_farm_health > max_mealworm_health) {
		mealworm_farm_health = max_mealworm_health;
		printf("Mealworm health is at maximum, cannot exceed 10!\n");
		}
		
	if (plant_farm_health > max_plant_health) {
		plant_farm_health = max_plant_health;
		printf("Plant health is at maximum, cannot exceed 10!\n");
		}
		
	else {
	printf("Farm health improved! Plant farm health: %d, Mealworm farm health: %d\n", plant_farm_health, mealworm_farm_health);
	}
	
	while (getchar() != '\n');
	
	water = water - 100;
	printf("Water supply has gone down by 100!\n");
	printf("Current water: %d\n", water);

	
	printf("Press any key to return to control hub\n");
	
	while (getchar() != '\n'); /*Note: getchar(); requires the user to enter a key to proceed with the program, however while (getchar() != '\n'); is before that line to clear previous blank line input */
	getchar();

}










void mine_Asteroid() {

	if (global_Orbit_Number == 0) {
		printf("Mining asteroids in orbit around YopYop...\n");
		
		
		while (getchar() != '\n'); 
		getchar();
		
		water = water + 50;
		oxygen = oxygen + 50;
		fuel = fuel + 50;
		
		if (water > ship_max_water) {
			water = ship_max_water;
			printf("Water is at maximum, cannot exceed 500!\n");
		}
		
		if (oxygen > ship_max_oxygen) {
			oxygen = ship_max_oxygen;
			printf("Oxygen is at maximum, cannot exceed 500!\n");
		}
		
		if (fuel > ship_max_fuel) {
			fuel = ship_max_fuel;
			printf("Fuel is at maximum, cannot exceed 1000!\n");
		}
		
		else {
			printf("Asteroids have been mined!\n");
		}
		
		printf("Your ship resources now have increased by 50!\n");
		printf("Current reserves:\n");
		printf("Water: %d\n", water);
		printf("Oxygen: %d\n", oxygen);
		printf("Fuel: %d\n", fuel);
		
		}
		
	else if (global_Orbit_Number == 1) {
		printf("Mining asteroids in orbit around Xim...\n");
		
		while (getchar() != '\n'); 
		getchar();
		
		water = water + 100;
		oxygen = oxygen + 100;
		fuel = fuel + 100;
		
		if (water > ship_max_water) {
			water = ship_max_water;
			printf("Water is at maximum, cannot exceed 500!\n");
		}
		
		if (oxygen > ship_max_oxygen) {
			oxygen = ship_max_oxygen;
			printf("Oxygen is at maximum, cannot exceed 500!\n");
		}
		
		if (fuel > ship_max_fuel) {
			fuel = ship_max_fuel;
			printf("Fuel is at maximum, cannot exceed 1000!\n");
		}
		
		else {
			printf("Asteroids have been mined!\n");
		}
		
		printf("Your ship resources now have increased by 100!\n");
		printf("Current reserves:\n");
		printf("Water: %d\n", water);
		printf("Oxygen: %d\n", oxygen);
		printf("Fuel: %d\n", fuel);
		
		}

	while (getchar() != '\n'); 
	getchar();
}


void surface_YopYop() {
	printf("You have landed on YopYop!\n"); 
	printf("You observe your surroundings...\n");
	
	while (getchar() != '\n'); 
	getchar();
	
    printf("             *             *                      \n");
    printf("                                                  \n");
    printf("       *                         *        *       \n");
    printf("                              *                   \n");
    printf("                   *   /\\                        \n");
    printf("                      /  \\                *      \n");
    printf("         /\\         _/    \\_        /\\         \n");
    printf("        /  \\    /\\ /        \\ /\\   /  \\      \n");
    printf("       /    \\  /  \\          /  \\ /    \\      \n");
    printf("  /\\  /      \\/    \\  /\\    /    \\      \\   \n");
    printf(" /  \\/            _/ /  \\  /      \\      \\    \n");
    printf("/    \\  /\\       /  /    \\/        \\      \\  \n");
    printf("      \\/  \\  _  /  /      \\        /\\      \\ \n");
    printf("         \\  \\/ \\/          \\      /  \\       \n");
    printf("          \\                \\    _/    \\  /\\   \n");
    printf("           \\    _           \\  /       \\/  \\  \n");
    printf("            \\  / \\  _        \\/             \\ \n");
    printf("             \\/   \\/ \\  _                   \\ \n");
    printf("                      \\/ \\     _             \\ \n");
    printf("                          \\   / \\   _           \n");
    printf("                           \\_/   \\_/ \\ -^----^ \n");
    printf("                                  \\_/            \n");
	
	printf("\n");
	printf("YopYop appears to a mountainous planet due to the frequent geological activity!\n");
	
	
	while (getchar() != '\n'); 
	getchar();
	
	printf("You do surface explorations, analyze surface samples with spectrometer instruments, and record other data! Gained 2 research points!\n");
	research_Points = research_Points + 2; 
	printf("Total Research = %d\n", research_Points);
	
	while (getchar() != '\n'); 
	getchar();
	
                                           
}

void surface_Xin() {
	printf("You have landed on Xin!\n"); 
	printf("You observe your surroundings...\n");
	
	while (getchar() != '\n'); 
	getchar();
	
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf(" <>        *             <>  *  * | {}  <>    *   \n");
    printf("       *                         *                \n");
    printf("                              *                   \n");
	printf(" <>        *            *  *  <>    *             \n");
	printf(" <>      =      =   <>  *  * | {}  <>    *        \n");
	printf(" <>        *{}  <             <>  *  *{}  <>    * \n");
	printf(" <>      =        *          *        >    *      \n");
	printf(" <>        *  {}  <           <>  *  * | {}  <>   \n");
	printf(" <>        *       =   <>  *  * | {}  <>    *     \n");
	printf(" <>        *  {}  <   =       =*  * | {}  <>    * \n");
	printf(" <>       =             <>  *  * | {}  <>    *    \n");
	printf(" <>        *  =       <>  *  *   <>    *          \n");
	printf(" <>      {}  <  *             <>  *  * | {}  <>   \n");
	printf(" <>     =             <>  = | {=>    *            \n");
	printf(" <>        *   =     <>  *  * <>    *             \n");
	printf(" <>   ={}  <  {}  < *      =    <>  *  * | {}  <> \n");
	printf(" <>        *             <>  *  * | {}  <>    *   \n");
	printf(" <>   {}  <   =             <> = | {}  <>    *    \n");
	printf(" <>        *        =  <>  *  * | {}  <>          \n");
	printf(" <>    {}  <    *=        =>  *  * | {>           \n");
    printf(" <>     {}  <   *          <> = | {}  <>    *     \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	printf("\n");
	printf("Xin appears to be dormant and flat, with lots of crators due to its lack of atmosphere!\n");
	
	while (getchar() != '\n'); 
	getchar();
	
	printf("You do surface explorations, analyze surface samples with spectrometer instruments, and record other data! Gained 4 research points!\n");
	research_Points = research_Points + 4; 
	printf("Total Research = %d\n", research_Points);
	
	while (getchar() != '\n'); 
	getchar();
	
}





void land_On_Body() {

	fuel_Check_Land(); 

	if (global_Orbit_Number == 0) {
		printf("Landing on YopYop...\n");
		
		while (getchar() != '\n'); 
		getchar();
		
		fuel = fuel - 200;

		
		printf("Your ship fuel has decreased by 200\n");
		printf("Current fuel:\n");
		printf("Fuel: %d\n", fuel);


		while (getchar() != '\n'); 
		getchar();
		
		surface_YopYop();
		
		}
		
	else if (global_Orbit_Number == 1) {
		printf("Landing on Xin...\n");
		
		while (getchar() != '\n'); 
		getchar();
		
		fuel = fuel - 200;
		
		printf("Your ship fuel has decreased by 200\n");
		printf("Current fuel:\n");
		printf("Fuel: %d\n", fuel);
		
		while (getchar() != '\n'); 
		getchar();
		
		surface_Xin();
		
		}
		

	while (getchar() != '\n'); 
	getchar();

}






void check_Diagnostics() {

	
	printf("Water Supplies at: %d\n", water);
	printf("Oxygen Supply at: %d\n", oxygen);
	printf("Fuel reserves at: %d\n", fuel);
	printf("\n");
	printf("Plant Farm Health at: %d\n", plant_farm_health);
	printf("Mealworm Farm Health at: %d\n", mealworm_farm_health);
	
	while (getchar() != '\n'); 
	getchar();
}



void radiation_Data() {
	int row;
	int col;
	int radiation_grid[4][4] = {
    	{38, 21, 25, 19},
        {25, 30, 28, 24},
        {12, 14, 21, 19},
        {10, 10, 16, 17}
	};
	
	printf("Last radiation data log made... 999 days ago\n");
	printf("Press any key to observe data:\n");
	
	while (getchar() != '\n'); 
	getchar(); 
	
	for (row = 0; row < 4; row++) {
		for (col = 0; col < 4; col++) {
			printf("[ %2d ]", radiation_grid[row][col]);
        }
		
        printf(" <-- HULL SECTOR %d\n", row + 1);
		while (getchar() != '\n'); 
    }
	while (getchar() != '\n'); 
    printf("Warning! Cosmic radiation hazard! Proceed to radiation shelter!\n");
	while (getchar() != '\n'); 
	printf("Warning! Solar flare activity detected! Proceed to radiation shelter!\n");
	while (getchar() != '\n'); 
	printf("Warning! Reactor shielding malfuntion! Proceed to radiation shelter!\n");
	while (getchar() != '\n'); 
	printf("Warning! Radiation Dose Rate Exceeds Maxmimum Threshold! Attempting systems reset...\n");
	while (getchar() != '\n');
	printf("System access denied, current user does not have authority! \n");
	while (getchar() != '\n');
	
	
	main();
	
}



/* main function, loops using while (1), waiting for user input for the control panel */
int main() {

	int choice;
	
	
	while (1) {
	display_Hub();
	scanf("%d", &choice);
	
	switch (choice) {
	
	
	case 1:
	orbit_Change();
	break;
	
	case 2:
	land_On_Body();
	break;
	
	case 3:
	maintain_Farm();
	break;
	
	case 4:
	mine_Asteroid();
	break;
	
	case 5:
	check_Diagnostics();
	break;
	
	case 6:
	radiation_Data();
	return 0;
	
	case 7:
	printf("Entering cyrogeneic sleep...\n");
	return 0;
	
	default:
	printf("Invalid choice! Please select options 1 - (unknown) \n");
	break;
	}
	
	}

	return 0;
}


/* END OF CODE: This is for progress report 1. Dane Nicol, 130822325, COMPE 271 */

