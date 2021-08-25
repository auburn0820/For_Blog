
class Node<T: Comparable> {
    var value: T?
    var next: Node<T>?
}

extension Node: Equatable {
    static func == (lhs: Node<T>, rhs: Node<T>) -> Bool {
        return lhs.value == rhs.value
    }
}

class LinkedList<T: Comparable> {
    private var head: Node<T>
    private var tail: Node<T>
    private var size: Int = 0
    
    init() {
        head = Node<T>()
        tail = Node<T>()
    }
    
    var isEmpty: Bool {
        return self.size == 0 ? true : false
    }
    
    var count: Int {
        return self.size
    }
    
    func insertNode(_ value: T) {
        let newNode = Node<T>()
        newNode.value = value
        
        if self.head.next == nil && self.tail.next == nil {
            self.head.next = newNode
            self.tail.next = newNode
        } else {
            self.tail.next?.next = newNode
            self.tail.next = newNode
        }
        self.size += 1
    }
    
    func deleteNode(_ value: T) {
        if isEmpty {
            return
        }
        
        var node: Node<T>? = head
        
        while node != nil {
            if let nextNode = node?.next, nextNode.value == value {
                node?.next = nextNode.next
                self.size -= 1
                break
            }
            node = node?.next
        }
    }
    
    func deleteAllNodes() {
        if isEmpty {
            return
        }
        
        self.head.next = nil
        self.tail.next = nil
        self.size = 0
    }
    
    func printAllNodes() {
        if isEmpty {
            return
        }
        
        var node = self.head.next
        
        while true {
            if let node = node {
                print(node.value!, terminator: " ")
            } else {
                break
            }
            node = node?.next
        }
        print()
    }
}
