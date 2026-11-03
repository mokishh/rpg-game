
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void battle(int *playerHealth) {
    int enemyLevel = rand() % 10 + 1;
    int enemyHealth = enemyLevel * 10;

    printf("You are in battle!\n");

    while (enemyHealth > 0) {
        printf("\n--------------------------------------------------------------\n");
        printf("The enemy is level %d\n", enemyLevel);
        printf("The enemy has %d health\n", enemyHealth);
        printf("Type 1 to attack, 2 to defend: ");

        int choice;
        int enemyChoice = rand() % 2 + 1;

        scanf("%d", &choice);

        if (choice == 1) {
            if (enemyChoice == 2) {
                printf("The enemy defended!\n");
            } else {
                int damage = rand() % 10 + 1;
                printf("You dealt %d damage!\n", damage);
                enemyHealth -= damage;
            }
        } else if (choice != 2) {
            printf("Invalid choice!\n");
            continue;
        }

        if (enemyHealth <= 0) {
            printf("Enemy defeated!\n");
            break;
        }

        printf("\n--------------------------------------------------------------\n");
        printf("Enemy turn\n");

        if (enemyChoice == 1) {
            int damage = rand() % 10 + 1;

            if (choice == 2) {
                damage /= 2;
            }

            printf("The enemy dealt %d damage!\n", damage);
            *playerHealth -= damage;

            if (*playerHealth <= 0) {
                *playerHealth = 0;
                printf("You have been defeated!\n");
                return;
            }
        }
    }
}

int shop(int coins) {
    system("clear");
    printf("Welcome to the shop!\n");

    printf("[1] Healing potion (10 coins)\n");
    printf("[2] Mana potion (10 coins)\n");
    printf("[3] Strength potion (10 coins)\n");
    printf("[4] Poison potion (10 coins)\n\n");

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice!\n");
        return 0;
    }

    if (coins < 10) {
        printf("You don't have enough coins!\n");
        return 0;
    }

    switch (choice) {
        case 1:
            printf("You bought a healing potion!\n");
            return 1;
        case 2:
            printf("You bought a mana potion!\n");
            return 2;
        case 3:
            printf("You bought a strength potion!\n");
            return 3;
        case 4:
            printf("You bought a poison potion!\n");
            return 4;
    }

    return 0;
}

int main(void) {
    srand(time(NULL));

    printf("Welcome to the game!\n");

    int playerLevel = 0;
    int playerHealth = 100;
    int coins = 50;

    int healthPotion = 0;
    int manaPotion = 0;
    int strengthPotion = 0;
    int poisonPotion = 0;

    while (1) {
        printf("----------------------------------------------\n");
        printf("Player level: %d\n", playerLevel);
        printf("Player health: %d\n", playerHealth);

        printf("\n[1] Open shop\n[2] Battle\n[3] See inventory\n[4] Exit\n");

        int choice;
        printf("\n> ");
        scanf("%d", &choice);

        if (choice == 1) {
            switch (shop(coins)) {
                case 1:
                    healthPotion++;
                    coins -= 10;
                    break;
                case 2:
                    manaPotion++;
                    coins -= 10;
                    break;
                case 3:
                    strengthPotion++;
                    coins -= 10;
                    break;
                case 4:
                    poisonPotion++;
                    coins -= 10;
                    break;
            }
        } else if (choice == 2) {
            battle(&playerHealth);
        } else if (choice == 3) {
            printf("\nInventory:\n");
            printf("Coins: %d\n", coins);
            printf("Health potion: %d\n", healthPotion);
            printf("Mana potion: %d\n", manaPotion);
            printf("Strength potion: %d\n", strengthPotion);
            printf("Poison potion: %d\n", poisonPotion);
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
