use std::io;

static mut v: Vec<i64> = Vec::new();
fn main() {
    let mut n = String::new();
    match io::stdin().read_line(&mut n) {
        Ok(_) => {}
        Err(_) => {}
    }

    let n: u64 = match n.trim().parse() {
        Ok(n) => n,
        Err(_) => 0,
    };

    unsafe {
        for i in 0..n + 1 as u64 {
            v.push(-1);
        }

        println!("{}", fibonacci(n));
    }
}

unsafe fn fibonacci(n: u64) -> u64 {
    let n_size: usize = n as usize;
    if v[n_size] != -1 {
        return v[n_size] as u64;
    }
    if n < 2 {
        return n as u64;
    }

    v[n_size] = (fibonacci(n - 1) + fibonacci(n - 2)) as i64;

    return v[n_size] as u64;
}
