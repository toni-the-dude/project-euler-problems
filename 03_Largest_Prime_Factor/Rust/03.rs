fn sieve_of_eratosthenes(sqrt_limit: usize) -> Vec<bool> {

    let mut sieve = vec![true; sqrt_limit + 1];
    sieve[0] = false;
    sieve[1] = false;

    for number in 2..=sqrt_limit {

        if sieve[number] == false {
            continue;
        }

        for factor in ((number * number)..=sqrt_limit).step_by(number) {
            sieve[factor] = false;
        }

    }

    sieve

}

fn get_limit(limit: u64) -> usize {

    let mut sqrt_limit: f64 = limit as f64;
    sqrt_limit = sqrt_limit.sqrt();
    sqrt_limit = sqrt_limit.floor();
    let sqrt_limit: usize = sqrt_limit as usize;

    sqrt_limit

}

fn parse_sieve_backwards_for_prime_factors(sieve: Vec<bool>, limit: u64) -> u64 {

    for prime in (2..sieve.len()).rev() {
        if sieve[prime] == true {
            let answer: u64 = prime as u64;
            if limit % answer == 0 {
                return answer;
            }
        }
    }
    
    return 0;

}

fn main() {

    let limit: u64 = 600851475143;
    let adjusted_limit: usize = get_limit(limit);
    let sieve: Vec<bool> = sieve_of_eratosthenes(adjusted_limit);
    let answer = parse_sieve_backwards_for_prime_factors(sieve, limit);
    println!("{}", answer);

}