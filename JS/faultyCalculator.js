/*
    Faulty Calculator only performs wrong operations 50% of the time.
*/


// function RightCalculator(a, b, operator){
//     switch(operator){
//         case "+":
//             return a + b;
//         case "-":
//             return a - b;
//         case "*":
//             return a * b;
//         case "/":
//             return a / b;
//         case "**":
//             return a ** b;
//         default:
//             return "Invalid Operator!";
//             break;
//     }
// }

// function FaultyCalculator(a, b, operator) {
//     switch(operator){
//         case "+":
//             return a - b;
//         case "-":
//             return a / b;
//         case "*":
//             return a + b;
//         case "/":
//             return a ** b;
//         case "**":
//             return a * b;
//         default:
//             return "Invalid Operator!";
//             break;
//     }
// }

// let n1 = Number(prompt("Enter first number: "));
// let n2 = Number(prompt("Enter second number: "));
// let op = prompt("Enter operator: ");

// let randomPercentage = Math.random() * 100;
// console.log(randomPercentage);
// if(randomPercentage <= 50){
//     console.log("Output: ", FaultyCalculator(n1, n2, op));
// }else{
//     console.log("Output: ", RightCalculator(n1, n2, op));
// }


let n1 = Number(prompt("Enter first number: "));
let op = prompt("Enter operator: ");
let n2 = Number(prompt("Enter second number: "));

let obj = {
    "+" : "-",
    "-" : "/",
    "*" : "+",
    "/" : "**",
    "**" : "*"
};


let random = Math.random() * 100;
console.log(random);
if(random <= 50){
    op = obj[op]; // turns the operator faulty
}

alert(`The Result is: ${eval(`${n1} ${op} ${n2}`)}`) // Do not use eval in production sites