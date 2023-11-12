let names = ["zaher","tama","bobo", "botros","d","d"];

function likes(names) {
if(!names.length){
  console.log(`No one likes this`);
}
  else if(names.length < 3){
    console.log(names.join(" and ") + `${names.length === 1 ? " likes this" : " like this"}`);
  }
  else if(names.length >= 3){
    console.log(names.slice(0,2).join(", ") +
    ` and ${names.length-2 > 1 ? `${names.length-2} others like this`: `${names[2]} like this`}`)
  }
}
likes(names);