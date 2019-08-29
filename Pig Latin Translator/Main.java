package com.jaeheonshim.piglatin;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Translator translator = new Translator();
        System.out.print("Enter text to be translated into pig latin: ");
        System.out.println(translator.translate(scanner.nextLine()));
    }
}
