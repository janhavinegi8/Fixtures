#include<stdio.h>
int main()
int numTeams;
    printf("Enter the number of teams: ");
    scanf("%d", &numTeams);

    int numMatches = numTeams - 1;
    int numRounds = 0;
    while (numMatches > 0) {
        numMatches /= 2;
        numRounds++;
    }

    int totalMatches = (1 << numRounds) - 1;
    int matchesPerRound = numTeams / 2;

    printf("Fixture for the knockout tournament:\n");
    for (int round = 1; round <= numRounds; round++) {
        printf("Round %d:\n", round);
        for (int match = 1; match <= matchesPerRound; match++) {
            int team1 = (totalMatches + match) % numTeams + 1;
            int team2 = (totalMatches - match) % numTeams + 1;
            printf("Match %d: Team %d vs Team %d\n", match, team1, team2);
        }
        totalMatches /= 2;
        matchesPerRound /= 2;
    }

    return 0;
}
