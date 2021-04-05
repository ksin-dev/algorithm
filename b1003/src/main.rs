use std::io;

static mut V: Vec<(i64, i64)> = Vec::new();

fn main() {
    let mut c = String::new();

    match io::stdin().read_line(&mut c) {
        Ok(_) => {}
        Err(_) => {}
    }
    let mut c: u64 = c.trim().parse().expect("error");

    while c > 0 {
        let mut n = String::new();
        match io::stdin().read_line(&mut n) {
            Ok(_) => {}
            Err(_) => {}
        }

        let n: u64 = n.trim().parse().expect("error");
        //        unsafe {
        //            V = Vec::with_capacity((n + 1) as usize);
        //            V.resize((n + 1) as usize, (-1 as i64, -1 as i64));
        //            let res = fibonacci(n);
        //            println!("{} {}", res.0, res.1);
        //        }
        let res = bottom_up_fibonacci(n);

        println!("{} {}", res.0, res.1);

        c -= 1;
    }
    //println!("{}", bottom_up_fibonacci_COUNT(n));
}

unsafe fn top_down_fibonacci(n: u64) -> (i64, i64) {
    let un = n as usize;

    if V[un].0 != -1 {
        return V[un];
    }
    V[un] = (0, 0);

    if n == 0 {
        V[un].0 += 1;
        return V[un];
    }
    if n == 1 {
        V[un].1 += 1;
        return V[un];
    }

    let prev2_fibo = top_down_fibonacci(n - 2);
    let prev1_fibo = top_down_fibonacci(n - 1);
    V[un] = (prev2_fibo.0 + prev1_fibo.0, prev1_fibo.1 + prev2_fibo.1);

    return V[un];
}

fn bottom_up_fibonacci(n: u64) -> (u64, u64) {
    if n == 0 {
        return (1, 0);
    } else if n == 1 {
        return (0, 1);
    }

    let mut f_prev_2 = (1, 0);
    let mut f_prev_1 = (0, 1);
    for _i in 0..(n - 1) as usize {
        let tmp = f_prev_1;

        f_prev_1 = (f_prev_1.0 + f_prev_2.0, f_prev_1.1 + f_prev_2.1);
        f_prev_2 = tmp;
    }
    return f_prev_1;
}
