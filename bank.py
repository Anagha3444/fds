def deposit(balance, amount):
    return balance + amount

def withdraw(balance, amount):
    if balance >= amount:
        return balance - amount
    else:
        print("Insufficient funds for withdrawal!")
        return balance

def process_transactions():
    balance = 0
    while True:
        transaction = input("Enter transaction (D for deposit, W for withdrawal) or 'done' to finish: ")
        if transaction.lower() == 'done':
            break
        type, amount = transaction.split()
        amount = int(amount)
        if type == 'D':
            balance = deposit(balance, amount)
        elif type == 'W':
            balance = withdraw(balance, amount)
        else:
            print("Invalid transaction type. Please enter 'D' for deposit or 'W' for withdrawal.")
    return balance

net_balance = process_transactions()
print("Net amount in the account:", net_balance)
