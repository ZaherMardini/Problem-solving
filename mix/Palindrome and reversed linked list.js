class Node{
  constructor(value){
    this.value = value;
    this.next = null;
  }
}

class LinkedList{
  constructor(){
    this.head = null;
    this.next = null;
    this.size = 0;
  }
  isEmpty(){
    return this.size === 0;
  }
  append(value){
    let n = new Node(value);
    if(this.isEmpty()){
      this.head = n;
    }else{
      n.next = this.head;
      this.head = n;
    }
    this.size++;
  }
  print(node = this.head){
    if(this.isEmpty()){
      return false;
    }
    let result = '';
    let current = node;
    while(current){
      result+=current.value;
      current = current.next;
    }
    return result;
  }
}
function reverse(node){
  let current = node; 
  let prev = null;
  let next;
    while(current){
      next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }  
    return prev;
}

function isPalindrome(head){
  let current = head;
  let fast = current;
  let mid = current;
  let first = current;
  let len = 0;
  while(fast && fast.next){
    fast = fast.next.next;
    mid = mid.next;
    len++;
  }
  let m = reverse(mid);
  while(len > 0){
    len--;
    if(first.value !== m.value){
      return false;
    }
    first = first.next;
    m = m.next;
  }
  return true;
}


let l = new LinkedList();
l.append(`2`);
l.append(`1`);
l.print();
console.log(l.print());