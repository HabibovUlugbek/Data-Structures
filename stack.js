class Stack {
  constructor(length) {
    this.data = [];
    this.length = length;
  }

  push(item) {
    if (this.isFull()) return;
    this.data.push(item);
  }

  pop() {
    if (this.isEmpty()) return;
    return this.data.pop();
  }

  peek(position) {
    if (this.isEmpty()) return;
    return this.data[this.data.length + 1 - position];
  }

  count = () => this.data.length;

  change = (position, item) => {
    if (this.isEmpty()) return;
    this.data[position] = item;
  };

  changeLength = (length) => {
    this.length = length;
  };

  isEmpty() {
    return this.data.length === 0;
  }

  isFull() {
    return this.data.length === this.length;
  }

  print() {
    console.log(this.data);
  }
}
