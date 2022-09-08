const { Console } = require("console")

let A = 2
let B = 4
let C = 8
let D = 9

let exp1 = (!(A > B)) && (A * B == C)
let exp2 = (B < C) && (B > D)
let exp3 = !(A + B < D) && D > C
let exp4 = (D % B > 2)

console.log(exp1)
console.log(exp2)
console.log(exp3)
console.log(exp4)