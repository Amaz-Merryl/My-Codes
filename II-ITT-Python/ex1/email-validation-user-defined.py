def is_valid_email(email):

    if email.count("@") != 1:
        return False

    user_part, domain_part = email.split("@")

    if len(user_part) == 0 or len(domain_part) == 0:
        return False

    if "." not in domain_part or domain_part.startswith(".") or domain_part.endswith("."):
        return False

    if " " in email:
        return False

    allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._+-"
    for char in user_part:
        if char not in allowed_chars:
            return False

    return True

email_input = input("Enter email to check: ")
if is_valid_email(email_input):
    print("Valid Email..! ")
else:
    print("Invalid email format. ")
