function getNthPrime(n) {

    function primes_filter(m) {
        let primes = Array(m+1).fill(true);
        primes[0] = primes[1] = false;
        for (let i = 2; i <= Math.sqrt(m); i++)
            if (primes[i])
                for (let j=i*i; j<=m; j+=i)
                    primes[j] = false;
        return primes.reduce((a, b) => a + b, 0);
    }

    x = 1;
    while (primes_filter(x) < n) {
        x++;
    }

    return x;
}
