import java.util.Scanner;
import java.util.Random;

class Hangman {
    private int lives = 7;
    private int tries = 0;
    private String target;
    private char targetArray[];
    private char guessedLetters[] = new char[26];
    private int guessedLettersCounter = 0;
    
    Hangman(String word) {
        word = word.toUpperCase();
        target = word;
        targetArray = word.toCharArray();
    }
    
    Hangman(String word, int lives) {
        this(word);
        this.lives = lives;
    }
    
    Hangman(boolean random) {
        if (random == true) {
            Random rand = new Random();
            target = Words.words[rand.nextInt(Words.words.length)].toUpperCase();
            targetArray = target.toCharArray();
        }
    }
    
    Hangman(boolean random, int lives) {
        this(random);
        this.lives = lives;
    }
    
    public void game() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to Hangman!");
        System.out.println("You have " + lives + " lives remaining.");
        System.out.println("Word: " + constructWordCompletionOutput());
        System.out.println();
        while (true) {
            System.out.print("Enter a letter: ");
            guess(Character.toUpperCase(scanner.next().charAt(0)));
            System.out.println("You have " + lives + " lives remaining.");
            System.out.print("Letters you have already guessed: ");
            for (char letter : guessedLetters) {
                System.out.print(letter + " ");
            }
            System.out.println();
            System.out.println(constructWordCompletionOutput());
            System.out.println();
            
            if (lives < 1) {
                System.out.print("Uh oh, it looks like you're out of lives. The word was: ");
                for (char letter : targetArray) {
                    System.out.print(letter);
                }
                System.out.println("\nGood Game.");
                break;
            }
            
            if (getCharsRemaining() < 1) {
                System.out.println("Congratulations!!! You guessed the word correctly!");
                System.out.print("It took you " + tries + " attempts to guess the word ");
                for (char letter : targetArray) {
                    System.out.print(letter);
                }
                System.out.println(". At the end, you had " + lives + " lives remaining.");
                System.out.println("Good work!");
                break;
            }
        }
    }
    
    private boolean[] getWordCompletionArray() {
        boolean completedChars[] = new boolean[targetArray.length];
        for (int i = 0; i < targetArray.length; i++) {
            for (int j = 0; j < guessedLetters.length; j++) {
                if (guessedLetters[j] == targetArray[i]) {
                    completedChars[i] = true;
                }
            }
        }
        return completedChars;
    }
    
    private String constructWordCompletionOutput() {
        String result = "";
        for (int i = 0; i < getWordCompletionArray().length; i++) {
            if (getWordCompletionArray()[i] == true) {
                result += "." + targetArray[i];
            } else {
                result += "._";
            }
        }
        result += ".";
        return result;
    }
    
    private int getCharsRemaining() {
        int result = 0;
        for (boolean bool : getWordCompletionArray()) {
            if (bool == true) {
                result++;
            }
        }
        return targetArray.length - result;
    }
    
    private void guess(char letter) {
        System.out.println("=====================");
        tries++;
        for (int i = 0; i < guessedLetters.length; i++) {
            if (letter == guessedLetters[i]) {
                System.out.println("You've already guessed that letter.");
                return;
            }
        }
        guessedLetters[guessedLettersCounter] = letter;
        guessedLettersCounter++;
        for (int i = 0; i < targetArray.length; i++) {
            if (targetArray[i] == letter) {
                System.out.println("Nice! You correctly guessed the letter " + letter + " in the word. Only "
                + getCharsRemaining() + " letters more to go.");
                return;
            }
        }
        System.out.println("The letter " + letter + " isn't in the word. -1 life");
        lives--;
    }
}