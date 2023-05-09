# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
# The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.

# Sums multiples of 3 and 5
def mult_of_3_or_5_sum(n):
    # All numbers that are < n
    sum = 0
    for i in range(2, n):
        if not i % 3 or not i % 5:
            # print(i)
            sum += i
    return sum

print(mult_of_3_or_5_sum(1000))
