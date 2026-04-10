para = input("Enter a paragraph: ")

words = para.lower().split()

counts = {}
for w in words:
    counts[w] = len(w)

print("\nWord Counts:")
for w in counts:
    if counts[w] != 1:
       print(w, ":", counts[w])

top_word = max(counts, key=counts.get)
print("\nHighest count word:", top_word)

reversed_word = top_word[::-1]
print("Reversed word:", reversed_word)
