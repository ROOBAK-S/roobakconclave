#include <stdio.h>
#include <string.h>

struct items {
    int id;
    char name[50];
    int quantity;
    int price;
};

// Function to add items
void add(struct items *c, int size) {
    printf("Enter details in this order:\nID\nName\nQuantity\nPrice\n");
    for (int i = 0; i < size; i++) {
        printf("Item %d:\n", i + 1);
        scanf("%d", &c[i].id);
        scanf("%s", c[i].name);
        scanf("%d", &c[i].quantity);
        scanf("%d", &c[i].price);
    }
}

// Function to view inventory
void view(struct items *c, int size) {
    for (int i = 0; i < size; i++) {
        printf("Details of product %d:\n", i + 1);
        printf("ID: %d\n", c[i].id);
        printf("Name: %s\n", c[i].name);
        printf("Quantity: %d\n", c[i].quantity);
        printf("Price: %d\n", c[i].price);
    }
}

// Function to search items
void search(struct items *c, int size) {
    char search_name[50];
    printf("Enter the name of the item to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(c[i].name, search_name) == 0) {
            printf("Item found:\n");
            printf("ID: %d\n", c[i].id);
            printf("Name: %s\n", c[i].name);
            printf("Quantity: %d\n", c[i].quantity);
            printf("Price: %d\n", c[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with name '%s' not found in the inventory.\n", search_name);
    }
}

// Function to update items
void update(struct items *c, int size) {
    int update_id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &update_id);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (c[i].id == update_id) {
            printf("Enter new details for item ID %d:\n", update_id);
            printf("New Name: ");
            scanf("%s", c[i].name);
            printf("New Quantity: ");
            scanf("%d", &c[i].quantity);
            printf("New Price: ");
            scanf("%d", &c[i].price);
            printf("Item updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found in the inventory.\n", update_id);
    }
}

int main() {
    struct items c[3];

    // Initialize the first item
    c[0].id = 1;
    strcpy(c[0].name, "apple");
    c[0].quantity = 20;
    c[0].price = 50;

    // Initialize the size and allow user to add two more items
    int size = 3;

    char str[100];
    printf("What do you want to do today?\n");
    printf("Say \"Add_items\" or \"View_inventory\" or \"Search_items\" or \"Update_items\": ");
    scanf("%s", str);

    if (strcmp(str, "Add_items") == 0)
        add(c, size);
    else if (strcmp(str, "View_inventory") == 0)
        view(c, size);
    else if (strcmp(str, "Search_items") == 0)
        search(c, size);
    else if (strcmp(str, "Update_items") == 0)
        update(c, size);
    else
        printf("Invalid option. Please try again.\n");

    return 0;
}
