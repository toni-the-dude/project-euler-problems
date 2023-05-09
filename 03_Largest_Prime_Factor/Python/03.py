import math

def sieve_of_eratosthenes(limit):

    sqrt_limit = limit ** 0.5
    sqrt_limit = math.floor(sqrt_limit)
    sieve = [True] * sqrt_limit
    sieve[0] = False
    sieve[1] = False

    for number in range(2, sqrt_limit):
        if sieve[number] is False: continue
        for factor in range(number * number, sqrt_limit, number):
            sieve[factor] = False

    return sieve

limit = 600851475143

sieve = sieve_of_eratosthenes(limit)

index = limit ** 0.5
index = math.floor(index) - 1

while True:
    if sieve[index] is True: 
        if limit % index == 0:
            print(index)
            break
        if index == 0:
            print("Nothing found.")
            break
    index -= 1