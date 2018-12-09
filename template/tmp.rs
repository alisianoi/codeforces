use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("Failed to read from stdin");

    print!("{}", line);

    // let x: i32 = line.trim().parse().expect("Failed to parse i32");
    // let xs: Vec<i32> = line.split(" ").map(|x| x.parse().expect("Failed to parse i32")).collect();

    // println!("{}", x);
}
