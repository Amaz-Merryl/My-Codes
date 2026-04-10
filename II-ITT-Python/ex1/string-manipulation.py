def string_copy(s):
    result = ""
    for ch in s:
        result = result + ch
    return result


def string_concat(s1, s2):
    result = ""
    for ch in s1:
        result = result + ch
    for ch in s2:
        result = result + ch
    return result


def string_length(s):
    count = 0
    for i in s:
        count += 1
    return count


def to_lower(s):
    result = ""
    for ch in s:
        ascii_val = ord(ch)
        if ascii_val >= 65 and ascii_val <= 90:   # A-Z
            result = result + chr(ascii_val + 32)
        else:
            result = result + ch
    return result


def to_upper(s):
    result = ""
    for ch in s:
        ascii_val = ord(ch)
        if ascii_val >= 97 and ascii_val <= 122:  # a-z
            result = result + chr(ascii_val - 32)
        else:
            result = result + ch
    return result


def find_char(s, key):
    index = 0
    for ch in s:
        if ch == key:
            return index
        index += 1
    return -1


def find_substring(s, sub):
    len_s = string_length(s)
    len_sub = string_length(sub)

    for i in range(len_s - len_sub + 1):
        match = True
        for j in range(len_sub):
            if s[i + j] != sub[j]:
                match = False
                break
        if match:
            return i
    return -1


def reverse_string(s):
    result = ""
    i = string_length(s) - 1
    while i >= 0:
        result = result + s[i]
        i -= 1
    return result


# -------- MENU --------
while True:
    print("\n--- STRING MANIPULATION MENU ---")
    print("1. Copy")
    print("2. Concatenation")
    print("3. Length")
    print("4. To Lower Case")
    print("5. To Upper Case")
    print("6. Find Character")
    print("7. Find Substring")
    print("8. Reverse String")
    print("9. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        s = input("Enter string: ")
        print("Copied String:", string_copy(s))

    elif choice == 2:
        s1 = input("Enter first string: ")
        s2 = input("Enter second string: ")
        print("Concatenated String:", string_concat(s1, s2))

    elif choice == 3:
        s = input("Enter string: ")
        print("Length:", string_length(s))

    elif choice == 4:
        s = input("Enter string: ")
        print("Lowercase:", to_lower(s))

    elif choice == 5:
        s = input("Enter string: ")
        print("Uppercase:", to_upper(s))

    elif choice == 6:
        s = input("Enter string: ")
        ch = input("Enter character to find: ")
        pos = find_char(s, ch)
        if pos != -1:
            print("Character found at position:", pos)
        else:
            print("Character not found")

    elif choice == 7:
        s = input("Enter string: ")
        sub = input("Enter substring: ")
        pos = find_substring(s, sub)
        if pos != -1:
            print("Substring found at position:", pos)
        else:
            print("Substring not found")

    elif choice == 8:
        s = input("Enter string: ")
        print("Reversed String:", reverse_string(s))

    elif choice == 9:
        print("Exiting program...")
        break

    else:
        print("Invalid choice!")
