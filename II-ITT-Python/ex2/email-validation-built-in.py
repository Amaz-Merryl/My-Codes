import re

def validate_email(email):
    pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'

    if re.fullmatch(pattern, email):
        return True
    return False

test_email = input("Enter an email: ")
if validate_email(test_email):
    print("Valid Email Format!")
else:
    print("Invalid Email Format.")
