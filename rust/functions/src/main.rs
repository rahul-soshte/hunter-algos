fn main() {
   let x = plus_one(5);
   println!("The value of x is :{}",x);

}

fn plus_one(x: i32) -> i32 {
	x+1
}

fn another_function(x: i32 ,y: i32 ){
	println!("Printed the parameter x={}",x);
	println!("Printed the parameter y={}",y);
}