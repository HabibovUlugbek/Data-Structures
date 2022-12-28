class Queue {
  constructor(length) {
    this.queue = [];
    this.length = length;
  }

  enqueue(item) {
    if (this.isFull()) return;
    this.queue.push(item);
  }

  dequeue() {
    if (this.isEmpty()) return;
    return this.queue.shift();
  }

  isEmpty() {
    return this.queue.length === 0;
  }

  isFull() {
    return this.queue.length === this.length;
  }

  count = () => this.queue.length;

  changeLength = (length) => {
    this.length = length;
  };

  print() {
    console.log(this.queue);
  }
}
