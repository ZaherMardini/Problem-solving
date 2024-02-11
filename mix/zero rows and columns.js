console.time('time');
let arr1=[
  [1, 1],
  [1, 1]
];

let arr2=[
  [-1,-1],
  [10, 9]
];

let arr3 = Array.from(arr2);  
let cCount = arr1[0].length;
let rCount = arr1.length
let zeros = 0;
let zrows = 0;
let zcol = 0;
let zc = 0;
let current = 0;


function countZeroRowsAndColumns(arr1,arr2){
  let arr3 = Array.from(arr2);  
  let cCount = arr1[0].length;
  let rCount = arr1.length
  let zeros = 0;
  let zrows = 0;
  let zcol = 0;
  let zc = 0;
  let current = 0;
  
  for(let i = 0; i < rCount; i++){ // iterate by row number
    for(let j = 0; j < cCount; j++){ // iterate by column number
      arr3[i][j] = arr1[i][j] + arr2[i][j]; // create rows and handling zeros count
      if(arr3[i][j] === 0){
        zeros++;
      }
      if(i === rCount - 1 && arr3[i][j] === 0){ // this means we reached the final row
        current = i;
        while(current >= 0 && arr3[current][j] === 0){
            zc++;
            current--;
        }
        if(zc === rCount){
          zcol++;
          zc = 0;
        }else{
          zc = 0;
        }
      }
    }
    if(zeros === cCount){ // calculate zero rows
      zeros = 0;
      zrows++;
    }else{
      zeros = 0;
    }
  }
  return zcol + zrows;
}

console.log(arr3, `zero rows:${zrows}`, `zero columns:${zcol}`, `total:${zcol + zrows}`);
console.timeEnd('time');