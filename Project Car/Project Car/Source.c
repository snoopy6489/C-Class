#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Makes Visuial Studio ignore the _s.
#pragma warning(disable : 4996)

/*
0 = Not available for rental.
1 = Available for rental.
*/

//Define the struct
typedef struct {
    char make[50];
    char model[50];
    char license_plate[20];
    int year;
    int available;
} Vehicle;

//Variable Declaration
#define MAX_VEHICLES 300
Vehicle rental_cars[MAX_VEHICLES];
int vehicle_count = 0;

//Declaring the functions
void add_vehicle();
void delete_vehicle();
void search_vehicle();
void rent_vehicle();
void return_vehicle();
void list_all_vehicles();
void list_available_vehicles();
void save_vehicle_database();
void load_vehicle_database();
void printMenu();

//Funcntion code
void add_vehicle() {
    if (vehicle_count >= MAX_VEHICLES) {
        printf("Can not add any more vehicles to the list.\n");
        return;
    }
    printf("If the make or the model has a space please enter it with a -.\n");
    printf("Enter make: ");
    scanf("%s", rental_cars[vehicle_count].make);
    printf("Enter model: ");
    scanf("%s", rental_cars[vehicle_count].model);
    printf("Enter license plate: ");
    scanf("%s", rental_cars[vehicle_count].license_plate);
    printf("Enter year: ");
    scanf("%d", &rental_cars[vehicle_count].year);
    rental_cars[vehicle_count].available = 1;
    vehicle_count++;
    printf("Vehicle added successfully.\n");
}

void delete_vehicle() {
    char plate_to_delete[20];
    int found = 0;
    printf("Enter the license plate of the vehicle to delete: ");
    scanf("%s", plate_to_delete);
    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(rental_cars[i].license_plate, plate_to_delete) == 0) {
            for (int j = i; j < vehicle_count - 1; j++) {
                rental_cars[j] = rental_cars[j + 1];
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Vehicle with plate '%s' was not found.\n", plate_to_delete);
    }
    else {
        vehicle_count--;
        printf("Vehicle with plate '%s' has been removed.\n", plate_to_delete);
    }
}

void search_vehicle() {
    int choice;
    char search[50];
    printf("\nSearch for a Vehicle\n");
    printf("1. Search by make\n");
    printf("2. Search by model\n");
    printf("3. Search by license plate\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Enter make: ");
        scanf("%s", search);
        break;
    case 2:
        printf("Enter model: ");
        scanf("%s", search);
        break;
    case 3:
        printf("Enter license plate: ");
        scanf("%s", search);
        break;
    default:
        printf("Invalid choice.\n");
        return;
    }
    int found = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < vehicle_count; i++) {
        if ((choice == 1 && strcmp(rental_cars[i].make, search) == 0) ||
            (choice == 2 && strcmp(rental_cars[i].model, search) == 0) ||
            (choice == 3 && strcmp(rental_cars[i].license_plate, search) == 0)) {
            printf("Make: %s, Model: %s, License Plate: %s, Year: %d, Available: %s\n",
                rental_cars[i].make, rental_cars[i].model, rental_cars[i].license_plate,
                rental_cars[i].year, rental_cars[i].available ? "Yes" : "No");
            found = 1;
        }
    }
    if (!found) {
        printf("No vehicles found matching the search query.\n");
    }
}

void rent_vehicle() {
    char plate_rent[20];
    int found = 0;
    printf("Enter the license plate of the vehicle you would like to rent: ");
    scanf("%s", plate_rent);
    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(rental_cars[i].license_plate, plate_rent) == 0) {
            if (rental_cars[i].available) {
                rental_cars[i].available = 0;
                printf("Vehicle with license plate '%s' rented successfully.\n", plate_rent);
            }
            else {
                printf("Vehicle with license plate '%s' is unavailable\n", plate_rent);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Vehicle with license plate '%s' not found.\n", plate_rent);
    }
}

void return_vehicle() {
    char plate_return[20];
    int found = 0;
    printf("Enter the license plate of the vehicle you would like to return: ");
    scanf("%s", plate_return);
    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(rental_cars[i].license_plate, plate_return) == 0) {
            if (!rental_cars[i].available) {
                rental_cars[i].available = 1;
                printf("Vehicle with plate number '%s' has been returned successfully.\n", plate_return);
            }
            else {
                printf("Vehicle with plate number '%s' had been returend already.\n", plate_return);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Vehicle with license plate '%s' not found.\n", plate_return);
    }
}

void list_all_vehicles() {
    printf("\nList of All Vehicles:\n");
    if (vehicle_count == 0) {
        printf("No vehicles in the database.\n");
        return;
    }
    for (int i = 0; i < vehicle_count; i++) {
        printf("Vehicle %d:\n", i + 1);
        printf("Make: %s\n", rental_cars[i].make);
        printf("Model: %s\n", rental_cars[i].model);
        printf("License Plate: %s\n", rental_cars[i].license_plate);
        printf("Year: %d\n", rental_cars[i].year);
        printf("Available: %s\n", rental_cars[i].available ? "Yes" : "No");
        printf("\n");
    }
}

void list_available_vehicles() {
    printf("\nList of Available Vehicles:\n");
    int available = 0;

    for (int i = 0; i < vehicle_count; i++) {
        if (rental_cars[i].available) {
            available++;
        }
    }
    if (available == 0) {
        printf("No available vehicles are in the database.\n");
        return;
    }
    for (int i = 0; i < vehicle_count; i++) {
        if (rental_cars[i].available) {
            printf("Vehicle %d:\n", i + 1);
            printf("Make: %s\n", rental_cars[i].make);
            printf("Model: %s\n", rental_cars[i].model);
            printf("License Plate: %s\n", rental_cars[i].license_plate);
            printf("Year: %d\n", rental_cars[i].year);
            printf("\n");
        }
    }
}

void save_vehicle_database() {
    FILE* file;
    file = fopen("vehicle.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < vehicle_count; i++) {
        fprintf(file, "%s,%s,%s,%d,%d\n", rental_cars[i].make, rental_cars[i].model,
            rental_cars[i].license_plate, rental_cars[i].year, rental_cars[i].available);
    }
    fclose(file);
    printf("Vehicle data saved to the file successfully.\n");
}

void load_vehicle_database() {
    FILE* file;
    file = fopen("vehicle.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    vehicle_count = 0;
    while (!feof(file)) {
        if (fscanf(file, "%[^,],%[^,],%[^,],%d,%d\n", rental_cars[vehicle_count].make,
            rental_cars[vehicle_count].model, rental_cars[vehicle_count].license_plate,
            &rental_cars[vehicle_count].year, &rental_cars[vehicle_count].available) == 5) {
            vehicle_count++;
        }
    }
    fclose(file);
    printf("Vehicle data loaded from file successfully.\n");
}

void printMenu() {
    printf("\nVehicle Rental System\n");
    printf("1. Add a Vehicle\n");
    printf("2. Delete a Vehicle\n");
    printf("3. Search for a Vehicle\n");
    printf("4. Rent Out a Vehicle\n");
    printf("5. Return a Vehicle\n");
    printf("6. List All Vehicles\n");
    printf("7. List Available Vehicles\n");
    printf("8. Save the list of vehicles.\n");
    printf("9. Load the list of vehicles.\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

//Main function. 
void main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_vehicle();
            break;
        case 2:
            delete_vehicle();
            break;
        case 3:
            search_vehicle();
            break;
        case 4:
            rent_vehicle();
            break;
        case 5:
            return_vehicle();
            break;
        case 6:
            list_all_vehicles();
            break;
        case 7:
            list_available_vehicles();
            break;
        case 8:
            save_vehicle_database();
            break;
        case 9:
            load_vehicle_database();
            break;
        case 10:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Enter 1-10.\n");
        }
    } while (choice != 10);
}