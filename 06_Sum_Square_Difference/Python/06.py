sumOfSquares = 0
squareOfSum = 0

for i in range(101):
    sumOfSquares += i * i
    squareOfSum += i

squareOfSum *= squareOfSum

print(abs(sumOfSquares - squareOfSum))