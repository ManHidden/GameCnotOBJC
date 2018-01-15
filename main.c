#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

//INITIALIZATION
//MAPS
void Swamp();
void City();
void Castle();
void Forest();
void Well();
void Camp();
//FIGHTING
void endFight();
void continueBattle();
void startBattle();
//PLAYER
void set_PlayerHealth(int current, int max);
int get_PlayerHealth();
int get_PlayerHealthMax();
void set_PlayerMana(int current, int max);
int get_PlayerMana();
int get_PlayerManaMax();
void set_PlayerSpeedAttack(double addAttackSpeed);
double get_PlayerSpeedAttack();
void set_PlayerDeffence(int addDefence);
int get_PlayerDeffence();
void set_PlayerResistance(int addResistance);
int get_PlayerResistance();
void set_PlayerAttack(int addAttack);
int get_PlayerAttack();
void set_PlayerLevel(int addLevel);
int get_PlayerLevel();
void set_PlayerExp(int addExp);
int get_PlayerExp();
void set_PlayerAgility(int addAgility);
int get_PlayerAgility();
void set_PlayerIntelligence(int addInteligence);
int get_PlayerIntelligence();
void set_PlayerStrength(int addStrength);
int get_PlayerStrength();
void set_PlayerCrit(int addCrit);
int get_PlayerCrit();
int get_PlayerAttackPower();
void set_PlayerClass(int setClass);
int get_PlayerClass();
//PLAYER METHODS
void playerDie();
void playerTakeDamage(int damage);
void get_PlayerStats();
void playerPhysicAttack();
void playerDealDamage();
void playerMagicAttack();
void playerLevelUp();
void playerMeditation();
//PLAYER CLASS
void Warrior();
void Rogue();
void Mage();
void setClass();
//PLAYER MAGIC
void playerUseFireBall();
void playerUseIceSpike();
void playerUseHeal();
void playerUseStealHealth();
void playerUseReinforcedAttack();
//MONSTER
void set_MonsterHealth(int current, int max);
int get_MonsterHealth();
int get_MonsterHealthMax();
void set_MonsterMana(int current, int max);
int get_MonsterMana();
int get_MonsterManaMax();
void set_MonsterDamage(int min, int max);
int get_MonsterDamageMin();
int get_MonsterDamageMax();
void set_MonsterSpeedAttack(double addSpeedAttack);
double get_MonsterSpeedAttack();
void set_MonsterMagicDamage(int min, int max);
int get_MonsterMinMagicDmg();
int get_MonsterMaxMagicDmg();
void set_MonsterExp(int min, int max);
int get_MonsterExpMin();
int get_MonsterExpMax();
void set_MonsterLevel(int level);
int get_MonsterLevel();
void set_MonsterNameOfTheMonster(char *name);
char *get_MonsterNameOfTheMonster();
void set_MonsterDeffence(int addDefence);
int get_MonsterDeffence();
void set_MonsterResistance(int addResistance);
int get_MonsterResistance();
//MONSTER METHODS
void die();
int monsterTakeDamage(int damage);
void monsterPhysicAttack(int damageMin, int damageMax);
void monsterMagicAttack();
//MONSTERS
void Zombie();
void Wolf();
void Bear();
void Floater();
void Vampire();
//MONSTER MAGIC
void monsterUseFireBall();
void monsterUseIceSpike();
void monsterUseHeal();
void monsterUseStealHealth();
void monsterUseReinforcedAttack();
void monsterUseMagic();
//RANDOM
int RInt(int min, int max);
int Crit();

//MAP
char choice[100];
int haveBucket = 0; //(0) - brak wiaderka, (1) - znalezione wiaderko, (2) - wyłowiony klucz
int haveKey = 0; //Trzeba mieć klucz (1), żeby wejść do zamku
int clearSwamp = 0; //Quest ze świątyni odnośnie zabijania topielców (1) - Quest przyjęty
int swampKill = 0; //Zabite topielce
int killVampire = 0; //EndGame Quest
int forestFight = 0; //(1) - Potwory będą atakować

void Swamp(){
    if (clearSwamp == 1){
        while (swampKill <= 10){
            Floater();
            startBattle();
            swampKill ++;
        }
        clearSwamp = 2;
        printf("Ukończyłeś zadanie, wracasz do miasta");
        City();
    }
    else if (clearSwamp == 2){
        printf("Zabiłeś już wszystkie topielce. Wróć do świątyni po nagrodę.\n");
        City();
    }
    else{
        printf("Niczego więcej już tu nie ma. Wracasz do miasta.\n");
        City();
    }
}

void City(){
    printf("Co chesz teraz zrobić?\n");
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';
    if (strcmp(choice, "idz na polnoc") == 0){
        printf("Wracasz do obozu\n");
        Camp();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        printf("Tam nic nie ma\n");
        City();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        if(clearSwamp == 0){
            printf("Nie możesz tam jeszcze iść");
            City();
        }
        else{
            if(swampKill == 1){
                printf("Jesteś pewien, że chcesz tam iść? Nie będziesz mógł wyjść dopóki nie pokonasz wszystkich potworów\n");
                fgets(choice,100,stdin);
                choice[strlen(choice)-1] = '\0';
                if(strcmp(choice, "tak") == 0){
                    printf("Idziesz na bagna\n");
                    Swamp();
                }
                else if(strcmp(choice, "nie") == 0){
                    printf("Wracasz do miasta\n");
                    City();
                }
                else{
                    printf("Niepoprawna komenda\n");
                    City();
                }
            }
            else{
                Swamp();
            }
        }
    }
    else if(strcmp(choice, "idz na zachod") == 0){
        printf("Tam nic nie ma\n");
        City();
    }
    else if(strcmp(choice, "idz do swiatyni") == 0){
        if (clearSwamp == 0){
            printf("Bla... bla... bla... musisz oczyścić bagna z topielców (10). Przyjdź kiedy skończysz\n");
            clearSwamp = 1;
            City();
        }
        else if(clearSwamp == 1){
            printf("Zanim tam pójdziesz, musisz pokonać topielce\n");
            City();
        }
        else if(clearSwamp == 2){
            printf("W zamian za oczyszczenie bagna zostałeś pobogłosawiony. Twoje statystyki wzrosły\n");
            printf("Dostałeś kolejne zadanie od arcybiskupa. Na zachód od Obozu znajduje się Zamek w którym zamieszkuje potężny wampir\n");
            printf("Zostałeś poproszony o zabicie go\n");
            printf("Nie możesz odmówić\n");
            clearSwamp = 3;
            killVampire = 1;
            City();
        }
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Idziesz spać do świątyni\n");
        printf("Zregenerowałeś życie i mane\n");
        set_PlayerHealth(get_PlayerHealthMax(), get_PlayerHealthMax());
        set_PlayerMana(get_PlayerManaMax(), get_PlayerManaMax());
        City();
    }
    else if(strcmp(choice, "medytuj") == 0) {
        printf("Medytujesz...\n");
        playerMeditation();
        City();
    }
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        City();
    }
    else if(strcmp(choice, "co robic") == 0){
        printf("idz na polnoc/wschod, idz do swiatyni, idz spac, statystyki, medytuj\n");
        City();
    }
    else{
        printf("Niepoprawna komenda\n");
        City();
    }
}

void Castle(){
    printf("Zamek... zła aura... Wampir...\n");
    Vampire();
    startBattle();
    printf("Gratulacje, ukończyłeś grę!\n");
    exit(0);
}

void Forest(){
    printf("Co chesz teraz zrobić?\n");
    int bleh = RInt(1, 3);
    if(get_PlayerLevel() < 5){
        if (bleh == 3 && forestFight == 1){
            Zombie();
            startBattle();
        }
    }
    else{
        int randomInt = RInt(1,8);
        if (randomInt == 3 && forestFight == 1){
            Wolf();
            startBattle();
            Forest();
        }
        else if(randomInt == 6){
            Bear();
            startBattle();
            Forest();
        }
    }

    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Nie możesz tutaj spać! Musisz wrócić do obozu\n");
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        printf("Nie ma tam nic\n");
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz na polnoc") == 0){
        printf("Nie ma tam nic\n");
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        printf("Nie ma tam nic\n");
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz na zachod") == 0){
        printf("Wracasz do Obozu\n");
        Camp();
    }
    else if(strcmp(choice, "czekaj") == 0){
        printf("Czekasz\n");
        forestFight = 1;
        Forest();
    }
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "co robic") == 0){
        printf("idz na zachod, statystyki, czekaj\n");
        forestFight = 0;
        Forest();
    }
    else{
        printf("Nie ma co tu zwiedzać\n");
        forestFight = 0;
        Forest();
    }
}

void Well(){
    printf("Co chesz teraz zrobić?\n");
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "obejrzyj studnie") == 0){
        if (haveBucket == 0){
            printf("Znalazłeś stare wiaderko i linę\n");
            haveBucket = 1;
            Well();
        }
        else {
            printf("Niczego już tu nie ma\n");
            Well();
        }
    }
    else if(strcmp(choice, "zajrzyj do studni") == 0){
        if(haveBucket == 1){
            printf("Po kilkunastu próbach udaje Ci się wyłowić klucz ze studni\n");
            haveBucket = 2;
            haveKey = 1;
            Well();
        }
        else if( haveBucket == 2){
            printf("Niczego więcej już tam nie ma\n");
            Well();
        }
        else {
            printf("Widzisz coś świecącego na dnie\n");
            printf("ale żeby to wyłowić musisz znaleźć wiadro\n");
            Well();
        }
    }
    else if(strcmp(choice, "idz na polnoc") == 0){
        printf("Nie możesz tam iść, możesz tylko zawrócić\n");
        Well();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        printf("Nie możesz tam iść, możesz tylko zawrócić\n");
        Well();
    }
    else if(strcmp(choice, "idz na zachod") == 0){
        printf("Nie możesz tam iść, możesz tylko zawrócić\n");
        Well();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        printf("Wracasz do obozu\n");
        Camp();
    }
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        Well();
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Nie możesz tutaj spać!\n");
    }
    else if(strcmp(choice, "medytuj") == 0){
        printf("Nie mozesz sie tu skupic\n");
        Well();
    }
    else if(strcmp(choice, "co robic") == 0){
        printf("idz na poludnie, statystyki, obejrzyj studnie, zajrzyj do studni\n");
        Well();
    }
    else{
        printf("Niepoprawna komenda\n");
        Well();
    }
}

void Camp(){
    printf("Co chesz teraz zrobić?\n");
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "idz na polnoc") == 0){
        printf("Doszedłeś do zniszczonej studni\n");
        Well();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        if (get_PlayerLevel() < 5){
            printf("Strażnicy nie pozwalają Ci wejść do miasta\n");
            printf("Musisz stać się silniejszy\n");
            Camp();
        }
        else{
            if (clearSwamp == 0) {
                printf("Wchodząc do miasta zostajesz zaczepiony przez strażników\n");
                printf("Każą Ci się zgłosić do świątyni\n");
                City();
            }
            else{
                printf("Wchodzisz do miasta\n");
                City();
            }
        }
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        printf("Widzisz przed sobą wielki las, zbliżając się słyszałeś, że czyha tam wiele niebezpieczeństw\n");
        printf("Jesteś pewien, że chcesz iść dalej?\n");
        fgets(choice,100,stdin);
        choice[strlen(choice)-1] = '\0';
        if(strcmp(choice, "tak") == 0){
            Forest();
            printf("Wszedłeś do lasu, czujesz się cały czas obserwowany\n");
            if(get_PlayerLevel() < 5)
                printf("Zaczynasz się zastanawiać czy to był dobry pomysł\n");
        }
        else if(strcmp(choice, "nie") == 0){
            printf("Zawracasz\n");
            Camp();
        }
        else{
            printf("Zła odpowiedź\n");
            Camp();
        }
    }
    else if(strcmp(choice, "idz na zachod") == 0){
        if (killVampire ==  0){
            printf("Widzisz potężny zamek, emanujący straszliwą aurą. Wolisz się nie zbliżać do niego\n");
            printf("Zawracasz do obozu\n");
            Camp();
        }
        else if (killVampire == 1 && haveKey == 1){
            printf("Idziesz do zamku, czeka Cię ciężka walka. Na pewno chcesz tam iść?\n");
            fgets(choice,100,stdin);
            choice[strlen(choice)-1] = '\0';
            if(strcmp(choice, "tak") == 0){
                Castle();
            }
            else if(strcmp(choice, "nie") == 0){
                printf("Zawracasz do Obozu\n");
                Camp();
            }
        }
        else if(killVampire == 1 && haveKey == 0){
            printf("Próbujesz otworzyć bramę do zamku, ale Ci się nie udaje. Musisz znaleźć klucz\n");
            printf("Wracasz do Obozu\n");
            Camp();
        }
    }
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        Camp();
    }
    else if(strcmp(choice, "medytuj") == 0){
        printf("Medytujesz...\n");
        playerMeditation();
        Camp();
    }
    else if(strcmp(choice, "koniec") == 0){
        exit(0);
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Poszedłeś spać. Odnowiłeś zdrowie i mane\n");
        set_PlayerMana(get_PlayerManaMax(), get_PlayerManaMax());
        set_PlayerHealth(get_PlayerHealthMax(), get_PlayerHealthMax());
        Camp();
    }
    else if(strcmp(choice, "co robic") == 0){
        printf("idz na polnoc/poludnie/wschod/zachod, idz spac, statystyki, medytuj, koniec\n");
        Camp();
    }
    else{
        printf("Niepoprawna komenda\n");
        Camp();
    }
}

//MONSTER
struct Monster{
    int MonsterHealth;
    int MonsterHealthMax;
    int MonsterMana;
    int MonsterManaMax;
    int MonsterDamageMin;
    int MonsterDamageMax;
    double MonsterSpeedAttack;
    int MonsterMinMagicDmg;
    int MonsterMaxMagicDmg;
    int MonsterExpMin;
    int MonsterExpMax;
    int MonsterLevel;
    char *MonsterNameOfTheMonster;
    int MonsterDeffence;
    int MonsterResistance;
};
struct Monster monster;

//MONSTER SETTERS
void set_MonsterHealth(int current, int max){
    monster.MonsterHealth = current;
    monster.MonsterHealthMax = max;
}

void set_MonsterMana(int current, int max){
    monster.MonsterMana = current;
    monster.MonsterManaMax = max;
}

void set_MonsterDamage(int min, int max){
    monster.MonsterDamageMin = min;
    monster.MonsterDamageMax = max;
}

void set_MonsterSpeedAttack(double addSpeedAttack){
    monster.MonsterSpeedAttack += addSpeedAttack;
}

void set_MonsterMagicDamage(int min, int max){
    monster.MonsterMinMagicDmg = min;
    monster.MonsterMaxMagicDmg = max;
}

void set_MonsterExp(int min, int max){
    monster.MonsterExpMin = min;
    monster.MonsterExpMax = max;
}

void set_MonsterLevel(int level){
    monster.MonsterLevel = level;
}

void set_MonsterNameOfTheMonster(char *name){
    monster.MonsterNameOfTheMonster = name;
}

void set_MonsterDeffence(int addDefence){
    monster.MonsterDeffence += addDefence;
}

void set_MonsterResistance(int addResistance){
    monster.MonsterResistance += addResistance;
}

//MONSTER GETTERS
int get_MonsterHealth(){
    return monster.MonsterHealth;
}

int get_MonsterHealthMax(){
    return monster.MonsterHealthMax;
}

int get_MonsterMana(){
    return monster.MonsterMana;
}

int get_MonsterManaMax(){
    return monster.MonsterManaMax;
}

int get_MonsterDamageMin(){
    return monster.MonsterDamageMin;
}

int get_MonsterDamageMax(){
    return monster.MonsterDamageMax;
}

double get_MonsterSpeedAttack(){
    return monster.MonsterSpeedAttack;
}

int get_MonsterMinMagicDmg(){
    return monster.MonsterMinMagicDmg;
}

int get_MonsterMaxMagicDmg(){
    return monster.MonsterMaxMagicDmg;
}

int get_MonsterExpMin(){
    return monster.MonsterExpMin;
}

int get_MonsterExpMax(){
    return monster.MonsterExpMax;
}

int get_MonsterLevel(){
    return monster.MonsterLevel;
}

char *get_MonsterNameOfTheMonster(){
    return monster.MonsterNameOfTheMonster;
}

int get_MonsterDeffence(){
    return monster.MonsterDeffence;
}

int get_MonsterResistance(){
    return monster.MonsterResistance;
}

//MONSTER MAGIC
int monsterRequiredMana;
int monsterSpellDamage;

void monsterUseFireBall(){
    monsterRequiredMana = 20;
    monsterSpellDamage = get_MonsterLevel() * RInt( get_MonsterMinMagicDmg(), get_MonsterMaxMagicDmg() ) / (get_PlayerResistance() * 1/5);

    printf( "%s użył Kuli Ognia!\n", get_MonsterNameOfTheMonster() );
    playerTakeDamage(monsterSpellDamage);
    set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
}

void monsterUseIceSpike(){
    monsterRequiredMana = 40;
    monsterSpellDamage = get_MonsterLevel() * RInt( get_MonsterMinMagicDmg(), get_MonsterMaxMagicDmg() ) / (get_PlayerResistance() * 1/5);

    printf( "%s użył Lodowego Szpikulca!\n", get_MonsterNameOfTheMonster(), monsterSpellDamage );
    playerTakeDamage(monsterSpellDamage);
    set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
}

void monsterUseHeal(){
    monsterRequiredMana = 30;
    monsterSpellDamage = get_MonsterLevel() * RInt( get_MonsterMinMagicDmg(), get_MonsterMaxMagicDmg() ) / (get_PlayerResistance() * 1/5);

    if ( monsterSpellDamage >= get_MonsterHealthMax() - get_MonsterHealth() ){
        monsterSpellDamage = get_MonsterHealthMax() - get_MonsterHealth();
        set_MonsterHealth( get_MonsterHealth() + monsterSpellDamage, get_MonsterHealthMax() );
        printf("%s użył Uleczenia, odnowił %d puntków życia! Jego życie wynosi teraz: %d / %d\n", get_MonsterNameOfTheMonster(), monsterSpellDamage, get_MonsterHealth(), get_MonsterHealthMax() );
        printf("leczenie 1");
        set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
    }
    else{
        set_MonsterHealth( get_MonsterHealth() + monsterSpellDamage, get_MonsterHealthMax() );
        printf("%s użył Uleczenia, odnowił %d puntków życia! Jego życie wynosi teraz: %d / %d\n", get_MonsterNameOfTheMonster(), monsterSpellDamage, get_MonsterHealth(), get_MonsterHealthMax() );
        printf("Leczenie 2");
        set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
    }
}

void monsterUseStealHealth(){
    monsterRequiredMana = 15;
    monsterSpellDamage = get_MonsterLevel() * RInt( get_MonsterMinMagicDmg(), get_MonsterMaxMagicDmg() ) / (get_PlayerResistance() * 1/5);

    if ( monsterSpellDamage >= get_MonsterHealthMax() - get_MonsterHealth() ){
        monsterSpellDamage = monsterSpellDamage >= get_MonsterHealthMax() - get_MonsterHealth();
        printf("%s użył Kradzieży Życia, ukradł Ci %d puntków życia! Jego życie wynosi teraz: %d / %d\n", get_MonsterNameOfTheMonster(), monsterSpellDamage, get_MonsterHealth(), get_MonsterHealthMax() );
        set_MonsterHealth( get_MonsterHealth() + monsterSpellDamage, get_MonsterHealthMax() );
        set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
        playerTakeDamage(monsterSpellDamage);
    }
    else{
        printf("%s użył Kradzieży Życia, ukradł Ci %d puntków życia! Jego życie wynosi teraz: %d / %d\n", get_MonsterNameOfTheMonster(), monsterSpellDamage, get_MonsterHealth(), get_MonsterHealthMax() );
        set_MonsterHealth( get_MonsterHealth() + monsterSpellDamage, get_MonsterHealthMax() );
        set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
        playerTakeDamage(monsterSpellDamage);
    }
}

void monsterUseReinforcedAttack(){
    monsterRequiredMana = 20;
    monsterSpellDamage = RInt( get_MonsterDamageMin() * 3/2, get_MonsterDamageMax() * 2) / (get_PlayerDeffence() * 7/20);

    set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );

    printf( "%s użył Wzmocnionego Ataku i zadał Ci %d punktów obrażeń!\n", get_MonsterNameOfTheMonster(), monsterSpellDamage );
    playerTakeDamage(monsterSpellDamage);
}

void monsterUseMagic(){
    int typeOfAttack;

    if ( get_MonsterMana() >= 20 && get_MonsterMana() < 30 ){
        monsterUseFireBall();
    }
    else if( get_MonsterMana() >= 30 && get_MonsterMana() < 40){
        typeOfAttack = RInt(1, 2);

        if (typeOfAttack == 1){
            monsterUseFireBall();
        }
        else{
            if (strcmp(get_MonsterNameOfTheMonster(), "Zombie") == 0)
                monsterUseReinforcedAttack();
            else if(strcmp(get_MonsterNameOfTheMonster(), "Wampir") == 0)
                monsterUseStealHealth();
            else
                monsterUseHeal();
        }
    }
    else if( get_MonsterMana() >= 40){
        typeOfAttack = RInt(1, 3);

        if ( typeOfAttack == 1){
            monsterUseFireBall();
        }
        else if( typeOfAttack == 2){
            if (strcmp(get_MonsterNameOfTheMonster(), "Zombie") == 0)
                monsterUseReinforcedAttack();
            else if(strcmp(get_MonsterNameOfTheMonster(), "Wampir") == 0)
                monsterUseStealHealth();
            else
                monsterUseHeal();
        }
        else{
            monsterUseIceSpike();
        }
    }

}

//MONSTER METHODS
void die(){
    int exp = RInt(monster.MonsterExpMin, monster.MonsterExpMax);

    printf("Pokonales przeciwnika, otrzymujesz: %d punktow doswiadczenian\n", exp);
    set_PlayerExp(exp);
}

int monsterTakeDamage(int damage){
    monster.MonsterHealth -= damage;
    printf("%s ma teraz: %d / %d punktow zycia\n", monster.MonsterNameOfTheMonster, monster.MonsterHealth, monster.MonsterHealthMax);
    if (monster.MonsterHealth <= 0){
        die();
        return 1;
    }
    else{
        return 0;
    }
}

void monsterPhysicAttack(int damageMin, int damageMax){
    int damage = RInt(damageMin, damageMax) / (get_PlayerDeffence() * 7/20);
    playerTakeDamage(damage);
}

void monsterMagicAttack(){
    monsterUseMagic();
}

//MONSTER ENEMIES
void Zombie() {
    monster.MonsterNameOfTheMonster = "Zombie";
    monster.MonsterDamageMin = 10 * get_PlayerLevel();
    monster.MonsterDamageMax = 20 * get_PlayerLevel();
    int elite = RInt(1, 7);
    if (get_PlayerLevel() > 3 && elite == 3){
        int random = RInt(2, 6);
        monster.MonsterNameOfTheMonster = "Potężne Zombie";
        monster.MonsterDamageMin = 10 * get_PlayerLevel() * random;
        monster.MonsterDamageMax = 20 * get_PlayerLevel() * random;
    }
    monster.MonsterLevel = get_PlayerLevel();
    monster.MonsterHealth = 75 * get_PlayerLevel();
    monster.MonsterHealthMax = 75 * get_PlayerLevel();
    monster.MonsterMana = 30;
    monster.MonsterManaMax = 30;
    monster.MonsterMinMagicDmg = 5 * get_PlayerLevel();
    monster.MonsterMaxMagicDmg = 10 * get_PlayerLevel();
    monster.MonsterSpeedAttack = 1.1;
    monster.MonsterExpMin = 10 * elite;
    monster.MonsterExpMax = 50 * elite;
    monster.MonsterDeffence = 5 * elite;
    monster.MonsterResistance = 5 * elite;
}

void Wolf(){
    monster.MonsterNameOfTheMonster = "Wilk";
    monster.MonsterDamageMin = 15 * get_PlayerLevel();
    monster.MonsterDamageMax = 25 * get_PlayerLevel();
    int elite = RInt(1, 7);
    if (get_PlayerLevel() > 3 && elite >= 3 && elite <= 5){
        int random = RInt(2, 6);
        monster.MonsterNameOfTheMonster = "Wilk Alfa";
        monster.MonsterDamageMin = 10 * get_PlayerLevel() * random;
        monster.MonsterDamageMax = 20 * get_PlayerLevel() * random;
    }
    monster.MonsterLevel = get_PlayerLevel();
    monster.MonsterHealth = 100 * get_PlayerLevel();
    monster.MonsterHealthMax = 100 * get_PlayerLevel();
    monster.MonsterMana = 45;
    monster.MonsterManaMax = 45;
    monster.MonsterMinMagicDmg = 2 * get_PlayerLevel();
    monster.MonsterMaxMagicDmg = 4 * get_PlayerLevel();
    monster.MonsterSpeedAttack = 1.5;
    monster.MonsterExpMin = 20 * elite;
    monster.MonsterExpMax = 60 * elite;
    monster.MonsterDeffence = 8 * elite;
    monster.MonsterResistance = 3 * elite;
}

void Bear(){
    monster.MonsterNameOfTheMonster = "Niedźwiedź";
    monster.MonsterDamageMin = 15 * get_PlayerLevel();
    monster.MonsterDamageMax = 25 * get_PlayerLevel();
    int elite = RInt(1, 7);
    if (get_PlayerLevel() > 3 && elite >= 3 && elite <= 5){
        int random = RInt(2, 6);
        monster.MonsterNameOfTheMonster = "Niedźwiedź Grizli";
        monster.MonsterDamageMin = 30 * get_PlayerLevel() * random;
        monster.MonsterDamageMax = 36 * get_PlayerLevel() * random;
    }
    monster.MonsterLevel = get_PlayerLevel();
    monster.MonsterHealth = 350 * get_PlayerLevel();
    monster.MonsterHealthMax = 350 * get_PlayerLevel();
    monster.MonsterMana = 30;
    monster.MonsterManaMax = 30;
    monster.MonsterMinMagicDmg = 3 * get_PlayerLevel();
    monster.MonsterMaxMagicDmg = 6 * get_PlayerLevel();
    monster.MonsterSpeedAttack = 1.0;
    monster.MonsterExpMin = 40 * elite;
    monster.MonsterExpMax = 75 * elite;
    monster.MonsterDeffence = 10 * elite;
    monster.MonsterResistance = 5 * elite;
}

void Floater(){
    monster.MonsterNameOfTheMonster = "Utopiec";
    monster.MonsterDamageMin = 7 * get_PlayerLevel();
    monster.MonsterDamageMax = 20 * get_PlayerLevel();
    int elite = RInt(1, 7);
    if (get_PlayerLevel() > 7 && (elite >= 3 && elite <= 5)){
        int random = RInt(2, 6);
        monster.MonsterNameOfTheMonster = "Topielec";
        monster.MonsterDamageMin = 14 * get_PlayerLevel() * random;
        monster.MonsterDamageMax = 32 * get_PlayerLevel() * random;
    }
    monster.MonsterLevel = get_PlayerLevel();
    monster.MonsterHealth = 319 * get_PlayerLevel();
    monster.MonsterHealthMax = 319 * get_PlayerLevel();
    monster.MonsterMana = 0;
    monster.MonsterManaMax = 0;
    monster.MonsterMinMagicDmg = 0 * get_PlayerLevel();
    monster.MonsterMaxMagicDmg = 0 * get_PlayerLevel();
    monster.MonsterSpeedAttack = 1.4;
    monster.MonsterExpMin = 44 * elite;
    monster.MonsterExpMax = 86 * elite;
    monster.MonsterDeffence = 7 * elite;
    monster.MonsterResistance = 0 * elite;
}

void Vampire(){
    int elite = RInt(1, 7);
    monster.MonsterNameOfTheMonster = "Wampir";
    monster.MonsterDamageMin = 100 * get_PlayerLevel();
    monster.MonsterDamageMax =  200 * get_PlayerLevel();
    monster.MonsterLevel = get_PlayerLevel();
    monster.MonsterHealth = 780 * get_PlayerLevel();
    monster.MonsterHealthMax = 780 * get_PlayerLevel();
    monster.MonsterMana = 100;
    monster.MonsterManaMax = 100;
    monster.MonsterMinMagicDmg = 100 * get_PlayerLevel();
    monster.MonsterMaxMagicDmg = 200 * get_PlayerLevel();
    monster.MonsterSpeedAttack = 1.7;
    monster.MonsterExpMin = 100 * elite;
    monster.MonsterExpMax = 100 * elite;
    monster.MonsterDeffence = 100;
    monster.MonsterResistance = 140;
}

//ADDITIONAL METHODS
int RInt(int min, int max){
    srand(time( NULL ));
    return min + rand() % (max+1 - min);
}

int Crit(){
    int chance = RInt( 1, get_PlayerCrit() );
    int possibilities = RInt( 1, 100 );
    if ( possibilities <= chance ){
        /*Musi wylosować liczbę chance większą niż possibilities, żeby było trafienie krytyczne.
         */

        return 1;
    }
    else {
        return 0;
    }
}

//Player
struct Player{
    int PlayerHealth;
    int PlayerHealthMax;
    int PlayerMana;
    int PlayerManaMax;
    double PlayerSpeedAttack;
    int PlayerDeffence;
    int PlayerResistance;
    int PlayerAttack;
    int PlayerLevel;
    int PlayerExp;
    int PlayerAgility;
    int PlayerIntelligence;
    int PlayerStrength;
    int PlayerCrit;
    int PlayerClass; //1 - Warrior, 2 - Rogue, 3 - Mage
};
struct Player player;


//OTHERS
char fight[100];

//PLAYER SETTERS
void set_PlayerHealth(int current, int max){
    player.PlayerHealth = current;
    player.PlayerHealthMax = max;
}

void set_PlayerMana(int current, int max){
    player.PlayerMana = current;
    player.PlayerManaMax = max;
}

void set_PlayerSpeedAttack(double addSpeedAttack){
    player.PlayerSpeedAttack += addSpeedAttack;
}

void set_PlayerDeffence(int addDefence){
    player.PlayerDeffence += addDefence;
}

void set_PlayerResistance(int addResistance){
    player.PlayerResistance += addResistance;
}

void set_PlayerAttack(int addAttack){
    player.PlayerAttack += addAttack;
}

void set_PlayerLevel(int addLevel){
    player.PlayerLevel += addLevel;
    printf("Gratulacje! Awansowałeś, masz teraz %d poziom. Twoje statystyki wzrosły.\n", player.PlayerLevel);
    if (player.PlayerClass == 1){
        player.PlayerHealth += 20;
        player.PlayerHealthMax += 20;
        player.PlayerSpeedAttack += 0.05;
        player.PlayerDeffence += 2;
        player.PlayerAttack += 2;
        player.PlayerStrength += 1;
    }
    else if(player.PlayerClass == 2){
        player.PlayerHealth += 10;
        player.PlayerHealthMax += 10;
        player.PlayerSpeedAttack += 0.1;
        player.PlayerAttack += 1;
        player.PlayerAgility += 1;
        player.PlayerCrit += 3;
    }
    else{
        player.PlayerHealth += 10;
        player.PlayerHealthMax += 10;
        player.PlayerAttack += 1;
        player.PlayerResistance += 2;
        player.PlayerIntelligence += 3;
    }

} //Dodać zwiększanie podstawowych atrybutów

void set_PlayerExp(int addExp){
    player.PlayerExp += addExp;
    playerLevelUp();
}

void set_PlayerAgility(int addAgility){
    player.PlayerAgility += addAgility;
}

void set_PlayerIntelligence(int addInteligence){
    player.PlayerIntelligence += addInteligence;
}

void set_PlayerStrength(int addStrength){
    player.PlayerStrength += addStrength;
}

void set_PlayerCrit(int addCrit){
    player.PlayerCrit += addCrit;
}

void set_PlayerClass(int setClass){
    player.PlayerClass = setClass;
}

//PLAYER GETTERS
int get_PlayerHealth(){
    return player.PlayerHealth;
}

int get_PlayerHealthMax(){
    return player.PlayerHealthMax;
}

int get_PlayerMana(){
    return player.PlayerMana;
}

int get_PlayerManaMax(){
    return player.PlayerManaMax;
}

double get_PlayerSpeedAttack(){
    return player.PlayerSpeedAttack;
}

int get_PlayerDeffence(){
    return player.PlayerDeffence;
}

int get_PlayerResistance(){
    return player.PlayerResistance;
}

int get_PlayerAttack(){
    return player.PlayerAttack;
}

int get_PlayerLevel() {
    return player.PlayerLevel;
}

int get_PlayerExp(){
    return player.PlayerExp;
}

int get_PlayerAgility(){
    return player.PlayerAgility;
}

int get_PlayerIntelligence(){
    return player.PlayerIntelligence;
}

int get_PlayerStrength(){
    return player.PlayerStrength;
}

int get_PlayerCrit(){
    return player.PlayerCrit + (player.PlayerCrit + (player.PlayerAgility * 1/2));
}

int get_PlayerAttackPower(){
    return RInt( (player.PlayerAttack * player.PlayerStrength) * 3/4, (player.PlayerAttack * player.PlayerStrength) );
}

void get_PlayerStats(){
    printf("Obecne zdrowie: %d\n", player.PlayerHealth);
    printf("Maksymalne zdrowie: %d\n", player.PlayerHealthMax);
    printf("Obecna mana: %d\n", player.PlayerMana);
    printf("Maksymalna mana: %d\n", player.PlayerManaMax);
    printf("Predkosc ataku: %.2f\n", player.PlayerSpeedAttack);
    printf("Obrona: %d\n", player.PlayerDeffence);
    printf("Atak: %d\n", player.PlayerAttack);
    printf("Level: %d\n", player.PlayerLevel);
    printf("Exp: %d\n", player.PlayerExp);
    printf("Zrecznosc: %d\n", player.PlayerAgility);
    printf("Inteligencja: %d\n", player.PlayerIntelligence);
    printf("Sila: %d\n", player.PlayerStrength);
    printf("Szansa na uderzenie krytyczne: %d\n", get_PlayerCrit());
}

int get_PlayerClass(){
    return player.PlayerClass;
}

//PLAYER MAGIC
int playerRequiredMana;
int playerSpellDamage;

void playerUseFireBall(){
    playerRequiredMana = 20;

    if (get_PlayerClass() == 3) //Sprawdza czy klasa postaci to mag
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence(), get_PlayerLevel() * get_PlayerIntelligence() * 3 ) - (get_MonsterResistance() * 10);
    else
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() ) - (get_MonsterResistance() * 10);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana mana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś magii Kula Ognia! Zadałeś: %d punktów obrażeń!\n", playerSpellDamage);
        set_PlayerMana(get_PlayerMana() - playerRequiredMana, get_PlayerManaMax());
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(playerSpellDamage);
    }
}

void playerUseIceSpike() {
    playerRequiredMana = 40;

    if (get_PlayerClass() == 3) { //Sprawdza czy klasa postaci to mag
        playerSpellDamage = RInt(get_PlayerLevel() * get_PlayerIntelligence() * 2, get_PlayerLevel() * get_PlayerIntelligence() * 5) - (get_MonsterResistance() * 10);
    }
    else
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence(), get_PlayerLevel() * get_PlayerIntelligence() *2 ) - (get_MonsterResistance() * 10);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś magii Lodowy Szpikulec! Zadałeś %d punktów obrażeń\n", playerSpellDamage);
        set_PlayerMana(get_PlayerMana() - playerRequiredMana, get_PlayerManaMax());
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(playerSpellDamage);
    }
}

void playerUseHeal(){
    playerRequiredMana = 30;

    if (get_PlayerClass() == 3) //Sprawdza czy klasa postaci to mag
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 2, get_PlayerLevel() * get_PlayerIntelligence() * 3 );
    else
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence(), get_PlayerLevel() * get_PlayerIntelligence() * 3/2);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        if ( playerSpellDamage >= get_PlayerHealthMax() - get_PlayerHealth() ){
            playerSpellDamage = get_PlayerHealthMax() - get_PlayerHealth();
            printf("Uleczyłeś się o: %d punktów życia!\n", playerSpellDamage);
            set_PlayerHealth( get_PlayerHealth() + playerSpellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        }
        else{
            printf("Uleczyłeś się o: %d punktów życia\n", playerSpellDamage);
            set_PlayerHealth( get_PlayerHealth() + playerSpellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        }
    }
}

void playerUseStealHealth(){
    playerRequiredMana = 15;

    if (get_PlayerClass() == 2) //Sprawdza czy klasa postaci to łotr
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerAgility() * 3/2, get_PlayerLevel() * get_PlayerAgility() * 3 ) - (get_MonsterResistance() * 10);
    else
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() ) - (get_MonsterResistance() * 10);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        if ( playerSpellDamage >= get_PlayerHealthMax() - get_PlayerHealth() ){
            playerSpellDamage = get_PlayerHealthMax() - get_PlayerHealth();
            printf("Użyłeś Kradzieży życia i uleczyłeś się za: %d punktów życia!\n", playerSpellDamage);
            set_PlayerHealth( get_PlayerHealth() + playerSpellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
            monsterTakeDamage(playerSpellDamage);
        }
        else{
            printf("Użyłeś Kradzieży życia i uleczyłeś się za: %d punktów życia!\n", playerSpellDamage);
            set_PlayerHealth( get_PlayerHealth() + playerSpellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
            monsterTakeDamage(playerSpellDamage);
        }
    }
}

void playerUseReinforcedAttack(){
    playerRequiredMana = 30;

    if (get_PlayerClass() == 1) //Sprawdza czy klasa postaci to wojownik
        playerSpellDamage = RInt( get_PlayerAttackPower() * 2, get_PlayerAttackPower() * 4 ) - (get_MonsterDeffence() * 7/20);
    else
        playerSpellDamage = RInt( get_PlayerAttackPower(), get_PlayerAttackPower() * 2) - (get_MonsterDeffence() * 7/20);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś wzmocnionego ataku i zadałeś: %d punktów obrażeń!\n", playerSpellDamage);
        set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(playerSpellDamage);
    }
}

//PLAYER METHODS
void playerDie(){
    printf("Zostałeś pokonany, koniec gry!\n");
    exit(0);
}

void playerTakeDamage(int damage){
    player.PlayerHealth -= damage;
    printf("%s zadał Ci: %d punktów obrażeń!\n", get_MonsterNameOfTheMonster(), damage);
    printf("Twoje zdrowie wynosi teraz: %d / %d\n", player.PlayerHealth, player.PlayerHealthMax);
    if (player.PlayerHealth < 0){
        playerDie();
    }
}

void playerPhysicAttack(){
    int damage = RInt( (player.PlayerAttack * player.PlayerStrength) * 3/4, (player.PlayerAttack * player.PlayerStrength) ) / ( get_MonsterDeffence() * 7/20);

    if(Crit() == 1){
        damage *= 2;
        printf("Uderzenie krytyczne! Zadałeś: %d punktów obrażeń!\n", damage);
        monsterTakeDamage(damage);
    }
    else{
        printf("Zadałeś: %d punktów obrażeń!\n", damage);
        monsterTakeDamage(damage);
    }
};

void playerDealDamage(){
    printf("Co chcesz teraz zrobic?\n");
    fgets(fight,100,stdin);
    fight[strlen(fight)-1] = '\0';

    if(strcmp(fight, "atakuj") == 0){
        printf("Atakujesz mieczem\n");
        playerPhysicAttack();
    }
    else if(strcmp(fight, "magia" ) == 0 && get_PlayerMana() >= 15){
        playerMagicAttack();
    }
    else if(strcmp(fight, "magia") == 0 && get_PlayerMana() < 15){
        printf("Nie masz many\n");
        playerDealDamage();
    }
    else{
        printf("Zła komenda\n");
        playerDealDamage();
    }
}

void playerMagicAttack(){
    printf("Jakiego zaklęcia chciałbyś użyć?\n");
    fgets(fight,100,stdin);
    fight[strlen(fight)-1] = '\0';

    if (strcmp(fight, "kula ognia") == 0){
        playerUseFireBall();
    }
    else if (strcmp(fight, "lodowy szpikulec") == 0){
        playerUseIceSpike();
    }
    else if (strcmp(fight, "uleczenie") == 0){
        playerUseHeal();
    }
    else if (strcmp(fight, "kradziez zycia") == 0){
        playerUseStealHealth();
    }
    else if (strcmp(fight, "wzmocniony atak") == 0){
        playerUseReinforcedAttack();
    }
    else if (strcmp(fight, "pomoc") == 0){
        printf("Dostępne komendy to: kula ognia, lodowy szpikulec, uleczenie, kradziez zycia, wzmocniony atak\n");
        playerMagicAttack();
    }
    else{
        printf("Podałeś złą komendę, spróbuj ponownie\n");
        playerDealDamage();
    }
}

void playerLevelUp(){
    if (player.PlayerExp > 100){
        set_PlayerLevel(1);
    }
    else if (player.PlayerExp > 100 && player.PlayerExp < 200){
        set_PlayerLevel(2);
    }
}

void playerMeditation() {
    int statsUp = RInt(1, 10);
    if (statsUp >= 5 && statsUp <= 7) {
        printf("Poczasz medytacji udało Ci się podnieść poziom swoich umiejętnośći\n");
        if (get_PlayerClass() == 1) {
            player.PlayerStrength += 3;
            player.PlayerAgility += 2;
            player.PlayerAgility += 1;
            player.PlayerCrit += 1;
            player.PlayerAttack += 1;
            player.PlayerHealth += 50;
            player.PlayerHealthMax += 50;
            player.PlayerMana += 3;
            player.PlayerManaMax += 3;
            player.PlayerDeffence += 2;
            player.PlayerResistance += 1;
        } else if (get_PlayerClass() == 2) {
            player.PlayerAttack += 1;
            player.PlayerStrength += 2;
            player.PlayerAgility += 3;
            player.PlayerIntelligence += 1;
            player.PlayerHealth += 30;
            player.PlayerHealthMax += 30;
            player.PlayerMana += 5;
            player.PlayerManaMax += 5;
            player.PlayerCrit += 3;
            player.PlayerDeffence += 1;
            player.PlayerResistance += 1;
        } else {
            player.PlayerIntelligence += 3;
            player.PlayerAgility += 1;
            player.PlayerStrength += 1;
            player.PlayerAttack += 1;
            player.PlayerMana += 15;
            player.PlayerManaMax += 15;
            player.PlayerHealth += 15;
            player.PlayerHealthMax += 15;
            player.PlayerResistance += 2;
            player.PlayerDeffence += 1;
        }
    }
}

//PLAYER CLASS
void Warrior() {
    player.PlayerHealth += 50;
    player.PlayerHealthMax += 50;
    player.PlayerStrength += 5;
    player.PlayerClass = 1;
}

void Rogue() {
    player.PlayerHealth -= 20;
    player.PlayerHealthMax -= 20;
    player.PlayerCrit += 5;
    player.PlayerSpeedAttack += 0.2;
    player.PlayerClass = 2;
}

void Mage() {
    player.PlayerHealth -= 30;
    player.PlayerHealthMax -= 30;
    player.PlayerMana += 30;
    player.PlayerManaMax += 30;
    player.PlayerIntelligence += 5;
    player.PlayerClass = 3;
}

void setClass() {
    char choice[100];

    printf("Wybierz swoja klase (podaj odpowiednia cyfre)\n");
    printf("1 - Wojownik\n2 - Lotr\n3 - Mag\n");
    fgets(choice, 100, stdin);
    choice[strlen(choice) - 1] = '\0';

    if (strcmp(choice, "1") == 0) {
        printf("Wybrales Wojownika, powodzenia!\n");
        Warrior();
    } else if (strcmp(choice, "2") == 0) {
        printf("Wybrales Lotra, powodzenia!\n");
        Rogue();
    } else if (strcmp(choice, "3") == 0) {
        printf("Wybrales maga, powodzenia!\n");
        Mage();
    } else {
        printf("Wybierz jeszcze raz\n");
        setClass();
    }
}

//FIGHTING
void endFight(){
    printf("Koniec walki\n");
    printf("-------------------------------------------------------------\n");
}

void continueBattle(){
    double attack = RInt(1, 2);

    if (get_MonsterHealth() > 0 && get_PlayerHealth() > 0){
        if(get_PlayerSpeedAttack() >= get_MonsterSpeedAttack() ){
            playerDealDamage();
            if (get_MonsterHealth() > 0){
                if (attack == 1 && get_MonsterMana() > 15 ){
                    monsterMagicAttack();
                }
                else{
                    monsterPhysicAttack(get_MonsterDamageMin(), get_MonsterDamageMax());
                }
            }
            printf("-------------------------------------------------------------\n");
            continueBattle();
        }
        else{
            if (get_MonsterHealth() > 0){
                if (attack == 1 && get_MonsterMana() > 15 ){
                    monsterPhysicAttack(get_MonsterDamageMin(), get_MonsterDamageMax());
                }
                else{
                    monsterPhysicAttack(get_MonsterDamageMin(), get_MonsterDamageMax());
                }
            }
            printf("-------------------------------------------------------------\n");
            playerDealDamage();
            continueBattle();
        }
    }
    else{
        endFight();
    }
}

void startBattle(){
    printf("-------------------------------------------------------------\n");
    printf("Zostales zaatakowany przez: %s\n", get_MonsterNameOfTheMonster());
    printf("-------------------------------------------------------------\n");
    continueBattle();
}

int main() {
    player.PlayerHealth = 100;
    player.PlayerHealthMax = 100;
    player.PlayerMana = 30;
    player.PlayerManaMax = 30;
    player.PlayerSpeedAttack = 1.0;
    player.PlayerDeffence = 5;
    player.PlayerResistance = 5;
    player.PlayerAttack = 5;
    player.PlayerLevel = 1;
    player.PlayerExp = 0;
    player.PlayerAgility = 5;
    player.PlayerIntelligence = 5;
    player.PlayerStrength = 5;
    player.PlayerCrit = 1;

    setClass();

    printf("Witaj w Gothic 8 nie arkania\n");
    printf("Twoja przygoda zaczyna sie w zrujnowanym obozowisku,\n");
    printf("Byles jencem wojennym a obozowisko Twoich wrogow zostalo zaatakowane.\n");
    printf("Budzisz sie rano i jedyne co pamietasz to tajemnicza postac w kapturze,\n");
    printf("ktora Cie oswobodzila.\n");

    Camp();

    return 0;
}