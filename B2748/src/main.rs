use std::io;

fn main() {
    let mut n = String::new();
    match io::stdin().read_line(&mut n) {
        Ok(_) => {}
        Err(_) => {}
    }

    let n: i32 = match n.trim().parse() {
        Ok(n) => n,
        Err(_) => 0,
    };

    println!("{}", fibonacci(n));
}

fn fibonacci(n: i32) -> i32 {
    if n < 2 {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
