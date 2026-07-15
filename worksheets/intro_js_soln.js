// 1. Arrow function that takes two integers and returns their difference
const difference = (a, b) => a - b;

// Call the function on two integers of your choice
const num1 = 15;
const num2 = 7;
const diffResult = difference(num1, num2);
console.log(`${num1} minus ${num2} equals ${diffResult}`);

// 2. Create two variables with random integers between 0 and 100
let random1 = Math.floor(Math.random() * 101);
let random2 = Math.floor(Math.random() * 101);
console.log(`Random numbers: ${random1} and ${random2}`);

// 3. Use the difference function to tell which is bigger
if (difference(random1, random2) > 0) {
    console.log(`${random1} is bigger than ${random2}`);
} else if (difference(random1, random2) < 0) {
    console.log(`${random2} is bigger than ${random1}`);
} else {
    console.log(`${random1} equals ${random2}`);
}

// 4. Modify the arrow function to return an object with the two integers and their difference
const differenceObject = (a, b) => {
    return {
        num1: a,
        num2: b,
        diff: a - b
    };
};

// 5. Create a new function that takes a function as an argument
function createRandomAndApply(fn) {
    const rand1 = Math.floor(Math.random() * 101);
    const rand2 = Math.floor(Math.random() * 101);
    return fn(rand1, rand2);
}

// 6. Call the new function passing in the difference function
const result = createRandomAndApply(differenceObject);

// Print out the result using object destructuring
const { num1: n1, num2: n2, diff: d } = result;
console.log(`${n1} minus ${n2} equals ${d}`);

// 7. Challenge: Create an array of 5 strings in lowercase. Loop through the array and print each string in uppercase.
const strings = ["a", "b", "c", "d", "e"];
strings.forEach(s => console.log(s.toUpperCase()));
