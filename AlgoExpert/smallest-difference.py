def smallestDiff(a1, a2):
    a1.sort()
    a2.sort()
    smallest = float("inf")
    curr = float("inf")

    i = 0
    j = 0
    smallestPair = []

    while i < len(a1) and j < len(a2):
        num1 = a1[i]
        num2 = a2[j]
        if num1 < num2:
            curr = num2 - num1
            i += 1
        elif num2 < num1:
            curr = num1 - num2
            j += 1
        else:
            return [num1, num2]
        if smallest > curr:
            smallest = curr
            smallestPair = [num1, num2]
    return smallestPair
