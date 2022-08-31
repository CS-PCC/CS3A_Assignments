# Review 03 - BlackJack

- Accept [00_review_03_black_jack](https://classroom.github.com/a/E_Y-7xL0)

---

Implement functions in `includes/black_jack/black_jack.h`

## Specifications

Your assignment is to write a single-player version of the casino card game Blackjack, also known as 21. The goal of the game Blackjack is to get cards whose total value comes closest to 21 without going over. Getting a card total over 21 is called "busting". The player will play against the dealer. There are 3 possible outcomes.

- The player comes closer to 21 than the dealer or the dealer busts but if the player did not bust -> player wins the bet amount.
- The dealer comes closer to 21 than the player or if the player's total exceeds 21 -> player loses. Note if both the player and the dealer bust, then the dealer wins. This is called the "house advantage".
- Both player and dealer have the same total and neither player busts -> tie, no money is exchanged.


At each round of play, the player will be asked to enter their bet. They will then be given 2 cards. The player will repeatedly be asked if they want to draw another card. The player can continue to draw cards while their total is less than 21. After the player's turn is over, the dealer's cards are shown. The dealer's play is always the same: the dealer will continue to draw cards if their total is less than or equal to 16.

A sample run is shown below. Assume the player starts with \$100 and the game ends when the player is down to \$0 or their amount exceeds \$1,000. Also, note the user is prompted to re-enter their bet amount if they try to bet more than they actually have.


## Instructions

Your program should have a function called draw_card that draws a random card. The function should get a random number between 1 and 13 to determine the rank of the card and another number between 1 and 4 to determine the suite of the card. The card of rank 13 corresponds to a king, the card of rank 12 corresponds to a queen, the card of rank 11 corresponds to a jack, and the card of rank 1 is an ace. In blackjack face cards (Jack, Queen, King) all count as 10 points towards the card total. The function should return the value of the card to be added to the point total. Aces can be either 11 (high) or 1 (low), depending on which is more advantageous to the player to come closest to 21 without going over. The card variable will contain the description of the card such as "Two of diamonds" or "King of hearts".

You should also have a `getSuit` and `getRank` function that takes as input an int that corresponds to a Rank or Suit and returns the string version of that rank or suit.  For example, rank 11 would have to return "Jack". Suit 3 would return "hearts".

**Note**: Your rand values should have spades = 0, clubs = 1, diamonds = 2, and hearts = 3.

**You should seed srand(333)**

**Note**: In your main, you should have a variable that keeps track of the current total for the player and another variable that keeps track of the current total for the dealer. When the draw card function is called you should pass to it a string variable called `card` and the current total. Your function `draw_card` will return the value of the card it draws and this value should be added in main to the current total. Note that the total is only used in this function to decide if an ace should count as high or low. This function does not return the total! It returns the value of the card that was drawn. You are responsible for adding this value to the total in the main. When you call the function `draw_card` you will also pass it a string called `card`. After calling the function `draw_card` this variable card will now have the description of the card, something like "Three of Diamonds". Do NOT output anything in the function draw card! All output should be done in the main.

```c++
//-------------------------------------------------------------------
//  draw_card()
//      Uses rand() to draw a card then returns the numerical
//  value and card name
//-------------------------------------------------------------------
int draw_card(string &card,                 //IN - card name
              int drawer_points);           //IN - drawer's total points
             
             
/****************************************************************
*
*  draw_card()
*_______________________________________________________________
*  Simulates the drawing of a card. Passes by reference the
*  kind of card (value and suite in string value) as well as
*  returns the card's equivalent numerical value (to be added
*  to totals in main())
*  Also reads current drawer's points to determine value of
*  aces
*_______________________________________________________________
* PRE-CONDITIONS:
*   &card : passes card info
*   drawer_points : reads current drawer's points to determine
*                   value of ace
*
* POST-CONDITIONS:
*   passes card info by reference, returns card numerical value
****************************************************************/
int draw_card (string &card,            //card info
               int drawer_points)       //current drawer's points
```

**Note**: You do not need to account for cases where you draw a 3 and then an Ace giving you a total of 14 (Ace counts here as 11) and then you draw a Queen giving you a total of 24. In real Blackjack, you would now revert the Ace back to 1 giving you a total of 14. However, this is too complicated and we will not deal with this issue. Once Ace has been counted as 11 it will stay as 11.

Things to test for:
- Player busts
- Dealer busts
- Player loses all his money (Game Over)
- Player wins (total is more than $1000)
- Program halts when appropriate


## FAQ
Q: Can the same card come up multiple times?
A: Yes. We will assume that the dealer uses multiple decks so for instance a four of clubs can come up many times in the same hand.
Q: What happens if the player gets 21 does he automatically win?
A: In real blackjack rules the dealer gets to draw even if the player has gotten a 21. If the dealer also gets a 21 then it is considered a draw.


## Example Run

```
You have $100. Enter bet: 
50
Your cards are: 
  Ten of Clubs
  Ace of Spades
Black Jack!
 
The dealer's cards are: 
  King of Hearts
  Seven of Clubs
The dealer's total is 17.
You win $50.
 
Play again? (y/n): 
y
You have $150. Enter bet: 
50
Your cards are: 
  Seven of Clubs
  Jack of Hearts
Your total is 17. Do you want another card (y/n)? 
n
 
The dealer's cards are: 
  Queen of Spades
  Two of Diamonds
The dealer draws a card.
  Five of Diamonds
The dealer's total is 17.
A draw! You get back your $50.
 
Play again? (y/n): 
y
You have $150. Enter bet: 
50
Your cards are: 
  Nine of Clubs
  Queen of Spades
Your total is 19. Do you want another card (y/n)? 
y
You draw a: 
  Five of Clubs
Your total is 24. You busted!
 
The dealer's cards are: 
  Two of Clubs
  Four of Diamonds
The dealer draws a card.
  Three of Hearts
The dealer draws a card.
  Two of Clubs
The dealer draws a card.
  Nine of Spades
The dealer's total is 20.
You lose $50.
 
Play again? (y/n): 
y
You have $100. Enter bet: 
100
Your cards are: 
  Ace of Spades
  Three of Diamonds
Your total is 14. Do you want another card (y/n)? 
y
You draw a: 
  Eight of Hearts
Your total is 22. You busted!
 
The dealer's cards are: 
  Two of Clubs
  Four of Diamonds
The dealer draws a card.
  Ten of Hearts
The dealer draws a card.
  Nine of Spades
The dealer's total is 25.
You lose $100.
 
You have $0. GAME OVER.
```
