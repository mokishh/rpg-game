#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void battle(int playerHealth, int playerMana, int playerStrength) {
    int enemyLevel = rand() % 10 + 1;
    int enemyHealth = enemyLevel * 10;
    int damage;

    printf("\033[2J\033[H");
    printf("You are in battle!\n");

    while (enemyHealth > 0) {
        printf("\n--------------------------------------------------------------\n");
        printf("The enemy is level %d\n", enemyLevel);
        printf("The enemy has %d health\n", enemyHealth);
        printf("Type 1 to attack, 2 to defend, 3 to super attack, 4 to drink potion: ");

        int choice;
        int enemyChoice = rand() % 2 + 1;

        scanf("%d", &choice);

        if (choice == 1) {
            if (enemyChoice == 2) {
                printf("The enemy defended!\n");
            } else {
                damage = rand() % 10 + 1;
                printf("You dealt %d damage!\n", damage * playerStrength);
                enemyHealth -= damage * playerStrength;
            }
        } else if (choice == 2) {
            printf("You defended!\n");
            continue;
        } else if (choice == 3) {
            if (playerMana != 50) {
                printf("You don't have enough mana!\n");
                continue;
            }
            damage = rand() % 30 + 10;
            printf("You dealt %d damage!\n", damage * playerStrength);
            enemyHealth -= damage * playerStrength;
            playerMana -= 50;
        } else if (choice == 4) {
            printf("Choose a potion: ");
            printf("[1] Health Potion\n[2] Strength Potion\n[3] Poison Potion\n");

            int potionChoice;
            scanf("%d", &potionChoice);

            switch (potionChoice) {
                case 1:
                    playerHealth += 50;
                    if (playerHealth > 100) {
                        playerHealth = 100;
                    }
                    break;
                case 2:
                    playerStrength += 2;
                    break;
                case 3:
                    enemyHealth -= 50;
                    if (enemyHealth < 0) {
                        enemyHealth = 0;
                    }
                    break;
            }
        }

        if (enemyHealth <= 0) {
            printf("Enemy defeated!\n");
            return;
        }

        printf("\n--------------------------------------------------------------\n");
        printf("Enemy turn\n");

        if (enemyChoice == 1) {
            switch (enemyLevel) {
                case 1:
                    damage = rand() % 5 + 1;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 2:
                    damage = rand() % 10 + 5;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 3:
                    damage = rand() % 20 + 10;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 4:
                    damage = rand() % 30 + 15;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 5:
                    damage = rand() % 35 + 20;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 6:
                    damage = rand() % 40 + 25;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 7:
                    damage = rand() % 45 + 30;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 8:
                    damage = rand() % 50 + 30;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 9:
                    damage = rand() % 55 + 35;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
                case 10:
                    damage = rand() % 60 + 40;
                    if (choice == 2) {
                        damage /= 2;
                    }
                    printf("The enemy dealt %d damage!\n", damage);
                    playerHealth -= damage;
                    break;
            }

            printf("The enemy dealt %d damage!\n", damage);
            playerHealth -= damage;

            if (playerHealth <= 0) {
                playerHealth = 0;
                printf("You have been defeated!\n");
                return;
            }
        }
    }
}

int shop(int coins) {
    printf("\033[2J\033[H");
    printf("Welcome to the shop!\n\n");

    printf("[1] Healing potion (10 coins)\n");
    printf("[2] Mana potion (10 coins)\n");
    printf("[3] Strength potion (10 coins)\n");
    printf("[4] Poison potion (10 coins)\n\n");

    printf("You have %d coins.\n\n", coins);

    int choice;
    printf("> ");
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
    int playerMana = 0;
    int playerStrength = 1;

    int coins = 50;

    int healthPotion = 0;
    int manaPotion = 0;
    int strengthPotion = 0;
    int poisonPotion = 0;

    while (1) {
        printf("\033[2J\033[H");
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
            battle(playerHealth, playerMana, playerStrength);
        } else if (choice == 3) {
            printf("\033[2J\033[H");
            printf("\nInventory:\n");
            printf("Health potion: %d\n", healthPotion);
            printf("Mana potion: %d\n", manaPotion);
            printf("Strength potion: %d\n", strengthPotion);
            printf("Poison potion: %d\n", poisonPotion);
            printf("\n[1] Use potion\n[2] Exit\n> ");

            int potionChoice;
            scanf("%d", &potionChoice);

            if (potionChoice == 1) {
                printf("\nWhich potion would you like to use?\n");
                printf("[1] Health potion\n[2] Mana potion\n[3] Strength potion\n[4] Poison potion\n> ");

                int potionType;
                scanf("%d", &potionType);

                switch (potionType) {
                    case 1:
                        healthPotion--;
                        printf("Health potion used.\n");
                        playerHealth += 50;
                        if (playerHealth > 100) {
                            playerHealth = 100;
                        }
                        break;

                    case 2:
                        manaPotion--;
                        printf("Mana potion used.\n");
                        playerMana += 10;
                        break;

                    case 3:
                        strengthPotion--;
                        printf("Used only in battle.\n");
                        break;

                    case 4:
                        poisonPotion--;
                        printf("Used only in battle.\n");
                        break;
                        }
            } else if (potionChoice == 2) {
                continue;
            }
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
