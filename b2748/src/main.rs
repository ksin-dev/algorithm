use std::io;

//static mut v: Vec<i64> = Vec::new();
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

    //    unsafe {
    //        for i in 0..n + 1 as u64 {
    //            v.push(-1);
    //        }
    //
    //        println!("{}", top_down_fibonacci(n));
    //    }
    //
    println!("{}", bottom_up_fibonacci(n));
}

//unsafe fn top_down_fibonacci(n: u64) -> u64 {
//    let n_size: usize = n as usize;
//    if v[n_size] != -1 {
//        return v[n_size] as u64;
//    }
//    if n < 2 {
//        return n as u64;
//    }
//
//    v[n_size] = (top_down_fibonacci(n - 1) + top_down_fibonacci(n - 2)) as i64;
//
//    return v[n_size] as u64;
//}

fn bottom_up_fibonacci(n: u64) -> u64 {
    if n == 0 {
        return 0;
    } else if n == 1 {
        return 1;
    }

    let mut f_prev_2: u64 = 0;
    let mut f_prev_1: u64 = 0;
    let mut f: u64 = 1;
    for _i in 0..(n - 1) as usize {
        let tmp = f;

        f = f_prev_1 + tmp;
        f_prev_2 = f_prev_1;
        f_prev_1 = tmp;
    }
    return f as u64;
}
