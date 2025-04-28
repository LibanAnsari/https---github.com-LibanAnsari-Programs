console.log("Hello World!")
console.log("Code is running...")
console.log("Code is also running...")
console.log("Code running like a wow...")

// let n = 5;
var n = prompt("Enter your number: ")

console.log("Your number is: " + n)

var isTrue = confirm("Are you sure you want to leave this page and blast your computer ")

if(isTrue){
    console.log("Your computer is Blasting...")
}else{
    console.log("You saved your computer")
}

document.title = "javaSCRIPT"

document.addEventListener("DOMContentLoaded", function() {
    document.body.style.backgroundColor = "pink";
});

let a = "ABC"; // string
let b = 12; // number
let c = 3.55; // number
const x = true; // boolean
let y = undefined; // undefined
let z = null; // object

console.log(a, b, c, x, y, z)
console.log(typeof a, typeof b, typeof c, typeof x, typeof y, typeof z)

let o = {
    "name" : "Liban",
    "enroll no" : 15
}

console.log(o)
o.gpa = 9.15;
console.log(o)