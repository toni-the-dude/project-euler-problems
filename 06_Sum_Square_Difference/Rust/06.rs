fn sum_of_many(limit: i32) -> i32 {
    let mut sum_of_squares = 0;
    let mut square_of_sum = 0;

    for num in 1..=limit {
        sum_of_squares += num * num;
        square_of_sum += num;
    }
    println!("{sum_of_squares}");
    println!("{square_of_sum}");
    let result = (sum_of_squares - square_of_sum * square_of_sum).abs();
    return result;
}

fn main() {
    println!("{}", sum_of_many(100));
}