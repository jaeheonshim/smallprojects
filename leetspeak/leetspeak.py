text = input("Input the text you would like to convert to L33t Speak: ")
mode = input("Enter the mode (0: Convert only distinctly readable letters, 1: Convert all letters): ")

while mode != "0" and mode != "1":
    print("Please enter a valid mode (0 or 1)")
    mode = input("Enter the mode (0: Convert only distinctly readable letters, 1: Convert all letters): ")

if mode == "0":
    newtext = text.lower()
    newtext = newtext.replace("a", "4")
    newtext = newtext.replace("e", "3")
    newtext = newtext.replace("i", "|")
    newtext = newtext.replace("l", "1")
    newtext = newtext.replace("o", "0")
    newtext = newtext.replace("s", "5")
    newtext = newtext.replace("t", "7")
    print(newtext)
elif mode == "1":
    newtext = text.lower()
    newtext = newtext.replace("a", "4")
    newtext = newtext.replace("b", "|3")
    newtext = newtext.replace("c", "(")
    newtext = newtext.replace("d", "|)")
    newtext = newtext.replace("e", "3")
    newtext = newtext.replace("f", "|=")
    newtext = newtext.replace("g", "6")
    newtext = newtext.replace("h", "|-|")
    newtext = newtext.replace("i", "|")
    newtext = newtext.replace("j", "9")
    newtext = newtext.replace("k", "|<")
    newtext = newtext.replace("l", "1")
    newtext = newtext.replace("m", "|v|")
    newtext = newtext.replace("n", "|/|")
    newtext = newtext.replace("o", "0")
    newtext = newtext.replace("p", "|*")
    newtext = newtext.replace("q", "O,")
    newtext = newtext.replace("r", "|2")
    newtext = newtext.replace("s", "5")
    newtext = newtext.replace("t", "7")
    newtext = newtext.replace("u", "|_|")
    newtext = newtext.replace("v", "|/")
    newtext = newtext.replace("w", "|/|/")
    newtext = newtext.replace("x", "><")
    newtext = newtext.replace("y", "`/")
    newtext = newtext.replace("z", "2")
    print(newtext)
