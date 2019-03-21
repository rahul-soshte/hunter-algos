fn main() {
    
let s=String::from("hello");
takes_ownership(s);
let x=5;
makes_copy(x);
println!("{}",s);
}

fn makes_copy(some_integer: i32){
	println!("{}",some_integer );
}

fn takes_ownership(some_string:String){
	println!("{}",some_string);
}
