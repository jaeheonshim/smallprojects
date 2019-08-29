package com.jaeheonshim.piglatin;

class Translator {
    private static String[] vowels = {"a", "e", "i", "o", "u"};
    private static String[] consonants = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"};
    String translate(String input) {
        String finalphrase = "";
        String[] splitbyspaceinput = input.split("\\s+");
        for(String word : splitbyspaceinput) {
            String[] splitword = word.split("(?!^)");
            String finalword = "";

            boolean consonantvowel = false;
            boolean twoconsonants = false;
            boolean vowel = false;

            //if word starts with consonant and vowel
            for(String letter : consonants) {
                if(splitword[0].equals(letter)) {
                    for(String lettertwo : vowels) {
                        if(splitword[1].equals(lettertwo)){
                            consonantvowel = true;
                            break;
                        }
                    }
                    break;
                }
            }

            //if word starts with two consonants
            for(String letter : consonants) {
                if(splitword[0].equals(letter)) {
                    for(String lettertwo : consonants) {
                        if(splitword[1].equals(lettertwo)) {
                            twoconsonants = true;
                            break;
                        }
                    }
                    break;
                }
            }

            //if word starts with vowel
            for(String letter : vowels) {
                if(splitword[0].equals(letter)) {
                    vowel = true;
                }
            }

            if(consonantvowel) {
                for(int i = 1; i < splitword.length; i++) {
                    finalword = finalword.concat(splitword[i]);
                }
                finalword = finalword.concat(splitword[0].concat("ay "));
                finalphrase = finalphrase.concat(finalword);
            }
            else if(twoconsonants) {
                for(int i = 2; i < splitword.length; i++) {
                    finalword = finalword.concat(splitword[i]);
                }
                finalword = finalword.concat(splitword[0].concat(splitword[1].concat("ay ")));
                finalphrase = finalphrase.concat(finalword);
            }
            else if(vowel) {
                for(String letter : splitword) {
                    finalword = finalword.concat(letter);
                }
                finalword = finalword.concat("way ");
                finalphrase = finalphrase.concat(finalword);
            }
        }
        return finalphrase;
    }
}
