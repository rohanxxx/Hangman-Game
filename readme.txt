* The Game Of Hangman

    Write a console version of the game of Hangman. Implement atleast basic
    version of Hangman game.

    * The Basic Version:

    - The Basic Version does not require you to draw gallows, noose, or
      hangman. In the Basic Version, the player chooses level easy, medium, or
      hard word to guess. Easy words have at most 5 letters; medium words have
      between 6 to 11 letters; and hard words have 12 or more letters. You
      must represent the secret word to the player. While the player is still
      "alive," the player enters a letter. If the letter is not in the word,
      tell the player and subtract 1 from the player's remaining chances. You
      will need to keep track of the letters the player guessed that are not
      in the word. Before each turn, show the player this list of letters. If
      the player uncovers the secret word before using up thier chances, then
      the player wins the game. If the player runs out of chances before
      revealing the entire secre word, then the player lose.

    * Implementation Requirements:

    - Prompt the player to select the level of difficulty.
    - Display the secret word in such a way that the player will know how many
      letters are in this word and which letters were found.
    - Display a list of wrong letters that player has choosed.
    - Display the number of chances that the player has left. But different
      level should have different chance counts.
    - Allow the player to enter a letter that was previously used; this does
      not change the number of chances remaining.
    - Determine whether the player has won or lost, and let them know.
