/*
   Session Challenge: Week 1

      Create a reaction game with
        -   x2 LDR
        -   x1 LED
*/
int ledPin    = 13;
int ldrPin[2] = {A0, A1};
int ldrThreshold[2] = {100, 100};

enum GameState
{
  NO_WINNER,
  PLAYER_1_WINS,
  PLAYER_2_WINS,
  PLAYERS_DRAW
};

GameState currentGameState = NO_WINNER;

const char* startMessage = 
"------------------------------------------\n"
"             Reaction Game\n"
"------------------------------------------\n"
"Rules:\n"
"\n"
"    When the LED lights up the first player\n" 
"    to cover the LDR with their hand wins!\n"
"\n";

void setup()
{
  Serial.begin(9600);
  Serial.print(startMessage);
  pinMode(ledPin, OUTPUT);
  delay(10000);
  digitalWrite(ledPin, HIGH);
}

void loop()
{
  if (analogRead(ldrPin[0]) < ldrThreshold[0] and  analogRead(ldrPin[1]) < ldrThreshold[1])
    currentGameState = PLAYERS_DRAW;
  else if (analogRead(ldrPin[0]) < ldrThreshold[0])
    currentGameState = PLAYER_1_WINS;
  else if (analogRead(ldrPin[1]) < ldrThreshold[1])
    currentGameState = PLAYER_2_WINS;

  if (currentGameState != NO_WINNER)
  {
    switch (currentGameState)
    {
      case PLAYER_1_WINS:
        Serial.print("Player 1 Wins!");
        break;
      case PLAYER_2_WINS:
        Serial.print("Player 2 Wins!");
        break;
      case PLAYERS_DRAW:
        Serial.print("Players DRAW!?");
        break;
    }

    Serial.print("\n\nPress Reset to Play Again\n\n");
    while (1);
  }
}
