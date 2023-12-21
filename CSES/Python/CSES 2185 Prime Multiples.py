n, k = map(int, input().split())
primes = [int(i) for i in input().split()]
total = 0
    
for subset in range(1, 1 << k):
    print(bin(subset))
    subset_product = 1
    num_primes = 0

    for i in range(k):
        if subset & (1 << i):
            subset_product *= primes[i]
            num_primes += 1
    print(subset_product, num_primes)

    if num_primes % 2:
        total += n // subset_product
    else:
        total -= n // subset_product

print(total)