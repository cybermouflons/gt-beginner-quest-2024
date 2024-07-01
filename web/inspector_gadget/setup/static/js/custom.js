
// Custom javascript code
function add(a, b) {
    return a + b;
}

function subtract(a, b) {
    return a - b;
}

function multiply(a, b) {
    return a * b;
}

function divide(a, b) {
    if (b === 0) {
        throw new Error("Division by zero");
    }
    return a / b;
}

function factorial(n) {
    if (n < 0) return -1;
    if (n === 0) return 1;
    return n * factorial(n - 1);
}

function isEven(num) {
    return num % 2 === 0;
}

function isOdd(num) {
    return num % 2 !== 0;
}

function findMax(arr) {
    return Math.max(...arr);
}

function findMin(arr) {
    return Math.min(...arr);
}

function sumArray(arr) {
    return arr.reduce((acc, val) => acc + val, 0);
}

function reverseString(str) {
    return str.split('').reverse().join('');
}

function toUpperCase(str) {
    return str.toUpperCase();
}

function toLowerCase(str) {
    return str.toLowerCase();
}

function random(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

// Flag Part 2: 3st1g4t3_th3_cl13nt_